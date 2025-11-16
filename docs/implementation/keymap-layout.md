# Chocofi Keymap Layout Documentation

This document provides a complete reference for all layers and key mappings in the Chocofi keyboard configuration.

## Unicode Transform Leader Keys

### Overview

The keyboard implements a "capswords-style" leader key system for Unicode character transformations. When a leader key is activated, it remains active until a key is pressed that cannot be transformed, excluding space, enter, comma, and period (which can be transformed and don't deactivate the leader).

### Leader Key Assignments (Layer 13 - UNICODE_NUMER)

| Leader Key | Transform | Coverage | Example |
|------------|-----------|----------|---------|
| `^` (caret) | Superscript | Numbers: ⁰¹²³⁴⁵⁶⁷⁸⁹<br>Symbols: ⁺⁻⁼⁽⁾<br>Letters: ⁱⁿ (limited) | x² + y³ = z⁴ |
| `_` (underscore) | Subscript | Numbers: ₀₁₂₃₄₅₆₇₈₉<br>Symbols: ₊₋₌₍₎<br>Letters: ₐₑₒₓₔₕₖₗₘₙₚₛₜ | H₂O, CO₂ |
| `/` (slash) | Fractions | Number pairs: ½ ¼ ¾ ⅓ ⅔ ⅕ ⅖ ⅗ ⅘ ⅙ ⅚ ⅐ ⅛ ⅜ ⅝ ⅞ ⅑ ⅒ | 1/2 → ½ |
| `*` (asterisk) | Circled | Numbers: ①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮⑯⑰⑱⑲⑳<br>Uppercase: ⒶⒷⒸⒹⒺⒻⒼⒽⒾⒿⓀⓁⓂⓃⓄⓅⓆⓇⓈⓉⓊⓋⓌⓍⓎⓏ<br>Lowercase: ⓐⓑⓒⓓⓔⓕⓖⓗⓘⓙⓚⓛⓜⓝⓞⓟⓠⓡⓢⓣⓤⓥⓦⓧⓨⓩ | ①②③ ⒶⒷⒸ |
| `-` (minus) | Strikethrough | All letters and numbers using combining character U+0336 | A̶B̶C̶ |
| `=` (equals) | Underline | All letters and numbers using combining character U+0332 | A̲B̲C̲ |

### Behavior Details

**Activation:**
1. Access Layer 13 (UNICODE_NUMER) via Unicode modifier (Z on LEFT_MODS or J on RIGHT_MODS)
2. Press a leader key (^, _, /, *, -, or =)
3. Leader mode activates and remains active

**Transformation:**
- Type characters that have transform variants → transformed characters are output
- Type space, enter, comma, or period → these are transformed if possible, leader stays active
- Type any other character without a transform variant → leader deactivates, character passes through normally

**Deactivation:**
- Automatically deactivates when a non-transformable character (other than space/enter/comma/period) is pressed
- Can be manually deactivated by pressing the leader key again (toggle behavior)

**Examples:**

```
Superscript: Unicode+^ then "x2" → x²
Subscript: Unicode+_ then "H2O" → H₂O
Fraction: Unicode+/ then "1" then "2" → ½
Circled: Unicode+* then "ABC" → ⒶⒷⒸ
Strikethrough: Unicode+- then "DONE" → D̶O̶N̶E̶
Underline: Unicode+= then "TODO" → T̲O̲D̲O̲
```

### Implementation Notes

- Fraction leader (`/`) waits for exactly two number keypresses, then outputs the fraction if valid
- Strikethrough and underline use Unicode combining characters (U+0336 and U+0332)
- Combining characters may not render correctly in all fonts/applications
- Leader keys use a "sticky" behavior similar to capswords in ZMK

### Freed Positions

By implementing superscript and subscript as leader keys instead of direct mappings, the following positions on Layer 13 are freed for other unicode symbols:

**Number positions (10 freed):**
- K, F, P (1, 2, 3)
- R, S, T (4, 5, 6)
- X, C, D (7, 8, 9)
- V (0)

**RSFT variants (10 freed):**
- Same positions with RSFT held (previously subscripts)

**Total: 20 position-variants available for additional unicode symbols**

---

## Layer Overview

- **Layer 0:** ALPHA - Base typing layer (Colemak-DH)
- **Layer 1:** WASD - Gaming layer
- **Layer 2:** LEFT_NAV - Left-hand navigation
- **Layer 3:** RIGHT_NAV - Right-hand media and scrolling
- **Layer 4:** NUMER - Numbers and symbols
- **Layer 4+RSFT:** NUMER with Right Shift modifier
- **Layer 5:** LEFT_MODS - Left-hand modifiers
- **Layer 6:** RIGHT_MODS - Right-hand modifiers
- **Layer 7:** MOUSE - Mouse emulation (LEFT_NAV + RIGHT_NAV)
- **Layer 8:** LEFT_SYSTEM - Left-hand system controls (LEFT_NAV + LEFT_MODS)
- **Layer 9:** RIGHT_SYSTEM - Right-hand system controls (RIGHT_NAV + RIGHT_MODS)
- **Layer 10:** UNICODE_ALPHA - Greek alphabet
- **Layer 11:** UNICODE_LEFT_NAV - Unicode navigation symbols
- **Layer 12:** UNICODE_RIGHT_NAV - Unicode media symbols
- **Layer 13:** UNICODE_NUMER - Math symbols and transform leaders
- **Layer 14:** UNICODE_MOUSE - Unicode pointing symbols

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

---

### Layer 1: WASD (Gaming)

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

---

### Layer 3: RIGHT_NAV (Media & Scroll)

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

---

### Layer 4+RSFT: NUMER with Right Shift

**Left Hand:**
```
°       F1      F2      F3      …
×       F4      F5      F6      —
±       F7      F8      F9      F10
        ---     ---     ---
```

**Right Hand:**
```
?       £       €       ¥       ¦
\       >       )       ]       }
`       §       ≈       ÷       ‰
---     S+TAB   S+F12
```

---

### Layer 5: LEFT_MODS (Left Modifiers)

**Left Hand:**
```
---     ---     ---     ---     ---
GUI     ALT     SHIFT   CTRL    ---
UNICODE ---     ---     ---     ---
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
- UNICODE = Activates unicode layer variants (Layers 10-14)
- When held, transforms base layers to unicode equivalents

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
---     ---     ---     ---     UNICODE
---     ---     ---
```

**Notes:**
- UNICODE = Activates unicode layer variants (Layers 10-14)
- When held, transforms base layers to unicode equivalents

---

### Layer 7: MOUSE (Mouse Emulation)

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

---

### Layer 8: LEFT_SYSTEM (Left-Hand System Controls)

**Activation:** LEFT_NAV (Layer 2) + LEFT_MODS (Layer 5)

**Left Hand:**
```
BT_0    BT_1    BT_2    BT_3    BT_4
RESET   BOOT    STUDIO  ---     REISUB
BT_CLR  ---     ---     ---     ---
        ---     ---     ---
```

**Right Hand:**
```
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---
```

---

### Layer 9: RIGHT_SYSTEM (Right-Hand System Controls)

**Activation:** RIGHT_NAV (Layer 3) + RIGHT_MODS (Layer 6)

**Left Hand:**
```
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---
```

**Right Hand:**
```
BT_4    BT_3    BT_2    BT_1    BT_0
REISUB  ---     STUDIO  BOOT    RESET
---     ---     ---     ---     BT_CLR
GAME    ---     ---
```

---

### Layer 10: UNICODE_ALPHA (Greek Alphabet)

**Activation:** Hold UNICODE modifier (Z or J on mod layers)

**Left Hand:**
```
θ       κ       φ       π       β
α       ρ       σ       τ       SPACE
ζ       ξ       χ       δ       ---
        ---     ---     ---
```

**Right Hand:**
```
;       λ       υ       ψ       ω
,/.     ν       ε       ι       ο
'       η       μ       γ       ---
RSHIFT  ---     ---
```

**Notes:**
- With Shift held, produces uppercase Greek letters (Θ, Α, Σ, etc.)
- Mirrors ALPHA layer structure with Greek equivalents

---

### Layer 11: UNICODE_LEFT_NAV (Unicode Navigation)

**Activation:** Hold UNICODE modifier (Z or J on mod layers)

**Left Hand:**
```
⌘       ←       ↑       →       ©
⌥       ⌫       ⇧       ⌦       ©
⎙       ↶       ↓       ↷       ✂
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
- With Shift held, arrows become double arrows (⇐, ⇑, ⇒, ⇓)
- Mirrors LEFT_NAV layer with unicode symbol equivalents

---

### Layer 12: UNICODE_RIGHT_NAV (Unicode Media)

**Activation:** Hold UNICODE modifier (Z or J on mod layers)

**Left Hand:**
```
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---     ---     ---
---     ---     ---
```

**Right Hand:**
```
🔊      ⇱       ⇞       ⇲       🎮
🔉      ⏮       ⚙       ⏭       🔇
⏯       ⌫       ⇟       ⌦       📷
---     ---     ---
```

**Notes:**
- Mirrors RIGHT_NAV layer with unicode symbol equivalents

---

### Layer 13: UNICODE_NUMER (Math Symbols & Transform Leaders)

**Activation:** Hold UNICODE modifier (Z or J on mod layers)

**Left Hand:**
```
^SUPER  ∞       √       ∛       ∙
*CIRCL  ∫       ∑       ∏       −
-STRK   ∂       ∇       Δ       ∅
        ---     ---     ---
```

**Right Hand:**
```
‽       ∀       ∃       №       ∨
/FRAC   ≪       ∈       ∉       ⊂
=UNDR   ∧       ∼       _SUB    ‱
---     ---     ---
```

**Legend:**
- `^SUPER` - Superscript leader (capswords-style)
- `_SUB` - Subscript leader (capswords-style)
- `/FRAC` - Fraction leader (waits for 2 numbers)
- `*CIRCL` - Circled character leader (capswords-style)
- `-STRK` - Strikethrough leader (capswords-style)
- `=UNDR` - Underline leader (capswords-style)

**Notes:**
- With RSFT held, `∧` → `∩` (intersection), `∨` → `∪` (union)
- Leader keys remain active until a non-transformable character (excluding space/enter/comma/period) is pressed
- See "Unicode Transform Leader Keys" section at top of document for full details

---

### Layer 14: UNICODE_MOUSE (Unicode Pointing)

**Activation:** Hold UNICODE modifier (Z or J on mod layers)

**Left Hand:**
```
---     ⬅       ⬆       ➡       ---
---     ---     ---     ---     ---
---     ---     ⬇       ---     ---
---     ---     ---
```

**Right Hand:**
```
---     👆      ☝       👉      ---
---     ---     ---     ---     ---
---     ---     ⬇       ---     ---
---     ---     ---
```

**Notes:**
- Mirrors MOUSE layer with unicode pointing symbols

---

## Section 2: Key-by-Key Breakdown

### Position: Top Row, Column 1 (Q position)

- **Layer 0 (ALPHA):** Q
- **Layer 1 (WASD):** 1
- **Layer 2 (LEFT_NAV):** CTRL
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** ^ (caret)
- **Layer 4+RSFT:** ° (degree symbol)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** BT_0 (Bluetooth profile 0)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** θ (theta)
- **Layer 10+Shift:** Θ (Theta)
- **Layer 11 (UNICODE_LEFT_NAV):** ⌘ (command symbol)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ^SUPER (superscript leader - activates capswords-style superscript mode)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** BT_1 (Bluetooth profile 1)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** κ (kappa)
- **Layer 10+Shift:** Κ (Kappa)
- **Layer 11 (UNICODE_LEFT_NAV):** ← (left arrow)
- **Layer 11+Shift:** ⇐ (double left arrow)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∞ (infinity)
- **Layer 14 (UNICODE_MOUSE):** ⬅ (left arrow)

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
- **Layer 8 (LEFT_SYSTEM):** BT_2 (Bluetooth profile 2)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** φ (phi)
- **Layer 10+Shift:** Φ (Phi)
- **Layer 11 (UNICODE_LEFT_NAV):** ↑ (up arrow)
- **Layer 11+Shift:** ⇑ (double up arrow)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** √ (square root)
- **Layer 14 (UNICODE_MOUSE):** ⬆ (up arrow)

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
- **Layer 8 (LEFT_SYSTEM):** BT_3 (Bluetooth profile 3)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** π (pi)
- **Layer 10+Shift:** Π (Pi)
- **Layer 11 (UNICODE_LEFT_NAV):** → (right arrow)
- **Layer 11+Shift:** ⇒ (double right arrow)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∛ (cube root)
- **Layer 14 (UNICODE_MOUSE):** ➡ (right arrow)

### Position: Top Row, Column 5 (B position)

- **Layer 0 (ALPHA):** B
- **Layer 1 (WASD):** 5
- **Layer 2 (LEFT_NAV):** Ctrl+V (paste)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** . (period)
- **Layer 4+RSFT:** … (ellipsis)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** BT_4 (Bluetooth profile 4)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** β (beta)
- **Layer 10+Shift:** Β (Beta)
- **Layer 11 (UNICODE_LEFT_NAV):** © (copyright)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∙ (bullet operator)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** BT_4 (Bluetooth profile 4)
- **Layer 10 (UNICODE_ALPHA):** ; (semicolon)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** 🔊 (speaker high volume)
- **Layer 13 (UNICODE_NUMER):** ‽ (interrobang)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

### Position: Top Row, Column 7 (L position)

- **Layer 0 (ALPHA):** L
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** HOME
- **Layer 4 (NUMER):** @ (at sign)
- **Layer 4+RSFT:** £ (pound sterling)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Left click
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** BT_3 (Bluetooth profile 3)
- **Layer 10 (UNICODE_ALPHA):** λ (lambda)
- **Layer 10+Shift:** Λ (Lambda)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⇱ (home)
- **Layer 13 (UNICODE_NUMER):** ∀ (for all)
- **Layer 14 (UNICODE_MOUSE):** 👆 (pointing up)

### Position: Top Row, Column 8 (U position)

- **Layer 0 (ALPHA):** U
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** PG_UP
- **Layer 4 (NUMER):** $ (dollar)
- **Layer 4+RSFT:** € (euro)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Middle click
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** BT_2 (Bluetooth profile 2)
- **Layer 10 (UNICODE_ALPHA):** υ (upsilon)
- **Layer 10+Shift:** Υ (Upsilon)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⇞ (page up)
- **Layer 13 (UNICODE_NUMER):** ∃ (there exists)
- **Layer 14 (UNICODE_MOUSE):** ☝ (pointing up hand)

### Position: Top Row, Column 9 (Y position)

- **Layer 0 (ALPHA):** Y
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** END
- **Layer 4 (NUMER):** # (hash)
- **Layer 4+RSFT:** ¥ (yen)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** Right click
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** BT_1 (Bluetooth profile 1)
- **Layer 10 (UNICODE_ALPHA):** ψ (psi)
- **Layer 10+Shift:** Ψ (Psi)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⇲ (end)
- **Layer 13 (UNICODE_NUMER):** № (numero sign)
- **Layer 14 (UNICODE_MOUSE):** 👉 (pointing right)

### Position: Top Row, Column 10 (W position)

- **Layer 0 (ALPHA):** W
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Toggle Layer 1 (WASD/Gaming)
- **Layer 4 (NUMER):** | (pipe)
- **Layer 4+RSFT:** ¦ (broken bar)
- **Layer 5 (LEFT_MODS):** Toggle Layer 1 (WASD/Gaming)
- **Layer 6 (RIGHT_MODS):** Toggle Layer 1 (WASD/Gaming)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** BT_0 (Bluetooth profile 0)
- **Layer 10 (UNICODE_ALPHA):** ω (omega)
- **Layer 10+Shift:** Ω (Omega)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** 🎮 (game controller)
- **Layer 13 (UNICODE_NUMER):** ∨ (logical OR)
- **Layer 13+RSFT:** ∪ (union)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

### Position: Home Row, Column 1 (A position)

- **Layer 0 (ALPHA):** A
- **Layer 1 (WASD):** Left Shift
- **Layer 2 (LEFT_NAV):** GUI
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** * (asterisk)
- **Layer 4+RSFT:** × (multiplication)
- **Layer 5 (LEFT_MODS):** GUI (tap: sticky, hold: regular)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** GUI
- **Layer 8 (LEFT_SYSTEM):** System reset
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** α (alpha)
- **Layer 10+Shift:** Α (Alpha)
- **Layer 11 (UNICODE_LEFT_NAV):** ⌥ (option/alt symbol)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** *CIRCL (circled character leader - activates capswords-style circled mode)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** Bootloader
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** ρ (rho)
- **Layer 10+Shift:** Ρ (Rho)
- **Layer 11 (UNICODE_LEFT_NAV):** ⌫ (delete backward)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∫ (integral)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** Studio unlock
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** σ (sigma)
- **Layer 10+Shift:** Σ (Sigma)
- **Layer 11 (UNICODE_LEFT_NAV):** ⇧ (shift symbol)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∑ (summation)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** τ (tau)
- **Layer 10+Shift:** Τ (Tau)
- **Layer 11 (UNICODE_LEFT_NAV):** ⌦ (delete forward)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∏ (product)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

### Position: Home Row, Column 5 (SPACE position)

- **Layer 0 (ALPHA):** Space
- **Layer 1 (WASD):** R
- **Layer 2 (LEFT_NAV):** Ctrl+C (copy)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** - (minus/hyphen)
- **Layer 4+RSFT:** — (em dash)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** REISUB macro
- **Layer 9 (RIGHT_SYSTEM):** REISUB macro
- **Layer 10 (UNICODE_ALPHA):** Space
- **Layer 11 (UNICODE_LEFT_NAV):** © (copyright)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** − (proper minus sign)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** , (comma) / . (period with RSFT)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** 🔉 (speaker medium volume)
- **Layer 13 (UNICODE_NUMER):** /FRAC (fraction leader - waits for 2 numbers then outputs fraction)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** ν (nu)
- **Layer 10+Shift:** Ν (Nu)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⏮ (previous track)
- **Layer 13 (UNICODE_NUMER):** ≪ (much less than)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** Studio unlock
- **Layer 10 (UNICODE_ALPHA):** ε (epsilon)
- **Layer 10+Shift:** Ε (Epsilon)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⚙ (gear/settings)
- **Layer 13 (UNICODE_NUMER):** ∈ (element of)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** Bootloader
- **Layer 10 (UNICODE_ALPHA):** ι (iota)
- **Layer 10+Shift:** Ι (Iota)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⏭ (next track)
- **Layer 13 (UNICODE_NUMER):** ∉ (not element of)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** System reset
- **Layer 10 (UNICODE_ALPHA):** ο (omicron)
- **Layer 10+Shift:** Ο (Omicron)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** 🔇 (muted speaker)
- **Layer 13 (UNICODE_NUMER):** ⊂ (subset)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

### Position: Bottom Row, Column 1 (Z position)

- **Layer 0 (ALPHA):** Z
- **Layer 1 (WASD):** Left Ctrl
- **Layer 2 (LEFT_NAV):** Hyper (GUI+Alt+Ctrl+Shift)
- **Layer 3 (RIGHT_NAV):** --- (transparent)
- **Layer 4 (NUMER):** + (plus)
- **Layer 4+RSFT:** ± (plus-minus)
- **Layer 5 (LEFT_MODS):** Unicode modifier (tap: sticky, hold: regular)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** Bluetooth clear
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** ζ (zeta)
- **Layer 10+Shift:** Ζ (Zeta)
- **Layer 11 (UNICODE_LEFT_NAV):** ⎙ (print screen symbol)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** -STRK (strikethrough leader - activates capswords-style strikethrough using U+0336)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

**Notes:**
- Unicode modifier activates Layers 10-14 when held

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** ξ (xi)
- **Layer 10+Shift:** Ξ (Xi)
- **Layer 11 (UNICODE_LEFT_NAV):** ↶ (curved arrow left/undo)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∂ (partial derivative)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** χ (chi)
- **Layer 10+Shift:** Χ (Chi)
- **Layer 11 (UNICODE_LEFT_NAV):** ↓ (down arrow)
- **Layer 11+Shift:** ⇓ (double down arrow)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∇ (nabla/del)
- **Layer 14 (UNICODE_MOUSE):** ⬇ (down arrow)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** δ (delta)
- **Layer 10+Shift:** Δ (Delta)
- **Layer 11 (UNICODE_LEFT_NAV):** ↷ (curved arrow right/redo)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** Δ (delta - uppercase for change)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** --- (no Greek equivalent)
- **Layer 11 (UNICODE_LEFT_NAV):** ✂ (scissors)
- **Layer 12 (UNICODE_RIGHT_NAV):** --- (transparent)
- **Layer 13 (UNICODE_NUMER):** ∅ (empty set)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

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
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** ' (single quote)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⏯ (play/pause)
- **Layer 13 (UNICODE_NUMER):** =UNDR (underline leader - activates capswords-style underline mode using U+0332)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

### Position: Bottom Row, Column 7 (H position)

- **Layer 0 (ALPHA):** H
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Backspace
- **Layer 4 (NUMER):** & (ampersand)
- **Layer 4+RSFT:** § (section sign)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** η (eta)
- **Layer 10+Shift:** Η (Eta)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⌫ (delete backward)
- **Layer 13 (UNICODE_NUMER):** ∧ (logical AND)
- **Layer 13+RSFT:** ∩ (intersection)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

### Position: Bottom Row, Column 8 (M position)

- **Layer 0 (ALPHA):** M
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** PG_DN
- **Layer 4 (NUMER):** ~ (tilde)
- **Layer 4+RSFT:** ≈ (approximately)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** μ (mu)
- **Layer 10+Shift:** Μ (Mu)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⇟ (page down)
- **Layer 13 (UNICODE_NUMER):** ∼ (tilde operator)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

### Position: Bottom Row, Column 9 (G position)

- **Layer 0 (ALPHA):** G
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Delete
- **Layer 4 (NUMER):** _ (underscore)
- **Layer 4+RSFT:** ÷ (division)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** --- (transparent)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** --- (transparent)
- **Layer 10 (UNICODE_ALPHA):** γ (gamma)
- **Layer 10+Shift:** Γ (Gamma)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** ⌦ (delete forward)
- **Layer 13 (UNICODE_NUMER):** _SUB (subscript leader - activates capswords-style subscript mode)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

### Position: Bottom Row, Column 10 (J position)

- **Layer 0 (ALPHA):** J
- **Layer 1 (WASD):** --- (transparent)
- **Layer 2 (LEFT_NAV):** --- (transparent)
- **Layer 3 (RIGHT_NAV):** Print Screen
- **Layer 4 (NUMER):** % (percent)
- **Layer 4+RSFT:** ‰ (per mille)
- **Layer 5 (LEFT_MODS):** --- (transparent)
- **Layer 6 (RIGHT_MODS):** Unicode modifier (tap: sticky, hold: regular)
- **Layer 7 (MOUSE):** --- (transparent)
- **Layer 8 (LEFT_SYSTEM):** --- (transparent)
- **Layer 9 (RIGHT_SYSTEM):** Bluetooth clear
- **Layer 10 (UNICODE_ALPHA):** --- (no Greek equivalent)
- **Layer 11 (UNICODE_LEFT_NAV):** --- (transparent)
- **Layer 12 (UNICODE_RIGHT_NAV):** 📷 (camera)
- **Layer 13 (UNICODE_NUMER):** ‱ (basis point)
- **Layer 14 (UNICODE_MOUSE):** --- (transparent)

**Notes:**
- Unicode modifier activates Layers 10-14 when held

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
- **Layer 8 (LEFT_SYSTEM)** activates when LEFT_NAV (Layer 2) + LEFT_MODS (Layer 5) are held
- **Layer 9 (RIGHT_SYSTEM)** activates when RIGHT_NAV (Layer 3) + RIGHT_MODS (Layer 6) are held

### Unicode Layer Activation

- Hold Z (on LEFT_MODS) or J (on RIGHT_MODS) to activate unicode variants
- Unicode layers mirror the structure of their base layers with thematic unicode replacements:
  - Layer 10 (UNICODE_ALPHA) mirrors Layer 0 with Greek letters
  - Layer 11 (UNICODE_LEFT_NAV) mirrors Layer 2 with navigation symbols
  - Layer 12 (UNICODE_RIGHT_NAV) mirrors Layer 3 with media symbols
  - Layer 13 (UNICODE_NUMER) mirrors Layer 4 with math symbols and transform leaders
  - Layer 14 (UNICODE_MOUSE) mirrors Layer 7 with pointing symbols

### RSFT Behavior

- On Layer 4 (NUMER), RSFT transforms keys via mod-morph behaviors
- On Layer 13 (UNICODE_NUMER), RSFT transforms unicode characters:
  - Logical operators: `∧` → `∩` (AND → intersection), `∨` → `∪` (union)

### Transform Leaders (Layer 13)

Transform leaders use a "capswords-style" sticky behavior:

1. **Superscript (`^`)**: Transforms numbers and some letters to superscripts (x² + y³)
2. **Subscript (`_`)**: Transforms numbers and some letters to subscripts (H₂O)
3. **Fraction (`/`)**: Waits for two number keypresses and outputs corresponding fraction (½, ¾)
4. **Circled (`*`)**: Transforms numbers and letters to circled variants (①②③, ⒶⒷⒸ)
5. **Strikethrough (`-`)**: Adds combining strikethrough character U+0336 (A̶B̶C̶)
6. **Underline (`=`)**: Adds combining underline character U+0332 (A̲B̲C̲)

Leaders remain active until a non-transformable character (excluding space/enter/comma/period) is pressed.

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
