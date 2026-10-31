# Decisions (ADRs)

Each Architecture Decision Record captures one choice: the context, the real alternatives,
what we picked and what that commits us to. Create a new one with `/decision <title>`.

**Rules**
- Numbers are sequential and never reused.
- Once an ADR is `Accepted`, its content doesn't change. To change your mind, write a new
  ADR that supersedes it. The only edit allowed to the old one is setting its status to
  `Superseded by ADR-NNNN`.
- List the rejected options honestly. They stop us (and Claude) from re-suggesting
  something already ruled out.

| ADR | Title | Status | Date |
|---|---|---|---|
| [0001](0001-mcu-rp2040-zero-module.md) | MCU: RP2040-Zero clone as a module | Accepted | 2026-10-28 |
| [0002](0002-switches-gateron-ks33-low-profile.md) | Switches: Gateron KS-33 Low Profile 2.0 | Accepted | 2026-10-28 |
| [0003](0003-encoders-ec11-with-push.md) | Encoders: generic EC11 with push, 20 detents | Accepted | 2026-10-28 |
| [0004](0004-oled-ssd1306-i2c.md) | Display: 0.96" SSD1306, I2C, 4-pin | Accepted | 2026-10-28 |
| [0005](0005-firmware-qmk.md) | Firmware: QMK | Accepted | 2026-10-28 |
| [0006](0006-direct-pin-wiring.md) | Wiring: direct pins, no matrix | Accepted | 2026-10-28 |
| [0007](0007-fab-jlcpcb-2layer-tht.md) | Fab: JLCPCB, 2 layers, at most 100 × 100 mm, THT, hand-soldered | Superseded by 0009 | 2026-10-28 |
| [0008](0008-remapping-via-then-own-app.md) | Remapping: VIA first, own PC app later | Accepted | 2026-10-28 |
| [0009](0009-fab-tht-plus-hand-soldered-1206-leds.md) | Fab: as 0007, plus hand-soldered 1206 LEDs under the switches | Accepted | 2026-10-30 |
| [0010](0010-m3-mounting-holes-at-the-corners.md) | Mounting holes: four M3, one per corner, plated and tied to GND | Accepted | 2026-10-31 |
