# Working Keymap Configuration - Session Documentation

## Overview
This documents the working keymap configuration we developed during the session.

## Key Features Implemented

### 1. Custom Behaviors

#### `lt_hp` - Hold-Preferred Layer-Tap
- **Purpose**: Layer access keys that activate immediately when another key is pressed
- **Settings**:
  - `flavor = "hold-preferred"`
  - `tapping-term-ms = <200>`
  - `quick-tap-ms = <125>`
  - `bindings = <&mo>, <&kp>`
- **Used on**: ESC, RET, TAB, F12 (all thumb layer-tap keys)

#### `sm_ht` - Sticky-Mod Hold-Tap
- **Purpose**: Tap for sticky modifier, hold for regular modifier
- **Settings**:
  - `flavor = "tap-preferred"`
  - `tapping-term-ms = <200>`
  - `quick-tap-ms = <125>`
  - `bindings = <&kp>, <&sk>` (hold=regular mod, tap=sticky mod)
- **Used on**: All modifier keys in LEFT_MODS and RIGHT_MODS layers

#### Mod-Morphs (18 total)
- **RSFT + numbers** → F-keys (1→F1, 2→F2, etc.)
- **RSFT + symbols** → Alternative symbols
  - `/` → `?`
  - `,` → `<`
  - `<` → `>`
  - `(` → `)`
  - `[` → `]`
  - `{` → `}`
  - `=` → `+`
  - `!` → `?`

### 2. Layer Structure (9 Layers)

#### Layer 0: ALPHA (Colemak-DH variant)
```
Q  K  F  P  B        ;  L  U  Y  W
A  R  S  T  SPC      ,  N  E  I  O
Z  X  C  D  V        '  H  M  G  J
   ESC RET  NUM         RSFT TAB F12
   (L2)(L5) (L4)        (sk) (L6)(L3)
```

#### Layer 1: WASD (Gaming)
```
1  2  3  4  5        -  -  -  -  -
LS Q  W  E  R        -  -  -  -  -
LC A  S  D  F        -  -  -  -  -
   TAB Z  SPC           -  L3 L2
```

#### Layer 2: LEFT_NAV
```
LC ←  ↑  →  C-v      -  -  -  -  -
LG BS LS DEL C-c      -  -  -  -  -
HYPER C-z ↓ C-y C-x   -  -  -  -  -
   -  -  -              -  -  -
```
- HYPER = LG+LA+LC+LS (all mods)

#### Layer 3: RIGHT_NAV
```
-  -  -  -  -        VOL+ HOME PGUP END  TG1
-  -  -  -  -        VOL- PREV APP  NEXT MUTE
-  -  -  -  -        PLAY BS   PGDN DEL  PSCRN
   -  -  -              -  -  -
```
- TG1 = Toggle WASD layer
- APP = Context menu (with LSHIFT mod-tap)

#### Layer 4: NUMER (Numbers and Symbols)
```
^  1  2  3  .        !  @  $  #  |
*  4  5  6  -        /  <  (  [  {
+  7  8  9  0        =  &  ~  _  %
   -  -  -              -  S-TAB S-F12
```
- All numbers have RSFT→F-key mod-morphs
- Symbols have RSFT→alternative mod-morphs

#### Layer 5: LEFT_MODS
```
-  -  -  -  -        -  -  -  -  TG1
GUI ALT SFT CTL -    -  -  -  -  -
-  -  -  -  -        -  -  -  -  -
   -  -  -              -  -  -
```
- All mods use `sm_ht` (tap=sticky, hold=regular)

#### Layer 6: RIGHT_MODS
```
-  -  -  -  -        -  -  -  -  TG1
-  -  -  -  -        -  CTL SFT ALT GUI
-  -  -  -  -        -  -  -  -  -
   -  -  -              -  -  -
```
- All mods use `sm_ht` (tap=sticky, hold=regular)

#### Layer 7: MOUSE (Conditional: L2+L3)
```
-  ML MU MR -        -  LC MC RC -
LG LA LS LC -        -  LC LS LA LG
-  -  MD -  -        -  -  -  -  -
   -  -  -              -  -  -
```
- ML/MR/MU/MD = Mouse movement (left/right/up/down)
- LC/MC/RC = Left/Middle/Right click
- Activated by holding ESC + F12 simultaneously

#### Layer 8: SYSTEM (Conditional: L2+L5)
```
BT0 BT1 BT2 BT3 BT4  -  -  -  -  -
RST BOOT UNLK -  -   -  -  -  -  -
-  -  -  -  CLR      -  -  -  -  -
   -  -  -              -  -  -
```
- BT0-4 = Bluetooth profiles
- RST = sys_reset
- BOOT = bootloader
- UNLK = studio_unlock
- CLR = BT_CLR (clear current profile)
- Activated by holding ESC + RET simultaneously

### 3. Conditional Layers

```c
conditional_layers {
    compatible = "zmk,conditional-layers";
    
    // Mouse layer: ESC + F12
    mouse_layer {
        if-layers = <2 3>;  // LEFT_NAV + RIGHT_NAV
        then-layer = <7>;   // MOUSE
    };
    
    // System layer: ESC + RET
    system_layer {
        if-layers = <2 5>;  // LEFT_NAV + LEFT_MODS
        then-layer = <8>;   // SYSTEM
    };
};
```

### 4. Physical Layout

```c
chosen {
    zmk,physical-layout = &foostan_corne_5col_layout;
};
```

## Configuration Files

### corne.conf / chocofi.conf

```ini
# Power Management
CONFIG_ZMK_SLEEP=y
CONFIG_ZMK_IDLE_SLEEP_TIMEOUT=900000  # 15 minutes

# Bluetooth
CONFIG_BT_CTLR_TX_PWR_PLUS_8=y

# Display (Nice View)
CONFIG_ZMK_DISPLAY_BLANK_ON_IDLE=n

# Keyboard Name
CONFIG_ZMK_KEYBOARD_NAME="Chocofi"

# Mouse Emulation
CONFIG_ZMK_MOUSE=y
CONFIG_ZMK_POINTING=y
```

## Build Script Modifications

### zmk-build enhancements:
1. **Automatic cache cleaning** - Detects shield configuration changes
2. **Explicit keymap specification** - Forces use of `chocofi.keymap` for both halves
3. **Nice View shields** - Includes `nice_view_adapter` and `nice_view` in build

## Key Activation Methods

### Layer Access
- **Layer 2 (LEFT_NAV)**: Hold ESC
- **Layer 3 (RIGHT_NAV)**: Hold F12
- **Layer 4 (NUMER)**: Tap or hold number layer key
- **Layer 5 (LEFT_MODS)**: Hold RET
- **Layer 6 (RIGHT_MODS)**: Hold TAB
- **Layer 7 (MOUSE)**: Hold ESC + F12 simultaneously
- **Layer 8 (SYSTEM)**: Hold ESC + RET simultaneously

### Modifier Behavior
- **Tap**: Sticky modifier (stays active for one keypress)
- **Hold**: Regular modifier (active while held)

## Important Notes

1. **Hold-preferred timing**: Layers activate immediately when another key is pressed
2. **No direct mouse layer access**: Removed `&lt_hp 7 RET` from RIGHT_NAV layer
3. **Mouse layer only via conditional**: Must hold ESC + F12 together
4. **Nice View display**: Uses custom status screen (not built-in widgets)
5. **Both halves use same keymap**: Build script explicitly specifies `chocofi.keymap`

## Troubleshooting

### If mouse keys don't work:
- Ensure you're holding BOTH ESC and F12 simultaneously
- Hold them for at least 200ms or press another key while holding

### If layers feel unresponsive:
- Check that you're using `lt_hp` (hold-preferred) not `lt` (tap-preferred)
- Verify `tapping-term-ms` is set to 200ms

### If wrong keymap loads:
- Check build script specifies: `-DKEYMAP_FILE=/workspaces/zmk-config/chocofi.keymap`
- Verify both `corne.conf` and `chocofi.conf` exist and are identical
