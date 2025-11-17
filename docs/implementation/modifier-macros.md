# Modifier Combination Macros

## Overview

The keymap includes C preprocessor macros for common modifier combinations, making the keymap more readable and maintainable.

## Available Macros

### HYPER(key)

Sends **Super + Alt + Ctrl + Shift + key** (all four modifiers).

**Usage:**
```c
&kp HYPER(A)    // Super+Alt+Ctrl+Shift+A
&kp HYPER(T)    // Super+Alt+Ctrl+Shift+T
&kp HYPER(ESC)  // Super+Alt+Ctrl+Shift+Escape
```

**Common use case:** Window manager keybindings that need to avoid conflicts with applications.

### MEH(key)

Sends **Alt + Ctrl + Shift + key** (all modifiers except Super).

**Usage:**
```c
&kp MEH(A)      // Alt+Ctrl+Shift+A
&kp MEH(F1)     // Alt+Ctrl+Shift+F1
```

**Common use case:** Application-specific shortcuts that shouldn't interfere with window manager bindings.

### HYPER_MODS

Sends **Super + Alt + Ctrl + Shift** without any additional key (standalone modifier hold).

**Usage:**
```c
&kp HYPER_MODS  // Hold all four modifiers
```

**Common use case:** A key that holds HYPER, allowing you to press other keys while it's held.

### MEH_MODS

Sends **Alt + Ctrl + Shift** without any additional key (standalone modifier hold).

**Usage:**
```c
&kp MEH_MODS    // Hold Alt+Ctrl+Shift
```

## Implementation Details

These are **C preprocessor macros**, not ZMK behaviors. They are expanded at compile time:

```c
// Defined in chocofi.keymap header:
#define HYPER(key) LG(LA(LC(LS(key))))
#define MEH(key) LA(LC(LS(key)))
#define HYPER_MODS LG(LA(LC(LSHIFT)))
#define MEH_MODS LA(LC(LSHIFT))
```

Where:
- `LG()` = Left GUI (Super/Windows key)
- `LA()` = Left Alt
- `LC()` = Left Ctrl
- `LS()` = Left Shift

## Examples in Current Keymap

### LEFT_NAV Layer (Layer 2)

The bottom-left key uses `HYPER_MODS`:

```c
&kp HYPER_MODS  // Standalone HYPER modifier
```

This allows you to:
1. Hold ESC (activates LEFT_NAV layer)
2. Press Z position (sends HYPER modifier hold)
3. Press another key to send HYPER+key

## Adding More HYPER/MEH Keys

To add HYPER or MEH combinations to your keymap:

### Example 1: HYPER+Q on a specific key
```c
&kp HYPER(Q)
```

### Example 2: MEH+F for Firefox
```c
&kp MEH(F)
```

### Example 3: Multiple HYPER keys on a layer
```c
left_nav_layer {
    bindings = <
        &kp HYPER(Q)  &kp HYPER(W)  &kp HYPER(E)  ...
        &kp HYPER(A)  &kp HYPER(S)  &kp HYPER(D)  ...
        ...
    >;
};
```

## Why Use Macros Instead of Behaviors?

### Advantages
1. **Compile-time expansion** - No runtime overhead
2. **Simple and reliable** - Just text substitution
3. **Easy to read** - `HYPER(A)` vs `LG(LA(LC(LS(A))))`
4. **No ZMK behavior complexity** - Avoids macro timing issues

### Limitations
1. **Not parameterized behaviors** - Can't be used with hold-tap or other behaviors
2. **Compile-time only** - Can't be changed dynamically

## Comparison with Other Approaches

### ❌ Parameterized Mod-Morph (Not Available Yet)
```c
// This DOES NOT WORK in current ZMK
&hyper A  // Planned feature, not yet available
```

### ❌ ZMK Macros (Can Be Unreliable)
```c
// This can cause timing issues and random characters
hyper: hyper {
    compatible = "zmk,behavior-macro-one-param";
    ...
};
```

### ✅ C Preprocessor Macros (Current Best Practice)
```c
// Clean, reliable, compile-time expansion
&kp HYPER(A)
```

## Niri Integration

These macros work perfectly with Niri's HYPER keybindings:

**Niri config:**
```kdl
Super+Alt+Ctrl+Shift+T { spawn "firefox"; }
Super+Alt+Ctrl+Shift+Space { spawn "kitty"; }
```

**ZMK keymap:**
```c
&kp HYPER(T)      // Launches Firefox
&kp HYPER(SPACE)  // Launches Kitty
```

## Troubleshooting

### Build fails with "undefined reference"
- Make sure the macro is defined **before** the `/ {` devicetree section
- Check that you're using valid ZMK key codes (e.g., `A` not `a`)

### HYPER key doesn't work
- Verify your window manager is configured to listen for Super+Alt+Ctrl+Shift combinations
- Test with `xev` or similar tool to see what's actually being sent
- Check that the key isn't being intercepted by another application

### Want to use HYPER with hold-tap
- This isn't possible with preprocessor macros
- You would need to wait for parameterized mod-morph (ZMK PR #2724)
- Current workaround: Create individual mod-morph behaviors for each key
