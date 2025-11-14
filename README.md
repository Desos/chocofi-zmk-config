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
zmk-build nice_nano_v2 chocofi left
zmk-build nice_nano_v2 chocofi right
```

### Edit Your Keymap

```bash
hx config/chocofi.keymap
```

### Build Firmware

**Option 1: GitHub Actions (Recommended for daily use)**
```bash
git add config/chocofi.keymap
git commit -m "feat: update keymap"
git push origin main
# Wait for GitHub Actions to build
# Download .uf2 files from GitHub releases
```

**Option 2: Local Build (For testing)**
```bash
zmk-build nice_nano_v2 chocofi left
zmk-build nice_nano_v2 chocofi right
# Output: Source/zmk/app/build/{left,right}/zephyr/zmk.uf2
```

### Flash to Keyboard

1. Put keyboard half into bootloader mode (double-tap reset)
2. Copy `.uf2` file to mounted drive
3. Repeat for other half

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
zmk-build <board> <shield> [left|right]
```

**Examples:**
```bash
zmk-build nice_nano_v2 chocofi left
zmk-build nice_nano_v2 chocofi right
```

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
