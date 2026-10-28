# Phase 4: Order & build (steps 12–13)

**Goal:** order the board, then bring it up one part at a time.

## 12 Export and order
- Generate the Gerber and drill files with `/pre-order` and check them in JLCPCB's online Gerber viewer.
- Order: 2 layers, 5 boards (settings in `fabrication.md`). **The owner places the order.**
- Tag the exact commit you ordered: `git tag rev-a`. Record the order in `fabrication.md`.
- **Exit criterion:** order placed, commit tagged, order recorded.

## 13 Assemble and test
- While the boards ship, design the case (`case/`, STATUS Q7).
- Follow `docs/hardware/bring-up.md`: check the bare board, then solder and test in stages.
  Don't solder everything and hope.
- **Exit criterion:** every key, every encoder (both directions plus push) and the OLED pass the
  tests in `bring-up.md`. Results are reported by the owner and logged.

## After v1: retrospective
Write a log entry titled "Rev A retrospective" covering what went wrong, what you would change,
and the list of changes for Rev B. Possible v2 directions: a bare RP2040 with JLCPCB assembly,
or your own remapping app (ADR-0008).

## Pitfalls
- Soldering every part before testing the MCU. If the MCU is mounted wrong, you've wasted the other parts.
- Ordering from an uncommitted working copy, so you can never be sure what you ordered.
