# Parts

**Status flow:** `ordered` → `arrived` → `verified` → `in design`.
`verified` means every item in the part's checklist below has evidence (a measurement or datasheet page).
A footprint may only be finalised from a `verified` part.

## Bill of materials (v1)
| Ref | Part | Qty need / bought | Source | Price | Status | ADR |
|---|---|---|---|---|---|---|
| U1 | RP2040-Zero clone (DUBEUYEW), USB-C, 2 MB flash | 1 / 2 | Amazon | €9.99 (2) | ordered 2026-10-28 | [0001](../decisions/0001-mcu-rp2040-zero-module.md) |
| SW1–SW4 | Gateron KS-33 Low Profile 2.0 Red Silent, linear, 45 gf | 4 / 35 | Amazon | €15.26 (35) | ordered 2026-10-28 | [0002](../decisions/0002-switches-gateron-ks33-low-profile.md) |
| — | Low-profile keycaps, KS-33 compatible: **model TBD (STATUS Q8)** | 4 / TBD | TBD | TBD | TBD | [0002](../decisions/0002-switches-gateron-ks33-low-profile.md) |
| ENC1–ENC2 | EC11, push switch, 20 steps/turn, 6 mm knurled shaft 20 mm, knobs included (Xatgiouy) | 2 / 5 | Amazon | €7.99 (5) | ordered 2026-10-28 | [0003](../decisions/0003-encoders-ec11-with-push.md) |
| DISP1 | 0.96" OLED 128×64, SSD1306, I2C, 4-pin (QWORK) | 1 / 3 | Amazon | €10.55 (3) | ordered 2026-10-28 | [0004](../decisions/0004-oled-ssd1306-i2c.md) |
| R1–R2 | 4.7 kΩ THT, SDA/SCL pull-ups: **fit only if needed** | 0–2 / 0 | TBD | — | not bought | [0004](../decisions/0004-oled-ssd1306-i2c.md) |
| J1 | 4-pin 2.54 mm header for the OLED (check whether it comes with the module) | 1 / ? | TBD | — | TBD | — |
| PCB | JLCPCB 2-layer, 5 boards | 5 | JLCPCB | about $2 + shipping | step 12 | [0007](../decisions/0007-fab-jlcpcb-2layer-tht.md) |

**Tools and consumables (not on the PCB):** breadboard, jumper wires, **data-capable** USB-C cable,
soldering iron, solder, flux, calipers, multimeter.

## Verification checklists (on arrival)
Record every value in the Measurements table, with method and date.

### U1: RP2040-Zero clone
- [ ] Length, width, thickness (with the USB-C connector)
- [ ] Pin pitch along each edge, and spacing between opposite rows
- [ ] USB-C position relative to the board edge
- [ ] Which GPIOs are on edge pads vs bottom pads; compare with Waveshare's pinout
- [ ] Enters `RPI-RP2` mode with BOOT held, and accepts a test UF2
- [ ] Onboard RGB LED on GP16 (from the Waveshare docs; confirm on the clone)

### SW1–SW4: Gateron KS-33
- [ ] Pins: 2 metal pins + centre post; positions match the `siderakb` footprint (1:1 print test)
- [ ] Keycap fits and the travel feels right
- [ ] Height of keycap top above the PCB surface, switch seated (→ `mechanical.md`)

### ENC1–ENC2: EC11
- [ ] 5 pins (A, C, B on one side; 2 switch pins on the other) plus 2 mounting tabs
- [ ] Detents per turn (count them) = 20?
- [ ] Push switch continuity (multimeter)
- [ ] Pin and tab positions match `RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm` (1:1 print test)
- [ ] Shaft top above the PCB; knob height; knob top above the PCB (→ `mechanical.md`)

### DISP1: OLED
- Listing photos (owner screenshots, 2026-10-29; seller not recorded), not measured on the received module:
  front header labels read VCC, GND, SCL, SDA from left to right. The back shows address pads labelled
  0x78 and 0x7A, and chip resistors and capacitors printed R5, R6, R7, R10 and C1 to C9 (values not legible).
  The board is marked "HW-239", but the DISP1 row above says QWORK, so confirm the photos match the ordered module.
- [ ] **Pin order as printed on the module** (no photo in the log yet; see the listing photos above)
- [ ] Works at 3.3 V on the breadboard
- [ ] I2C address (0x3C or 0x3D). SSD1306 §8.1.5 (page TBD): 7-bit `0111100` (0x3C) or `0111101` (0x3D), chosen by the SA0 bit, which the D/C# pin provides. Write address 0x78 / 0x7A. Confirm which pad is bridged on the module.
- [ ] On-board pull-ups? (with power off, measure the resistance SDA→VCC and SCL→VCC). SSD1306 §8.1.5 (page TBD) says SDA and SCL must both be connected to pull-up resistors. If the module has none, we add them on our board, with values from the datasheet's I2C timing, not from memory. The RP2040's internal pulls (50 to 80 kΩ, RP2040 datasheet Table 625, p. 616) are not a substitute: §4.3 (p. 441) says external pull-ups should be on the board, because the internal ones may not be strong enough.
  Sources: NXP UM10204 Rev 7.0, Table 10 (p. 44 of 62: tr max 1000 ns Standard, 300 ns Fast, 120 ns Fast-mode Plus; Cb max 400 pF), §7.1 (p. 50 of 62), example (p. 52 of 62). Equation images were not extracted from the PDF text, so check the formulas by hand. RP2040 datasheet Table 625 (p. 616) and §4.3 (p. 441).
  External pull-up value: **TBD**. Inputs so far: Rp(min) ≈ 0.97 kΩ at VDD 3.3 V (UM10204 p. 52 of 62, VOL 0.4 V at 3 mA); Rp(max) = tr / (0.8473 × Cb) (p. 50 of 62), with Fast-mode tr max 300 ns (p. 44 of 62). Still needed: the bus capacitance Cb (measure it), the SSD1306's own tr limit (its I2C timing table, page TBD), and whether the module's pulls sit in parallel with ours.
- [ ] Module outline, header position, mounting holes (diameter, spacing)
- [ ] Glass top height above the PCB when mounted on the header (→ `mechanical.md`)

## Measurements
| Part | Item | Value | Method | Date | By |
|---|---|---|---|---|---|
| | | | | | |

## Rejected parts (don't re-suggest without new information)
| Part | Why rejected | Date | ADR |
|---|---|---|---|
| Seeed XIAO RP2040 | 11 GPIO is not enough once the OLED and encoder pushes are added | 2026-10-28 | 0001 |
| AYWHP RP2040-Zero 3-pack | Better value, but slower delivery | 2026-10-28 | 0001 |
| Alps EC12E2430 (Diotronic) | 0 detents, no push switch, EC12 footprint | 2026-10-28 | 0003 |
| Diotronic EC11E2020SW | Right type, about 3× the price of the Amazon 5-pack | 2026-10-28 | 0003 |
| Waveshare 0.96" OLED (B) (Diotronic MDIO9092) | SPI by default, 8 pins, 33 × 33.5 mm | 2026-10-28 | 0004 |
| Velleman VMA438 (Diotronic) | €18.45, about 3× a generic module | 2026-10-28 | 0004 |
| KY-040 encoder modules | Breakout boards, can't mount on our PCB (fine for breadboarding) | 2026-10-28 | 0003 |
