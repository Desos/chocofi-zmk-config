# Issues with Previous Keymap (chocofi.keymap.broken)

## Date: 2025-11-16

## Symptoms Reported by User

1. **Random `+` characters appearing** - HYPER macro firing incorrectly
2. **HYPER key not working** - Modifier combination not functioning
3. **`sm_ht` and `lt_hp` behaviors not working correctly** - Hold-tap behaviors malfunctioning

## Root Cause Analysis

The broken keymap (`chocofi.keymap.broken`) had several issues:

### 1. Incorrect Behavior Names
- Used `sticky_mod` instead of `sm_ht` (sticky-mod hold-tap)
- Used `lt_hyper` instead of standard `lt_hp` (layer-tap hold-preferred)
- These behaviors had different configurations that didn't work correctly

### 2. HYPER Macro Implementation Issues
- Implemented parameterized HYPER macros throughout the keymap
- Macros were firing incorrectly, causing random `+` characters
- The macro syntax or timing was causing unintended key presses

### 3. Overly Complex Design
- 10 layers instead of 9
- Extensive HYPER macro usage across multiple layers
- More complex mod-morph naming (`num_1_f1` vs `mm_1`)

## Solution

Restored the working session keymap (`chocofi.keymap.working-session`) which has:

### Working Behaviors
- `lt_hp`: Hold-preferred layer-tap (tested and working)
- `sm_ht`: Sticky-mod hold-tap (tested and working)
- Simple, reliable mod-morph behaviors

### Simpler Design
- 9 layers total
- Minimal HYPER usage (only on specific keys)
- Cleaner behavior definitions

## Files

- **Broken keymap**: `config/chocofi.keymap.broken` (saved for reference)
- **Working keymap**: `config/chocofi.keymap` (restored from working session)
- **Working configs**: `config/corne.conf`, `config/chocofi.conf`

## Lessons Learned

1. **Test before committing** - The broken keymap was never tested on hardware
2. **Keep it simple** - Complex macro systems can introduce subtle bugs
3. **Preserve working states** - The working session backup saved us
4. **Behavior naming matters** - Using standard, tested behavior names is safer

## Next Steps

1. Flash the newly built firmware to both keyboard halves
2. Test all layers and behaviors
3. Document any issues that arise
4. Only make incremental changes from the working baseline
