# Automated Firmware Flashing Implementation

This document describes the technical implementation of the `zmk-flash` script for automated firmware flashing.

## Overview

The `zmk-flash` script automates the process of flashing ZMK firmware to keyboard halves by:
- Detecting when bootloader devices are connected
- Mounting them without requiring sudo
- Copying and verifying firmware
- Safely unmounting and cleaning up

## Architecture

### Script Location

`zmk/.local/bin/zmk-flash`

This location is in `$PATH` when the zmk tool is stowed, making the command available system-wide.

### Key Design Decisions

#### 1. Using udisksctl Instead of sudo mount

**Why udisksctl?**
- No sudo required - uses PolicyKit for authorization
- Automatically determines mount point
- Handles filesystem detection
- Safer unmounting with proper cleanup
- Standard on modern Linux systems

**How it works:**
```bash
# Mount returns output like: "Mounted /dev/sda at /run/media/peter/NICENANO"
mount_output=$(udisksctl mount --block-device /dev/sda --no-user-interaction 2>&1)

# Extract mount point from output
mount_point=$(echo "$mount_output" | grep -oP 'at \K.*' | tr -d '\n')
```

**Fallback:**
If udisksctl is not available, users can use the manual method with `sudo mount`.

#### 2. Device Detection: udevadm monitor

**Why udevadm monitor over polling?**
- Instant detection when device appears (no polling delay)
- No race conditions
- More efficient (event-driven vs. polling)
- Built into systemd (always available)
- Can filter for specific device types

**Implementation:**
```bash
# Watch for block device add events, filter for sda, timeout after 60s
timeout 60s udevadm monitor --udev --subsystem-match=block | \
    grep --line-buffered "add.*sda" | \
    head -n1
```

**Why this works:**
- `udevadm monitor` streams device events in real-time
- `--subsystem-match=block` filters for block devices only
- `grep --line-buffered` ensures immediate output
- `head -n1` exits after first match
- `timeout` prevents infinite waiting

**Alternative considered:**
Polling `/dev/sda` existence every 0.5 seconds was simpler but less robust and wastes CPU cycles.

#### 3. Device Removal Detection: Polling

**Why polling for removal?**
- Simpler than monitoring for remove events
- Removal is less time-critical than detection
- Shorter timeout (30s) makes polling acceptable

**Implementation:**
```bash
while [ -e "$DEVICE" ] && [ $timeout -gt 0 ]; do
    sleep 0.5
    ((timeout--))
done
```

## Safety Features

### 1. Pre-flight Checks

Before starting, verify:
- `udisksctl` is available
- `udevadm` is available
- Firmware files exist at expected paths
- Device is not already connected (prevents confusion)

### 2. UF2 Bootloader Verification

After mounting, verify the device is a UF2 bootloader:

```bash
if [ ! -f "$mount_point/INFO_UF2.TXT" ]; then
    echo "Error: Not a UF2 bootloader device"
    udisksctl unmount --block-device "$DEVICE"
    exit 1
fi
```

**Why this matters:**
- Prevents flashing to wrong device
- UF2 bootloaders always have `INFO_UF2.TXT`
- Catches cases where wrong USB device is mounted as `/dev/sda`

### 3. Copy Verification

After copying firmware, verify success:

```bash
source_size=$(stat -c%s "$firmware_path")
dest_size=$(stat -c%s "$mount_point/firmware.uf2")

if [ "$source_size" != "$dest_size" ] || [ "$source_size" = "0" ]; then
    echo "Error: Firmware copy verification failed"
    exit 1
fi
```

**Why file size check?**
- Simple and reliable
- Catches incomplete copies
- Catches permission issues
- No need for checksums (UF2 has built-in validation)

### 4. Sync Before Unmount

```bash
sync
```

Ensures all writes are flushed to device before unmounting. Critical for preventing corruption.

### 5. Graceful Error Handling

Every operation that can fail has error handling:
- Device detection timeout
- Mount failures
- Copy failures
- Verification failures
- Unmount failures (with warning, not error, since device may auto-eject)

## Workflow Details

### Flashing Both Halves

```
1. Pre-flight checks
2. Display firmware paths
3. Flash left half:
   a. Wait for device (udevadm monitor)
   b. Mount with udisksctl
   c. Verify UF2 bootloader
   d. Copy firmware
   e. Verify copy
   f. Sync
   g. Unmount
4. Wait for device removal (polling)
5. Flash right half:
   a-g. Same as left half
6. Display success message
```

### Flashing Single Half

Same as above but skips the other half and device removal wait.

## Error Scenarios and Handling

### Device Not Detected (Timeout)

**Cause:** User didn't enter bootloader mode, USB issue, wrong device

**Handling:**
- Timeout after 60 seconds
- Display helpful error message
- Suggest checking bootloader mode and USB connection
- Exit with error code

### Mount Failure

**Cause:** Device not ready, permission issue, udisksctl not available

**Handling:**
- Display mount error output
- Exit with error code
- User can try manual method

### Not a UF2 Bootloader

**Cause:** Wrong device mounted, not in bootloader mode

**Handling:**
- Check for `INFO_UF2.TXT`
- Unmount device
- Display error message
- Exit with error code

### Copy Failure

**Cause:** No space, permission issue, device disconnected

**Handling:**
- Check copy operation return code
- Verify file sizes match
- Unmount device
- Display error message
- Exit with error code

### Unmount Failure

**Cause:** Device auto-ejected (normal for some bootloaders)

**Handling:**
- Display warning, not error
- Continue execution
- Device will be gone anyway

## Device Assumptions

### Hardcoded for Single Keyboard

The script assumes:
- Only one keyboard being flashed
- Bootloader appears as `/dev/sda`
- No other USB storage devices connected during flashing

**Why hardcoded?**
- User has only one keyboard
- Simplifies implementation
- Reduces chance of flashing wrong device
- Can be enhanced later if needed

### Future Enhancements

Possible improvements:
1. **Auto-detect device:** Use `lsblk` to find UF2 bootloader instead of assuming `/dev/sda`
2. **Detect which half:** Parse `INFO_UF2.TXT` to determine if left or right half
3. **Support multiple keyboards:** Allow specifying device path
4. **Progress indicator:** Show copy progress for large firmware files
5. **Verify firmware signature:** Check ZMK firmware metadata

## Dependencies

### Required

- `bash` - Shell interpreter
- `udisksctl` - From udisks2 package, for mounting without sudo
- `udevadm` - From systemd, for device detection
- `grep` - For parsing output
- `stat` - For file size verification
- `timeout` - For limiting wait times
- `sync` - For flushing writes

### Optional

None - script fails gracefully if dependencies missing

## Testing Considerations

### Manual Testing

To test the script:

1. **Build firmware first:**
   ```bash
   zmk-build
   ```

2. **Test single half:**
   ```bash
   zmk-flash left
   ```

3. **Test both halves:**
   ```bash
   zmk-flash both
   ```

4. **Test error conditions:**
   - Run without firmware built (should error)
   - Run with device already connected (should warn)
   - Timeout test: run without plugging in device

### Edge Cases

- Device already connected when script starts
- Device disconnected during copy
- Multiple USB storage devices connected
- Insufficient space on bootloader device
- Corrupted firmware file
- udisksctl not installed

## Performance

### Timing

Typical execution time for both halves:
- Device detection: < 1 second after plugging in
- Mount: < 1 second
- Copy: 1-2 seconds (firmware is ~500KB)
- Unmount: < 1 second
- **Total per half: ~5 seconds** (excluding user interaction time)

### Resource Usage

- Minimal CPU usage (event-driven, not polling for detection)
- No significant memory usage
- No disk I/O except firmware copy

## Comparison to Manual Method

### Manual Method

```bash
sudo mount /dev/sda /mnt/nicenano
sudo cp firmware.uf2 /mnt/nicenano/
sudo umount /mnt/nicenano
```

**Drawbacks:**
- Requires sudo (password prompt)
- Manual typing while using backup keyboard
- Easy to forget which half
- No verification
- No error handling

### Automated Method

```bash
zmk-flash
```

**Benefits:**
- No sudo required
- No typing during flashing
- Clear prompts for which half
- Automatic verification
- Comprehensive error handling
- Consistent and repeatable

## Integration with Build Process

### Separate Commands (Current)

```bash
zmk-build && zmk-flash
```

**Why separate?**
- Composable - can build without flashing
- Can flash previously built firmware
- Follows Unix philosophy (do one thing well)
- User has control over when to flash

### Combined Command (Not Implemented)

Could create `zmk-build-and-flash` but decided against it:
- Less flexible
- Can't flash without rebuilding
- Harder to debug build vs. flash issues
- User can easily combine with `&&`

## See Also

- [Flashing Firmware Workflow](../workflow/flashing-firmware.md) - User guide
- [Building Firmware](./building-firmware.md) - Build process documentation
- `zmk-build` script - Firmware build automation
