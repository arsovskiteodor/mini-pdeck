# ADR-0008: Remapping: VIA first, own PC app later

- **Status:** Accepted
- **Date:** 2026-10-28
- **Step:** 01 Lock the spec (implementation after step 04)

## Context
The owner wants to change what each key does from a PC program without reflashing.

## Options considered
| Option | For | Against |
|---|---|---|
| Reflash for every change | Simple | Not what the owner wants |
| **QMK dynamic keymap + VIA** | Flash once; the keymap lives in storage on the board; VIA changes it over Raw HID | Custom board needs its own VIA definition file |
| Own app speaking VIA's protocol | Learn host-side USB; the firmware already supports the protocol | Only the PC side is new, but that's still extra work |
| Own Raw HID protocol | Learn the most | Debugging firmware and app at the same time |
| Firmware sends F13–F24; PC app decides | Can behave differently per app | Only works where the app runs |

## Decision
Stage it: (1) enable VIA and prove remapping with the VIA app; (2) write our own PC app
that speaks VIA's protocol; (3) design our own protocol only after (2) works.

## Consequences
- Keymap: `VIA_ENABLE = yes` in the keymap's `rules.mk`, plus an encoder map with as many layers as the dynamic keymap.
- The VIA definition's vendor and product IDs must match `keyboard.json`.
- The default keymap is copied into storage on first boot. Later changes to `keymap.c` won't apply
  until that storage is cleared (`EE_CLR`).
- Only key mappings and simple macros change live. OLED behaviour and new features still need a reflash.
- No effect on the PCB.

## Sources
- VIA docs, Configuring QMK: https://caniusevia.com/docs/configuring_qmk/
