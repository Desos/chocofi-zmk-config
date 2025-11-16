# ZMK Macro Implementation Guide

This document explains how macros are implemented in this keymap, with specific examples and patterns used.

## Overview

Macros in ZMK allow you to define sequences of keypresses and behaviors that execute when a single key is pressed. This is particularly useful for:
- Complex key sequences (like REISUB)
- Combining modifiers with layers
- Automating repetitive typing tasks
- System control sequences

## REISUB Emergency Reboot Macro

### What is REISUB?

REISUB is the Linux "Magic SysRq" emergency reboot sequence. When a Linux system becomes completely frozen and unresponsive, this sequence can safely reboot the system by performing cleanup operations in order:

1. **R** - Switch keyboard from raw mode to XLATE mode
2. **E** - Send SIGTERM to all processes except init (graceful termination)
3. **I** - Send SIGKILL to all processes except init (forceful termination)
4. **S** - Sync all mounted filesystems (flush buffers to disk)
5. **U** - Remount all filesystems read-only (prevent corruption)
6. **B** - Immediately reboot the system

The mnemonic "**R**aising **E**lephants **I**s **S**o **U**tterly **B**oring" helps remember the sequence.

### Implementation

The REISUB macro is defined in the keymap configuration as follows:

```dts
/ {
    macros {
        reisub: reisub {
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            wait-ms = <1000>;  // 1 second delay between keys
            tap-ms = <100>;    // Hold each key for 100ms
            bindings
                = <&macro_press &kp LALT &kp SYSREQ>
                , <&macro_tap &kp R>
                , <&macro_tap &kp E>
                , <&macro_tap &kp I>
                , <&macro_tap &kp S>
                , <&macro_tap &kp U>
                , <&macro_tap &kp B>
                , <&macro_release &kp LALT &kp SYSREQ>
                ;
        };
    };
};
```

### Key Parameters Explained

- **`compatible = "zmk,behavior-macro"`**: Defines this as a standard (zero-parameter) macro
- **`#binding-cells = <0>`**: Indicates this macro takes no parameters
- **`wait-ms = <1000>`**: Sets a 1-second delay between each keypress
  - This is critical - each SysRq command needs time to complete before the next one starts
  - Too short a delay may cause commands to be processed out of order or skipped
- **`tap-ms = <100>`**: Each key is held down for 100ms to ensure it registers properly
- **`&macro_press &kp LALT &kp SYSREQ`**: Holds down Alt and SysRq keys simultaneously
- **`&macro_tap &kp X`**: Taps each letter in the sequence (R, E, I, S, U, B)
- **`&macro_release &kp LALT &kp SYSREQ`**: Releases the modifier keys after the sequence completes

### Alternative: Using PRINTSCREEN

On most keyboards, the SysRq function is accessed via Alt+PrintScreen rather than a dedicated SysRq key. If your system requires this, use:

```dts
bindings
    = <&macro_press &kp LALT &kp PRINTSCREEN>
    , <&macro_tap &kp R>
    , <&macro_tap &kp E>
    , <&macro_tap &kp I>
    , <&macro_tap &kp S>
    , <&macro_tap &kp U>
    , <&macro_tap &kp B>
    , <&macro_release &kp LALT &kp PRINTSCREEN>
    ;
```

### Keymap Binding

Once defined, the macro is bound in the keymap at:
- **Layer 8 (LEFT_SYS)**: D position (bottom row, column 4)
- **Layer 9 (RIGHT_SYS)**: H position (bottom row, column 7)

In the keymap bindings, it's referenced as:

```dts
&reisub
```

### Usage Notes

**⚠️ WARNING: This is a destructive operation!**

- REISUB will forcefully terminate all processes and reboot your system
- Only use this when your system is completely frozen and unresponsive
- All unsaved work will be lost
- The sequence attempts to sync and unmount filesystems safely, but data loss is still possible

**Prerequisites:**

1. **SysRq must be enabled on your Linux system**
   - Check: `cat /proc/sys/kernel/sysrq`
   - Should return a non-zero value (typically `1` or `438`)
   - If disabled, enable with: `echo 1 | sudo tee /proc/sys/kernel/sysrq`
   - To enable permanently, add `kernel.sysrq = 1` to `/etc/sysctl.conf`

2. **Timing considerations**
   - The 1-second delay between keys is intentional
   - Each SysRq command performs significant system operations
   - Rushing the sequence may cause commands to fail or execute out of order

**Alternative sequences:**

Some users prefer different orderings:
- **BUSIER** (reverse order): Useful if you want to reboot immediately without cleanup
- **RSEIUB**: Alternative ordering some find easier to remember

### Testing (Safely)

To test if SysRq is working without rebooting:

1. Try Alt+SysRq+H (or Alt+PrintScreen+H) - should print help to kernel log
2. Check with: `sudo dmesg | tail`
3. You should see SysRq help text in the output

**Do not test the full REISUB sequence unless you intend to reboot!**

## Macro Architecture Patterns

### Activation Modes

ZMK macros support three activation modes:

1. **Tap mode** (`&macro_tap`): Press and release each behavior
   - Default mode for simple keycode sequences
   - Used for the R-E-I-S-U-B letter sequence in REISUB

2. **Press mode** (`&macro_press`): Only press, don't release
   - Used for holding modifiers (like Alt+SysRq in REISUB)
   - Behavior stays active until explicitly released

3. **Release mode** (`&macro_release`): Only release previously pressed behaviors
   - Used to release modifiers at the end of a sequence
   - Must match earlier `&macro_press` calls

### Timing Controls

- **`wait-ms`**: Delay between behaviors in the bindings list
  - Can be set globally for the macro: `wait-ms = <1000>;`
  - Can be changed mid-sequence: `<&macro_wait_time 500>`
  - Default: `CONFIG_ZMK_MACRO_DEFAULT_WAIT_MS` (typically 100ms)

- **`tap-ms`**: How long a tapped behavior is held
  - Can be set globally: `tap-ms = <100>;`
  - Can be changed mid-sequence: `<&macro_tap_time 50>`
  - Default: `CONFIG_ZMK_MACRO_DEFAULT_TAP_MS` (typically 30ms)

### Best Practices

1. **For system control sequences** (like REISUB):
   - Use longer wait times (1000ms) to ensure commands complete
   - Use explicit press/release for modifiers
   - Test thoroughly before relying on them in emergencies

2. **For typing sequences**:
   - Use at least 30-40ms wait and tap times
   - Prevents HID notifications from being grouped and processed out of order
   - Especially important for Bluetooth connections

3. **For long macros**:
   - Be aware of the 64-event queue limit (tap mode uses 2 events per key)
   - Increase queue size if needed: `CONFIG_ZMK_BEHAVIORS_QUEUE_SIZE=512`
   - Maximum 256 bindings per macro due to Devicetree limitations

## Additional Resources

For complete ZMK macro documentation, see:
- `Source/zmk/docs/docs/keymaps/behaviors/macros.md` - Official ZMK macro behavior documentation
- ZMK official docs: https://zmk.dev/docs/behaviors/macros

For Linux SysRq documentation:
- Kernel documentation: https://www.kernel.org/doc/html/latest/admin-guide/sysrq.html
- Wikipedia: https://en.wikipedia.org/wiki/Magic_SysRq_key
