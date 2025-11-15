# Flashing ZMK Firmware to Chocofi Keyboard

This guide covers how to flash compiled firmware to your Chocofi keyboard halves.

## Quick Start

The automated method is the easiest way to flash firmware:

```bash
# Build and flash in one go
zmk-build && zmk-flash

# Or flash previously built firmware
zmk-flash
```

## Automated Flashing (Recommended)

The `zmk-flash` script automates the entire flashing process, eliminating the need to manually mount/copy/unmount while using a backup keyboard.

### Usage

```bash
zmk-flash [left|right|both]
```

**Examples:**
- `zmk-flash` - Flash both halves (default)
- `zmk-flash both` - Flash both halves
- `zmk-flash left` - Flash left half only
- `zmk-flash right` - Flash right half only

### Workflow

1. **Run the command:**
   ```bash
   zmk-flash
   ```

2. **Flash left half:**
   - Script prompts: "Waiting for LEFT half in bootloader mode..."
   - Double-tap the reset button on the left keyboard half
   - Script automatically detects, mounts, copies firmware, and unmounts
   - Success message appears

3. **Flash right half:**
   - Script prompts: "Unplug the keyboard half..."
   - Unplug the left half
   - Script prompts: "Waiting for RIGHT half in bootloader mode..."
   - Double-tap the reset button on the right keyboard half
   - Script automatically detects, mounts, copies firmware, and unmounts
   - Success message appears

4. **Done!**
   - Both halves are flashed
   - Keyboard is ready to use

### What the Script Does

For each keyboard half:
1. Waits for device to appear (60 second timeout)
2. Mounts the bootloader device using `udisksctl` (no sudo required)
3. Verifies it's a UF2 bootloader by checking for `INFO_UF2.TXT`
4. Copies the firmware file
5. Verifies the copy succeeded (file size check)
6. Unmounts the device
7. Waits for you to unplug before continuing to next half

### Safety Features

- **Pre-flight checks:** Verifies firmware files exist before starting
- **Device verification:** Confirms mounted device is a UF2 bootloader
- **Copy verification:** Checks file sizes match after copying
- **Timeout protection:** Won't wait forever if device doesn't appear
- **Clear prompts:** Always tells you which half to plug in

## Manual Flashing

If the automated script doesn't work or you prefer manual control:

### Prerequisites

- Firmware files built (run `zmk-build` first)
- Mount point exists: `sudo mkdir -p /mnt/nicenano`

### Steps for Each Half

1. **Enter bootloader mode:**
   - Double-tap the reset button on the keyboard half
   - The keyboard should appear as a USB mass storage device

2. **Mount the device:**
   ```bash
   sudo mount /dev/sda /mnt/nicenano
   ```

3. **Copy firmware:**
   ```bash
   # For left half:
   sudo cp ~/Environment/zmk/Source/zmk/app/build/left/zephyr/zmk.uf2 /mnt/nicenano/
   
   # For right half:
   sudo cp ~/Environment/zmk/Source/zmk/app/build/right/zephyr/zmk.uf2 /mnt/nicenano/
   ```

4. **Unmount:**
   ```bash
   sudo umount /mnt/nicenano
   ```

5. **Repeat for other half**

### Alternative: Using udisksctl (No Sudo)

```bash
# Mount (automatically mounts to /run/media/$USER/...)
udisksctl mount --block-device /dev/sda --no-user-interaction

# Copy firmware (adjust mount point as shown in mount output)
cp ~/Environment/zmk/Source/zmk/app/build/left/zephyr/zmk.uf2 /run/media/$USER/NICENANO/

# Unmount
udisksctl unmount --block-device /dev/sda --no-user-interaction
```

## Troubleshooting

### Device Not Detected

**Problem:** Script times out waiting for device

**Solutions:**
- Make sure you're double-tapping the reset button (not single tap)
- Try a different USB cable
- Try a different USB port
- Check `dmesg` output to see if device is recognized by kernel
- Verify `/dev/sda` appears when you plug in the bootloader

### Wrong Device Mounted

**Problem:** Script says "Not a UF2 bootloader device"

**Solutions:**
- Make sure no other USB storage devices are connected
- The nice!nano bootloader should appear as `/dev/sda`
- Check what's mounted: `lsblk` or `mount | grep sda`

### Copy Failed

**Problem:** Firmware copy fails or verification fails

**Solutions:**
- Check available space on bootloader device
- Try manual flashing method
- Verify firmware file exists and is not corrupted
- Check file permissions

### Script Hangs

**Problem:** Script appears stuck

**Solutions:**
- Press Ctrl+C to abort
- Unplug the keyboard half
- Check if device is still mounted: `mount | grep sda`
- Manually unmount if needed: `udisksctl unmount --block-device /dev/sda`
- Try again

### udisksctl Not Found

**Problem:** Script reports "udisksctl not found"

**Solutions:**
- Install udisks2: `sudo dnf install udisks2` (Fedora) or equivalent
- Use manual flashing method with sudo mount
- Or modify script to use sudo mount instead

## Firmware File Locations

After building with `zmk-build`, firmware files are located at:

- **Left half:** `~/Environment/zmk/Source/zmk/app/build/left/zephyr/zmk.uf2`
- **Right half:** `~/Environment/zmk/Source/zmk/app/build/right/zephyr/zmk.uf2`

## Entering Bootloader Mode

The nice!nano v2 has a reset button. To enter bootloader mode:

1. **Double-tap** the reset button quickly
2. The board should appear as a USB mass storage device
3. You should see `/dev/sda` appear (check with `lsblk`)

**Note:** Single tap resets the board, double tap enters bootloader mode.

## Verifying Flash Success

After flashing:

1. The keyboard half will automatically reboot
2. The device will disconnect from USB
3. If you have a display (nice!view), it should show the ZMK logo or your custom display
4. Test the keys to ensure they work

## Complete Build and Flash Workflow

```bash
# 1. Make changes to keymap
vim ~/Environment/zmk/config/chocofi.keymap

# 2. Build firmware
zmk-build

# 3. Flash both halves
zmk-flash

# 4. Test your keyboard!
```

## See Also

- [Building Firmware](../implementation/building-firmware.md) - How the build process works
- [Automated Flashing Implementation](../implementation/automated-flashing.md) - Technical details of zmk-flash script
