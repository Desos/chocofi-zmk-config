# How to Restore the Working Keymap

## Quick Restore

If you need to restore the working keymap we developed during the session:

```bash
cd ~/Environment/zmk/config

# Restore keymap
cp chocofi.keymap.working-session chocofi.keymap

# Restore config files
cp corne.conf.working-session corne.conf
cp chocofi.conf.working-session chocofi.conf

# Rebuild firmware
cd ~/Environment/zmk
zmk-build both

# Flash the new firmware to both halves
```

## Files Saved

The working configuration has been saved to:

1. **Keymap**: `config/chocofi.keymap.working-session`
2. **Config**: `config/corne.conf.working-session`
3. **Config**: `config/chocofi.conf.working-session`
4. **Documentation**: `docs/implementation/session-working-keymap.md`

## What Makes This Configuration Work

### 1. Hold-Preferred Layer-Tap (`lt_hp`)
- Layers activate **immediately** when you press another key
- No more waiting for the tapping-term timeout
- Makes layer access feel responsive

### 2. Sticky-Mod Hold-Tap (`sm_ht`)
- **Tap** = Sticky modifier (one-shot)
- **Hold** = Regular modifier
- Best of both worlds for modifier keys

### 3. Conditional Layers
- **Mouse layer**: Hold ESC + F12 together
- **System layer**: Hold ESC + RET together
- No direct layer-tap conflicts

### 4. Mod-Morphs
- RSFT + numbers → F-keys
- RSFT + symbols → Alternative symbols
- Reduces layer complexity

### 5. Nice View Display
- Custom status screen (not built-in widgets)
- Shows layer, battery, connection status
- No blanking on idle

## Key Differences from Other Versions

### This Working Version Has:
✅ `lt_hp` behavior (hold-preferred)
✅ `sm_ht` behavior (sticky-mod hold-tap)
✅ 18 mod-morph behaviors
✅ Mouse layer via conditional only (no direct access)
✅ Physical layout: `&foostan_corne_5col_layout`
✅ Mouse headers: `mouse.h` and `pointing.h`
✅ 9 layers total

### Other Versions Might Have:
❌ Different behavior names (`sticky_mod`, `lt_hyper`)
❌ HYPER macros
❌ Different layer structure
❌ Direct mouse layer access (`&lt_hp 7 RET`)
❌ Different physical layout selection

## Verification

After restoring, verify the keymap has these key features:

```bash
# Check for hold-preferred behavior
grep "lt_hp:" config/chocofi.keymap

# Check for sticky-mod hold-tap
grep "sm_ht:" config/chocofi.keymap

# Check conditional layers
grep "conditional_layers" config/chocofi.keymap

# Check mouse configuration
grep "CONFIG_ZMK_MOUSE" config/corne.conf

# Check physical layout
grep "zmk,physical-layout" config/chocofi.keymap
```

Expected output:
- `lt_hp: layer_tap_hold_preferred` - Found
- `sm_ht: sticky_mod_hold_tap` - Found
- `conditional_layers` section - Found
- `CONFIG_ZMK_MOUSE=y` - Found
- `zmk,physical-layout = &foostan_corne_5col_layout` - Found

## Troubleshooting

### If the keymap doesn't compile:

1. Check for syntax errors:
   ```bash
   cd ~/Environment/zmk
   zmk-build left 2>&1 | grep -i error
   ```

2. Verify all includes are present:
   ```bash
   head -15 config/chocofi.keymap
   ```
   
   Should show:
   ```c
   #include <behaviors.dtsi>
   #include <behaviors/mouse_keys.dtsi>
   #include <dt-bindings/zmk/bt.h>
   #include <dt-bindings/zmk/keys.h>
   #include <dt-bindings/zmk/mouse.h>
   #include <dt-bindings/zmk/pointing.h>
   ```

3. Check for missing closing braces:
   ```bash
   grep -c "^};" config/chocofi.keymap
   ```
   Should be at least 11 (behaviors + layers + root)

### If mouse keys don't work:

1. Verify mouse config:
   ```bash
   grep -i mouse config/corne.conf
   ```

2. Check conditional layer:
   ```bash
   grep -A 3 "mouse_layer {" config/chocofi.keymap
   ```

3. Ensure you're holding ESC + F12 **simultaneously**

### If modifiers don't work:

1. Check sm_ht behavior exists:
   ```bash
   grep -A 8 "sm_ht:" config/chocofi.keymap
   ```

2. Verify mods layers use sm_ht:
   ```bash
   grep "sm_ht LGUI" config/chocofi.keymap
   ```

## Build Script

The working build script should have:

1. **Automatic cache cleaning**:
   ```bash
   grep "check_build_cache" .local/bin/zmk-build
   ```

2. **Explicit keymap specification**:
   ```bash
   grep "DKEYMAP_FILE" .local/bin/zmk-build
   ```

3. **Nice View shields**:
   ```bash
   grep "nice_view_adapter nice_view" .local/bin/zmk-build
   ```

## Session Summary

This configuration was developed through:
1. Converting QMK keymap to ZMK
2. Fixing 5-column layout issues
3. Adding mouse support
4. Implementing hold-preferred layer-tap
5. Adding sticky-mod hold-tap
6. Removing direct mouse layer access
7. Configuring Nice View displays

All features tested and confirmed working.
