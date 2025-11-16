# Chocofi Keymap Layout Documentation

This document provides a complete reference for all layers and key mappings in the Chocofi keyboard configuration.

## Custom Shift Implementation

This keymap uses a **custom shift system** on the NUMER layer that differs from standard keyboard behavior:

### Standard Shift (ALPHA Layer)
On the base ALPHA layer, shift works normally - it capitalizes letters and accesses standard shifted symbols (e.g., `,` → `.`).

### Custom RSFT Remapping (NUMER Layer)
On the NUMER layer, **RSFT (Right Shift on thumb)** acts as a **layer modifier** that completely remaps keys to different symbols:

- **Without RSFT**: Numbers and primary symbols (`1`, `2`, `3`, `@`, `$`, etc.)
- **With RSFT**: Function keys and alternate symbols (`F1`, `F2`, `F3`, `£`, `€`, etc.)

This is **not** the standard shift behavior - it's a general remapping where RSFT changes what keys are associated with what other keys. Think of it as "Layer 4 + RSFT = Layer 4 alternate mapping" rather than traditional shift.

**Key Difference:**
- ALPHA layer: Any shift key produces standard shifted characters
- NUMER layer: Only RSFT (thumb key) triggers the custom remapping via mod-morph behaviors

This allows quick access to both number/symbol sets and function keys without needing a separate layer.

---

## Layer Overview

- **Layer 0:** ALPHA - Base typing layer (Colemak-DH)
- **Layer 1:** WASD - Gaming layer
- **Layer 2:** LEFT_NAV - Left-hand navigation
- **Layer 3:** RIGHT_NAV - Right-hand media and navigation
- **Layer 4:** NUMER - Numbers and symbols
- **Layer 4+RSFT:** NUMER with custom RSFT remapping (alternate symbol set)
- **Layer 5:** LEFT_MODS - Left-hand modifiers
- **Layer 6:** RIGHT_MODS - Right-hand modifiers
- **Layer 7:** MOUSE - Mouse emulation (LEFT_NAV + RIGHT_NAV)
- **Layer 8:** SYSTEM - System and Bluetooth controls (LEFT_NAV + LEFT_MODS)

---

## Section 1: Spatial Key Layouts

### Layer 0: ALPHA (Base Layer - Colemak-DH)

**Left Hand:**
```
Q       K       F       P       B
A       R       S       T       SPACE
Z       X       C       D       V
        ESC     RET     NUMER
        (L2)    (L5)    (L4)
```

**Right Hand:**
```
;       L       U       Y       W
,/.     N       E       I       O
'       H       M       G       J
RSHIFT  TAB     F12
        (L6)    (L3)
```

**Notes:**
- Comma key (`,`) becomes period (`.`) when RSFT is held (mod-morph)
- Thumb keys use layer-tap hold-preferred behavior

---

### Layer 1: WASD (Gaming)

**Activation:** Toggle via Layer 5 or Layer 6 top-right position

**Left Hand:**
```
1       2       3       4       5
SHIFT   Q       W       E       R
CTRL    A       S       D       F
        TAB     Z       SPACE
```

**Right Hand:**
```
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     L3      L2
```

**Notes:**
- Gaming layer for traditional WASD layout
- Right hand remains transparent for normal typing
- Thumb cluster provides layer access for navigation

---

### Layer 2: LEFT_NAV (Navigation)

**Left Hand:**
```
CTRL    LEFT    UP      RIGHT   PASTE
GUI     BSPC    SHIFT   DEL     COPY
HYPER   UNDO    DOWN    REDO    CUT
        ---     ---     ---
```

**Right Hand:**
```
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---
```

**Notes:**
- HYPER = GUI+Alt+Ctrl+Shift (all modifiers)
- PASTE = Ctrl+V
- COPY = Ctrl+C
- CUT = Ctrl+X
- UNDO = Ctrl+Z
- REDO = Ctrl+Y

---

### Layer 3: RIGHT_NAV (Media & Navigation)

**Left Hand:**
```
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---
```

**Right Hand:**
```
VOL+    HOME    PG_UP   END     GAME
VOL-    PREV    K_APP   NEXT    MUTE
PLAY    BSPC    PG_DN   DEL     PSCRN
---     ---     ---
```

**Notes:**
- GAME = Toggle Layer 1 (gaming layer)
- K_APP = Application/Menu key (with SHIFT mod-tap)
- Media controls: PREV/NEXT track, PLAY/PAUSE, VOL+/-, MUTE
- Navigation: HOME, END, PG_UP, PG_DN
- PSCRN = Print Screen

---

### Layer 4: NUMER (Numbers & Symbols)

**Left Hand:**
```
^       1       2       3       .
*       4       5       6       -
+       7       8       9       0
        ---     ---     ---
```

**Right Hand:**
```
!       @       $       #       |
/       <       (       [       {
=       &       ~       _       %
---     S+TAB   S+F12
```

**Notes:**
- Numbers 1-9, 0 on left hand
- Symbols arranged for programming
- Paired symbols: `<>`, `()`, `[]`, `{}`
- Math operators: `+`, `-`, `*`, `/`, `=`
- Special symbols: `^`, `@`, `$`, `#`, `|`, `&`, `~`, `_`, `%`, `!`

---

### Layer 4+RSFT: NUMER with Custom RSFT Remapping

When RSFT (sticky shift on thumb) is held, **custom mod-morph behaviors** remap keys to an alternate symbol set. This is **not standard shift behavior** - it's a complete key remapping:

**Left Hand:**
```
^       F1      F2      F3      .
*       F4      F5      F6      -
+       F7      F8      F9      F10
        ---     ---     ---
```

**Right Hand:**
```
?       @       $       #       |
\       >       )       ]       }
`       &       ~       _       %
---     S+TAB   S+F12
```

**Custom RSFT Remappings:**
- **Numbers → Function Keys:** `1`→`F1`, `2`→`F2`, `3`→`F3`, `4`→`F4`, `5`→`F5`, `6`→`F6`, `7`→`F7`, `8`→`F8`, `9`→`F9`, `0`→`F10`
- **Symbol Remappings:** `!`→`?`, `/`→`\`, `<`→`>`, `(`→`)`, `[`→`]`, `{`→`}`, `=`→`` ` ``

**Important:** This only responds to RSFT (the sticky shift on your right thumb), not any shift key. This creates a custom "alternate symbol layer" accessible via the thumb shift, allowing quick access to both number/symbol sets and function keys without switching layers.

---

### Layer 5: LEFT_MODS (Left Modifiers)

**Left Hand:**
```
---     ---     ---     ---     ---
GUI     ALT     SHIFT   CTRL    ---
---     ---     ---     ---     ---
        ---     ---     ---
```

**Right Hand:**
```
---     ---     ---     ---     GAME
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---
```

**Notes:**
- Modifiers use sticky-mod hold-tap behavior
- Tap = sticky modifier (stays active for one key)
- Hold = regular modifier (active while held)
- GAME = Toggle Layer 1 (top-right position)

---

### Layer 6: RIGHT_MODS (Right Modifiers)

**Left Hand:**
```
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---
```

**Right Hand:**
```
---     ---     ---     ---     GAME
---     CTRL    SHIFT   ALT     GUI
---     ---     ---     ---     ---
---     ---     ---
```

**Notes:**
- Modifiers use sticky-mod hold-tap behavior
- Tap = sticky modifier (stays active for one key)
- Hold = regular modifier (active while held)
- GAME = Toggle Layer 1 (top-right position)
- Mirrors Layer 5 on right hand

---

### Layer 7: MOUSE (Mouse Emulation)

**Activation:** LEFT_NAV (Layer 2) + RIGHT_NAV (Layer 3) held together

**Left Hand:**
```
---     M_LEFT  M_UP    M_RIGHT ---
GUI     ALT     SHIFT   CTRL    ---
---     ---     M_DOWN  ---     ---
        ---     ---     ---
```

**Right Hand:**
```
---     LCLK    MCLK    RCLK    ---
---     CTRL    SHIFT   ALT     GUI
---     ---     ---     ---     ---
---     ---     ---
```

**Notes:**
- Mouse movement: M_LEFT, M_RIGHT, M_UP, M_DOWN
- Mouse clicks: LCLK (left), MCLK (middle), RCLK (right)
- Modifiers available on both hands for modified clicks

---

### Layer 8: SYSTEM (System & Bluetooth Controls)

**Activation:** LEFT_NAV (Layer 2) + LEFT_MODS (Layer 5) held together

**Left Hand:**
```
BT_0    BT_1    BT_2    BT_3    BT_4
RESET   BOOT    STUDIO  ---     ---
---     ---     ---     ---     BT_CLR
        ---     ---     ---
```

**Right Hand:**
```
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---
```

**Notes:**
- BT_0 through BT_4 = Bluetooth profile selection (5 profiles)
- BT_CLR = Clear current Bluetooth profile
- RESET = System reset
- BOOT = Enter bootloader mode (for firmware flashing)
- STUDIO = Unlock ZMK Studio (for live keymap editing)

---

## Section 2: Key-by-Key Breakdown

### Position: Top Row, Column 1 (Q position)

- **Layer 0 (ALPHA):** Q
- **Layer 1 (WASD):** 1
- **Layer 2 (LEFT_NAV):** CTRL
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** ^ (caret)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** BT_0 (Bluetooth profile 0)

### Position: Top Row, Column 2 (K position)

- **Layer 0 (ALPHA):** K
- **Layer 1 (WASD):** 2
- **Layer 2 (LEFT_NAV):** LEFT arrow
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 1
- **Layer 4+RSFT:** F1
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Mouse move left
- **Layer 8 (SYSTEM):** BT_1 (Bluetooth profile 1)

### Position: Top Row, Column 3 (F position)

- **Layer 0 (ALPHA):** F
- **Layer 1 (WASD):** 3
- **Layer 2 (LEFT_NAV):** UP arrow
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 2
- **Layer 4+RSFT:** F2
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Mouse move up
- **Layer 8 (SYSTEM):** BT_2 (Bluetooth profile 2)

### Position: Top Row, Column 4 (P position)

- **Layer 0 (ALPHA):** P
- **Layer 1 (WASD):** 4
- **Layer 2 (LEFT_NAV):** RIGHT arrow
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 3
- **Layer 4+RSFT:** F3
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Mouse move right
- **Layer 8 (SYSTEM):** BT_3 (Bluetooth profile 3)

### Position: Top Row, Column 5 (B position)

- **Layer 0 (ALPHA):** B
- **Layer 1 (WASD):** 5
- **Layer 2 (LEFT_NAV):** Ctrl+V (paste)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** . (period)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** BT_4 (Bluetooth profile 4)

### Position: Top Row, Column 6 (SEMI position)

- **Layer 0 (ALPHA):** ; (semicolon)
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Volume up
- **Layer 4 (NUMER):** ! (exclamation)
- **Layer 4+RSFT:** ? (question mark)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Top Row, Column 7 (L position)

- **Layer 0 (ALPHA):** L
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** HOME
- **Layer 4 (NUMER):** @ (at sign)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Left click
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Top Row, Column 8 (U position)

- **Layer 0 (ALPHA):** U
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** PG_UP
- **Layer 4 (NUMER):** $ (dollar)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Middle click
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Top Row, Column 9 (Y position)

- **Layer 0 (ALPHA):** Y
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** END
- **Layer 4 (NUMER):** # (hash)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Right click
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Top Row, Column 10 (W position)

- **Layer 0 (ALPHA):** W
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Toggle Layer 1 (WASD/Gaming)
- **Layer 4 (NUMER):** | (pipe)
- **Layer 5 (LEFT_MODS):** Toggle Layer 1 (WASD/Gaming)
- **Layer 6 (RIGHT_MODS):** Toggle Layer 1 (WASD/Gaming)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Home Row, Column 1 (A position)

- **Layer 0 (ALPHA):** A
- **Layer 1 (WASD):** Left Shift
- **Layer 2 (LEFT_NAV):** GUI
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** * (asterisk)
- **Layer 5 (LEFT_MODS):** GUI (tap: sticky, hold: regular)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** GUI
- **Layer 8 (SYSTEM):** System reset

### Position: Home Row, Column 2 (R position)

- **Layer 0 (ALPHA):** R
- **Layer 1 (WASD):** Q
- **Layer 2 (LEFT_NAV):** Backspace
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 4
- **Layer 4+RSFT:** F4
- **Layer 5 (LEFT_MODS):** Alt (tap: sticky, hold: regular)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Alt
- **Layer 8 (SYSTEM):** Bootloader

### Position: Home Row, Column 3 (S position)

- **Layer 0 (ALPHA):** S
- **Layer 1 (WASD):** W
- **Layer 2 (LEFT_NAV):** SHIFT
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 5
- **Layer 4+RSFT:** F5
- **Layer 5 (LEFT_MODS):** Shift (tap: sticky, hold: regular)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Shift
- **Layer 8 (SYSTEM):** Studio unlock

### Position: Home Row, Column 4 (T position)

- **Layer 0 (ALPHA):** T
- **Layer 1 (WASD):** E
- **Layer 2 (LEFT_NAV):** Delete
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 6
- **Layer 4+RSFT:** F6
- **Layer 5 (LEFT_MODS):** Ctrl (tap: sticky, hold: regular)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Ctrl
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Home Row, Column 5 (SPACE position)

- **Layer 0 (ALPHA):** Space
- **Layer 1 (WASD):** R
- **Layer 2 (LEFT_NAV):** Ctrl+C (copy)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** - (minus/hyphen)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Home Row, Column 6 (COMMA position)

- **Layer 0 (ALPHA):** , (comma) / . (period with RSFT)
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Volume down
- **Layer 4 (NUMER):** / (slash)
- **Layer 4+RSFT:** \ (backslash)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Home Row, Column 7 (N position)

- **Layer 0 (ALPHA):** N
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Previous track
- **Layer 4 (NUMER):** < (less than)
- **Layer 4+RSFT:** > (greater than)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** Ctrl (tap: sticky, hold: regular)
- **Layer 7 (MOUSE):** Ctrl
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Home Row, Column 8 (E position)

- **Layer 0 (ALPHA):** E
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** K_APP (application/menu key with SHIFT mod-tap)
- **Layer 4 (NUMER):** ( (left paren)
- **Layer 4+RSFT:** ) (right paren)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** Shift (tap: sticky, hold: regular)
- **Layer 7 (MOUSE):** Shift
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Home Row, Column 9 (I position)

- **Layer 0 (ALPHA):** I
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Next track
- **Layer 4 (NUMER):** [ (left bracket)
- **Layer 4+RSFT:** ] (right bracket)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** Alt (tap: sticky, hold: regular)
- **Layer 7 (MOUSE):** Alt
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Home Row, Column 10 (O position)

- **Layer 0 (ALPHA):** O
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Mute
- **Layer 4 (NUMER):** { (left brace)
- **Layer 4+RSFT:** } (right brace)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** GUI (tap: sticky, hold: regular)
- **Layer 7 (MOUSE):** GUI
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 1 (Z position)

- **Layer 0 (ALPHA):** Z
- **Layer 1 (WASD):** Left Ctrl
- **Layer 2 (LEFT_NAV):** Hyper (GUI+Alt+Ctrl+Shift)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** + (plus)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** Bluetooth clear

### Position: Bottom Row, Column 2 (X position)

- **Layer 0 (ALPHA):** X
- **Layer 1 (WASD):** A
- **Layer 2 (LEFT_NAV):** Ctrl+Z (undo)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 7
- **Layer 4+RSFT:** F7
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 3 (C position)

- **Layer 0 (ALPHA):** C
- **Layer 1 (WASD):** S
- **Layer 2 (LEFT_NAV):** DOWN arrow
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 8
- **Layer 4+RSFT:** F8
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Mouse move down
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 4 (D position)

- **Layer 0 (ALPHA):** D
- **Layer 1 (WASD):** D
- **Layer 2 (LEFT_NAV):** Ctrl+Y (redo)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 9
- **Layer 4+RSFT:** F9
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 5 (V position)

- **Layer 0 (ALPHA):** V
- **Layer 1 (WASD):** F
- **Layer 2 (LEFT_NAV):** Ctrl+X (cut)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** 0
- **Layer 4+RSFT:** F10
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 6 (QUOTE position)

- **Layer 0 (ALPHA):** ' (single quote)
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Play/Pause
- **Layer 4 (NUMER):** = (equals)
- **Layer 4+RSFT:** ` (backtick/grave)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 7 (H position)

- **Layer 0 (ALPHA):** H
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Backspace
- **Layer 4 (NUMER):** & (ampersand)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 8 (M position)

- **Layer 0 (ALPHA):** M
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** PG_DN
- **Layer 4 (NUMER):** ~ (tilde)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 9 (G position)

- **Layer 0 (ALPHA):** G
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Delete
- **Layer 4 (NUMER):** _ (underscore)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Bottom Row, Column 10 (J position)

- **Layer 0 (ALPHA):** J
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Print Screen
- **Layer 4 (NUMER):** % (percent)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (SYSTEM):** --- (transparent)

### Position: Thumb Row, Left 1 (ESC position)

- **Layer 0 (ALPHA):** ESC (tap) / Layer 2 (hold)
- **Layer 1 (WASD):** TAB
- **All other layers:** --- (transparent)

### Position: Thumb Row, Left 2 (RET position)

- **Layer 0 (ALPHA):** RET/Enter (tap) / Layer 5 (hold)
- **Layer 1 (WASD):** Z
- **All other layers:** --- (transparent)

### Position: Thumb Row, Left 3 (NUMER position)

- **Layer 0 (ALPHA):** Sticky Layer 4 (one-shot layer)
- **Layer 1 (WASD):** SPACE
- **All other layers:** --- (transparent)

### Position: Thumb Row, Right 1 (RSHIFT position)

- **Layer 0 (ALPHA):** Sticky RSHIFT (one-shot modifier)
- **All other layers:** --- (transparent)

### Position: Thumb Row, Right 2 (TAB position)

- **Layer 0 (ALPHA):** TAB (tap) / Layer 6 (hold)
- **Layer 1 (WASD):** Momentary Layer 3
- **All other layers:** --- (transparent)

### Position: Thumb Row, Right 3 (F12 position)

- **Layer 0 (ALPHA):** F12 (tap) / Layer 3 (hold)
- **Layer 1 (WASD):** Momentary Layer 2
- **All other layers:** --- (transparent)

---

## Notes

### Conditional Layers

- **Layer 7 (MOUSE)** activates when LEFT_NAV (Layer 2) + RIGHT_NAV (Layer 3) are both held
- **Layer 8 (SYSTEM)** activates when LEFT_NAV (Layer 2) + LEFT_MODS (Layer 5) are held

### Mod-Morph Behaviors

This keymap uses mod-morph behaviors differently on different layers:

**ALPHA Layer (Standard Shift):**
- `,` → `.` when **any shift** is held (standard typing behavior)
- This is normal shift functionality for typing

**NUMER Layer (Custom RSFT Remapping):**
The following keys change **only when RSFT (sticky shift on thumb) is held**. This is a custom remapping system, not standard shift:

**Numbers → Function Keys:**
- `1` → `F1`, `2` → `F2`, `3` → `F3`, `4` → `F4`, `5` → `F5`
- `6` → `F6`, `7` → `F7`, `8` → `F8`, `9` → `F9`, `0` → `F10`

**Symbol Remappings:**
- `!` → `?`
- `/` → `\`
- `<` → `>`
- `(` → `)`
- `[` → `]`
- `{` → `}`
- `=` → `` ` ``

**Why the difference?**
- ALPHA uses standard shift for normal typing
- NUMER uses RSFT as a **layer modifier** to access an alternate symbol set
- This allows the NUMER layer to effectively have two "sub-layers" accessible via the thumb shift

### Sticky Behaviors

**Sticky Modifiers (on Layer 5 and 6):**
- Tap = modifier stays active for next keypress only
- Hold = modifier active while held

**Sticky Layer (Layer 4 on thumb):**
- Tap = Layer 4 active for next keypress only
- Allows quick access to numbers/symbols without holding

### Layer-Tap Behaviors

All thumb keys except the sticky layer use layer-tap hold-preferred:
- Tap = send keycode (ESC, RET, TAB, F12)
- Hold = activate layer (2, 3, 5, 6)
- Hold-preferred flavor activates layer immediately when another key is pressed

### Gaming Layer

Layer 1 (WASD) can be toggled on/off via:
- Layer 5 (LEFT_MODS) top-right position
- Layer 6 (RIGHT_MODS) top-right position
- Layer 3 (RIGHT_NAV) top-right position

When active, left hand becomes traditional gaming layout with WASD, number row, and modifier keys.
