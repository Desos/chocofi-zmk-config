# ZMK Firmware Development

ZMK firmware development environment for building custom keyboard firmware using both GitHub Actions and local Podman containers.

## Quick Start

### First Time Setup

1. **Initialize Zephyr workspace** (inside container, only needed once):
```bash
zmk-shell
cd app/
west init -l app/
west update
exit
```

2. **Build firmware for Chocofi**:
```bash
zmk-build
```

### Daily Workflow

1. **Edit your keymap:**
```bash
hx config/chocofi.keymap
```

2. **Build and flash:**
```bash
zmk-build && zmk-flash
```

That's it! The scripts handle everything automatically.

### Build Firmware

**Option 1: Local Build (Recommended)**
```bash
zmk-build [left|right|both]  # Default: both
```

**Option 2: GitHub Actions**
```bash
git add config/chocofi.keymap
git commit -m "feat: update keymap"
git push origin main
# Wait for GitHub Actions to build
# Download .uf2 files from GitHub releases
```

### Flash to Keyboard

**Automated (Recommended):**
```bash
zmk-flash [left|right|both]  # Default: both
```

The script will:
- Prompt you to plug in each keyboard half in bootloader mode
- Automatically detect, mount, copy firmware, and unmount
- Verify successful flashing
- Guide you through the entire process

**Manual:**
1. Put keyboard half into bootloader mode (double-tap reset)
2. Mount: `udisksctl mount --block-device /dev/sda`
3. Copy `.uf2` file to mounted drive
4. Unmount: `udisksctl unmount --block-device /dev/sda`
5. Repeat for other half

## Structure

- `config/` - Your Chocofi keymap and configuration
- `Source/zmk/` - Upstream ZMK firmware (submodule)
- `.local/bin/` - Helper scripts (stowed to ~/.local/bin/)
- `docs/` - Documentation
- `.github/workflows/` - GitHub Actions for automated builds

## Helper Scripts

### zmk-build

Build firmware locally using Podman container.

**Usage:**
```bash
zmk-build [left|right|both]  # Default: both
```

**Examples:**
```bash
zmk-build          # Build both halves
zmk-build both     # Build both halves
zmk-build left     # Build left half only
zmk-build right    # Build right half only
```

**Output:**
- Left: `Source/zmk/app/build/left/zephyr/zmk.uf2`
- Right: `Source/zmk/app/build/right/zephyr/zmk.uf2`

### zmk-flash

Flash firmware to keyboard halves automatically.

**Usage:**
```bash
zmk-flash [left|right|both]  # Default: both
```

**Examples:**
```bash
zmk-flash          # Flash both halves (automated)
zmk-flash both     # Flash both halves
zmk-flash left     # Flash left half only
zmk-flash right    # Flash right half only
```

**Features:**
- No sudo required (uses udisksctl)
- Automatic device detection
- Verifies UF2 bootloader
- Confirms successful copy
- Clear prompts for which half to plug in

**See:** `docs/workflow/flashing-firmware.md` for detailed guide

### zmk-shell

Enter container shell for manual operations.

**Usage:**
```bash
zmk-shell
```

**Use cases:**
- First-time setup (`west init`, `west update`)
- Manual builds with custom flags
- Debugging build issues

## Documentation

See `docs/` for detailed documentation:
- `reference/` - Official ZMK documentation
- `implementation/` - Our setup choices and reasoning
- `workflow/` - Step-by-step procedures

## Hardware Configuration

- **Keyboard:** Chocofi (36-key split)
- **Board:** Nice Nano v2
- **Shield:** Corne (electrically compatible)
- **Display:** Nice View (optional)
- **Switches:** Choc v1 low profile

## Notes

- Chocofi uses the Corne shield definition in ZMK (this is correct)
- The shield name stays as `corne_left`/`corne_right`
- Physical differences (switches, case) don't affect firmware

## References

- [ZMK Documentation](https://zmk.dev/)
- [Planning Documents](../planning/zmk-setup/)
- [Upstream ZMK](https://github.com/zmkfirmware/zmk)
