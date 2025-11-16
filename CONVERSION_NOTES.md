# QMK to ZMK Keymap Conversion Notes

## Conversion Summary

Successfully converted your QMK keymap from `keymap.c` to ZMK format in `config/chocofi.keymap`.

## Files Modified

1. **`config/chocofi.conf`** - Added `CONFIG_ZMK_MOUSE=y` and `CONFIG_ZMK_POINTING=y` for mouse support
2. **`config/chocofi.keymap`** - Complete rewrite with converted layers and behaviors, includes `<dt-bindings/zmk/mouse.h>` and `<dt-bindings/zmk/pointing.h>`

## Layer Structure (9 layers total)

| Layer | Name | Description |
|-------|------|-------------|
| 0 | ALPHA | Base layer (Colemak-DH variant) |
| 1 | WASD | Gaming layer |
| 2 | L_NAV | Left-hand navigation |
| 3 | R_NAV | Right-hand navigation/media |
| 4 | NUMER | Numbers and symbols |
| 5 | L_MODS | Left-hand modifiers |
| 6 | R_MODS | Right-hand modifiers |
| 7 | MOUSE | Mouse navigation |
| 8 | SYSTEM | Bluetooth and system controls (NEW) |

## Key Conversions

### QMK → ZMK Behavior Mappings

| QMK | ZMK | Notes |
|-----|-----|-------|
| `LT(layer, kc)` | `&lt layer kc` | Layer-tap |
| `OSL(layer)` | `&sl layer` | One-shot layer |
| `OSM(MOD_x)` | `&sk MOD_x` | One-shot modifier |
| `MT(MOD_x, kc)` | `&mt MOD_x kc` | Mod-tap |
| `TG(layer)` | `&tog layer` | Toggle layer |
| `KC_TRNS` | `&trans` | Transparent |
| `LCTL(KC_x)` | `&kp LC(x)` | Control + key |
| `MEH(KC_LGUI)` | `&kp LG(LA(LC(LSHIFT)))` | Meh + GUI |

### Mouse Key Conversions

| QMK | ZMK |
|-----|-----|
| `QK_MOUSE_CURSOR_LEFT` | `&mmv MOVE_LEFT` |
| `QK_MOUSE_CURSOR_UP` | `&mmv MOVE_UP` |
| `QK_MOUSE_CURSOR_RIGHT` | `&mmv MOVE_RIGHT` |
| `QK_MOUSE_CURSOR_DOWN` | `&mmv MOVE_DOWN` |
| `QK_MOUSE_BUTTON_1` | `&mkp LCLK` |
| `QK_MOUSE_BUTTON_2` | `&mkp RCLK` |
| `QK_MOUSE_BUTTON_3` | `&mkp MCLK` |

### Key Override → Mod-Morph Conversions

Created 18 mod-morph behaviors to replicate your RSFT key overrides:

| Behavior | Normal | RSFT + Key |
|----------|--------|------------|
| `&mm_1` - `&mm_0` | 1-0 | F1-F10 |
| `&mm_slsh` | `/` | `\` |
| `&mm_comm` | `,` | `.` |
| `&mm_lt` | `<` | `>` |
| `&mm_lpar` | `(` | `)` |
| `&mm_lbrc` | `{` | `}` |
| `&mm_lbkt` | `[` | `]` |
| `&mm_eq` | `=` | `` ` `` |
| `&mm_excl` | `!` | `?` |

## New Features

### Mouse Layer (Layer 7)

**Activation:** Uses conditional layers - automatically activates when holding both:
- F12 thumb key (right-most, activates layer 3 - RIGHT_NAV)
- TAB thumb key (middle-right, activates layer 6 - RIGHT_MODS)

**How to use:**
1. Hold F12 thumb key (right-most)
2. Hold TAB thumb key (middle-right)
3. Layer 7 automatically activates
4. Use L/U/Y keys for left/middle/right click
5. Use K/F/P keys for mouse movement

### System/BT Layer (Layer 8)

**Activation:** Uses conditional layers - automatically activates when holding both:
- ESC thumb key (left-most, activates layer 2 - LEFT_NAV)
- ENT thumb key (middle-left, activates layer 5 - LEFT_MODS)

**Left hand layout:**
```
Row 1: BT_SEL 0-4  (Select bluetooth profile)
Row 2: &sys_reset, &bootloader, &studio_unlock, [unused], [unused]
Row 3: [unused], [unused], [unused], [unused], &bt BT_CLR
```

**Right hand:** All transparent keys

### ZMK Studio Support

- **Unlock key:** Layer 8 (system layer) → Row 2, Column 3 (left hand)
- **Access:** Hold ESC + ENT thumb keys, then press the S key position
- **Studio URL:** https://zmk.studio/

## Important Notes

### Differences from QMK

1. **Mod-tap on transparent keys:** In layer 5 and 6, used `&mt MOD 0` instead of `&mt MOD &trans` (ZMK doesn't support mod-tap with transparent)

2. **Mouse support:** Requires `CONFIG_ZMK_POINTING=y` in config file (already added)

3. **Conditional layers:** Layer 8 (system) uses conditional_layers feature instead of combos - activates automatically when both layer 2 and layer 5 are active (holding ESC + ENT thumb keys)

### Testing Checklist

Before flashing:
- [ ] Review all layer bindings for accuracy
- [ ] Verify mod-morph behaviors match your expectations
- [ ] Check thumb key positions (especially combo positions 30, 31)
- [ ] Confirm bluetooth controls are accessible
- [ ] Verify studio_unlock is reachable

### Known Limitations

1. **No key position 0 support in mod-tap:** Used literal `0` instead of transparent in mod layers
2. **Conditional layer activation:** 
   - Layer 7 (MOUSE) only activates when BOTH layer 3 and layer 6 are held
   - Layer 8 (SYSTEM) only activates when BOTH layer 2 and layer 5 are held
   - These layers cannot be accessed any other way
3. **Mouse acceleration:** Using default ZMK mouse settings - can be tuned if needed

## Next Steps

1. Review the converted keymap in `config/chocofi.keymap`
2. Test build (don't flash yet): `zmk-build nice_nano_v2 chocofi left`
3. If build succeeds, review any warnings
4. Flash and test on actual hardware
5. Adjust timings/behaviors as needed

## Rollback

If you need to revert:
- Old keymap is preserved in `keymap.c` (QMK format)
- Git can restore previous ZMK keymap if needed
