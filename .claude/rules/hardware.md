---
paths:
  - "hardware/**"
  - "docs/hardware/**"
  - "case/**"
---

# Hardware rules

- Units are millimetres. Write the unit every time.
- Every dimension, pin position or electrical limit cites its source: a datasheet link and page,
  or a measurement in `docs/hardware/parts.md` (value, method, date). Otherwise write `TBD`.
- Datasheets for "original" parts (Waveshare RP2040-Zero, Alps EC11) are starting points only.
  Our parts are clones or generics; the measured part wins.
- Footprints we use live in `hardware/kicad/lib/minipad.pretty`. Third-party libraries
  (`lib/third_party/`) are never edited; copy first.
- Don't edit `.kicad_sch` or `.kicad_pcb` files by hand. Reading them to review nets or
  placement is fine. Changes are made in KiCad by the owner, unless the owner explicitly asks
  otherwise (settings.json asks before such edits).
- For checks, use `kicad-cli` (ERC, DRC, exports), not visual guesses.
- A pin change updates `docs/hardware/pinout.md`, the schematic and `firmware/qmk/minipad/keyboard.json`
  together. Flag the ones you didn't touch.
- Board constraints (ADR-0007): 2 layers, at most 100 × 100 mm, through-hole only, hand-soldered.
- Watch for: MCU module orientation (mirrored if on the back), OLED pin order from the
  *received* module, USB-C at the board edge, BOOT button access, silkscreen labels for every
  key, encoder and the OLED pins.
