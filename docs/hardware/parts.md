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
| R1–R2 | THT 1/4 W axial (footprint DIN0207, 7.62 mm pitch), SDA/SCL pull-ups: **fit only if needed** (Q3), value TBD (Q9). Buying 2.2 kΩ and 4.7 kΩ (5 each) to choose on the bench: Fast mode up to about 160 pF and 75 pF bus capacitance (UM10204 formula, see DISP1) | 0–2 / 0 | TBD | — | not bought | [0004](../decisions/0004-oled-ssd1306-i2c.md) |
| — | No OLED socket: the module's own male header is soldered into the board (owner, 2026-10-30) | 0 | — | — | — | — |
| D1–D4 | White SMD LED, 1206, under each switch. Candidate: Diotronic LSMD1206B (maker and part number unknown) | 4 / 0 | Diotronic | €0.16 excl. VAT, MOQ 10 | candidate: **buy with checks** (forward voltage measured on arrival) | [0009](../decisions/0009-fab-tht-plus-hand-soldered-1206-leds.md) |
| R3–R6 | LED series resistors, THT 1/4 W axial (footprint DIN0207, 7.62 mm pitch), **330 Ω provisional** (confirm with the measured LED forward voltage; also buy 220 Ω and 470 Ω) | 4 / 0 | TBD | — | not bought | [0009](../decisions/0009-fab-tht-plus-hand-soldered-1206-leds.md) |
| PCB | JLCPCB 2-layer, 5 boards | 5 | JLCPCB | about $2 + shipping | step 12 | [0009](../decisions/0009-fab-tht-plus-hand-soldered-1206-leds.md) |

**Tools and consumables (not on the PCB):** breadboard, jumper wires, **data-capable** USB-C cable,
soldering iron, solder, flux, calipers, multimeter.

## Verification checklists (on arrival)
Record every value in the Measurements table, with method and date.

### U1: RP2040-Zero clone
**Footprint (candidate, not verified, 2026-10-30):** `minipad.pretty/MODULE_RP2040-ZERO`, a copy of the SnapMagic
footprint in `lib/third_party/snapmagic-RP2040-ZERO/`, with one change: the Waveshare 3D model
(`lib/third_party/waveshare-RP2040-Zero-3d/RP2040_Zero.stp`) attached at offset (−9, −12, 2) mm. That offset is the
one the owner set by eye in the board on 2026-10-30 (KiCad local history); check it in the 3D view. The model had been
attached to the board's copy only, so it was lost when the board reloaded footprints from the library.
Which footprint to use (SnapMagic, bobu01, or our own) is still step 07, against the Waveshare drawing and the clone.

- [ ] Length, width, thickness (with the USB-C connector)
- [ ] Pin pitch along each edge, and spacing between opposite rows
- [ ] USB-C position relative to the board edge
- [ ] Which GPIOs are on edge pads vs bottom pads; compare with Waveshare's pinout
- [ ] Enters `RPI-RP2` mode with BOOT held, and accepts a test UF2
- [ ] Onboard RGB LED on GP16 (from the Waveshare docs; confirm on the clone)

### SW1–SW4: Gateron KS-33
**Footprint (candidate, 2026-10-30):** `hardware/kicad/lib/minipad.pretty/SW_Gateron_LowProfile_THT.kicad_mod`,
a copy of `siderakb/key-switches.pretty` commit `e7dea70` (licence CERN-OHL-P-2.0). One change: the Gateron 3D
model is attached (see below); copper, holes and outlines are unchanged. Checked against
Gateron drawing DS-02-001-A0, item KS-33H10B050NN-Y24, Rev 2, 2023-01-03, PDF p. 1 (owner's copy; see
`datasheets/README.md`). The PDF has no text layer: values were read from a rendered image of the page.

| Item | Drawing (p. 1) | Footprint (KiCad, top view, Y down) | Match |
|---|---|---|---|
| Centre hole | Ø5.25 mm (PCB layout); bottom post Ø5.05 ±0.05 mm | NPTH Ø5.25 mm | yes |
| Terminal positions | (−2.60, −5.75) and (+4.40, −4.70) mm from centre, bottom view, Y up | pad 2 (2.60, 5.75), pad 1 (−4.40, 4.70) mm | yes, after mirroring the bottom view to the top view |
| LED window ("RGB") | 5.00 × 2.25 mm rectangle (dims 5.00, 3.20, 2.25, 6.30) | F.Fab outline (−3.20, −6.30) to (1.80, −4.05) mm | yes (outline only; the LED D1–D4 sits here, ADR-0009) |
| Terminal hole | Not given for soldering. The Ø3.00 mm holes in the PCB layout are hot-swap clearance holes | Plated, drill 1.50 mm, pad Ø2.50 mm | yes: terminals are about 1.00 × 0.33 mm and 0.29 × 0.49 mm (3D model below), diagonal ≤ 1.05 mm |

- **View direction:** the PCB layout matches the bottom view, which sits right of the side view (third-angle
  projection, as stated on the drawing). The front view gives an independent check: the round terminal
  (Ø1.00 mm) is at +2.60 mm and the flat one at −4.40 mm, the same as the footprint's pads 2 and 1.
- **"3-pin"** on the listing and on Gateron's product page means 2 metal terminals + the centre post.
  The drawing shows two terminals (circuit diagram ① and ②).
- **Terminal size:** the drawing labels one terminal Ø1.00 mm and gives 0.45 mm for the other. Gateron's 3D
  model (below) gives about 1.00 × 0.33 mm (pad 2) and 0.29 × 0.49 mm (pad 1), from its vertex coordinates.
  The largest diagonal is about 1.05 mm, so the 1.50 mm drill leaves about 0.45 mm. Two other footprints agree
  (ai03 `MX_V2`: 1.45 mm drill).
- **Part number:** the drawing is for KS-33H10B050NN-Y24 (operating force 50 ±15 gf). Ours is the Red
  Silent 2.0 at 45 ±15 gf. Travel matches (pre-travel 1.7 mm, total 3.0 mm). Owner's decision (2026-10-30):
  treat them as the same housing.
- **Rejected alternative:** ai03 `MX_V2` `Gateron-KS33-Solderable-1U` (in the owner's ProdDeck project).
  Same pad positions, but NPTH Ø5.10 mm: with the post at Ø5.05 ±0.05 mm that leaves 0 to 0.10 mm.
- **3D model:** Gateron's official KS-33 Low Profile 2.0 model, from https://www.gateron.com/pages/3d
  (archive `GateronKS-33LowProfile20KS33-20230109KS-33-Y313D.rar`, one STEP file, 1 354 657 bytes,
  CRC32 `c07b5433`). Local copy: `hardware/kicad/lib/3d/Gateron_KS-33_LP2.0_KS33-20230109.step` (gitignored,
  no licence stated). The ProdDeck file `Gateron-KS33-Solderable-Body.step` is the same file renamed
  (same size and CRC32). Footprint offset (−60, 0, −3.25) mm, no rotation: the model is centred at X = 60 mm,
  and its pins sit at the footprint's pad positions without rotation.
  **Stem top differs from current photos:** the model and the drawing (p. 1 top view) show the Ø5.70 mm stem
  inside a wide rectangular rail. A product photo from Gateron's site (owner, 2026-10-30; black stem, so possibly
  another colour) shows only a rounded "pill" about half the switch width, with the "+". Treat the model's stem
  and top as approximate. Pins, post, outline and footprint are not affected; keycap fit and height are measured
  on arrival.
- **From the 3D model, not measured** (Z = 0 is the PCB top, after the −3.25 mm offset): the switch stands on
  four corner feet; the housing base is 0.30 mm above the PCB; the top is 8.90 mm above the PCB. The centre post
  reaches 3.25 mm below the PCB top, and the terminal tips about 2.5 to 2.65 mm below. With a 1.6 mm PCB that is
  about 1.65 mm (post) and about 1.0 mm (terminals, untrimmed) below the board's underside.

- [ ] Pins: 2 metal pins + centre post; positions match the footprint above (1:1 print test). Waiting for
      the parts (ordered 2026-10-28)
- [ ] Centre post and terminal length below the PCB, with calipers (→ `mechanical.md`, underside row)
- [ ] Keycap fits and the travel feels right
- [ ] Height of keycap top above the PCB surface, switch seated (→ `mechanical.md`)

### D1–D4: white 1206 LED (ADR-0009)
**Candidate check, 2026-10-30:** Diotronic LSMD1206B, "LED SMD 1206 BLANCO 0.6CD 3.5V",
https://diotronic.com/leds-smd/9442-led-smd-1206-blanco-0-6cd-3-5v. Retailer listing only: no manufacturer,
no part number, no datasheet, no dimensions, no current rating.
- **Contradiction:** the title says 3.5 V; the characteristics list says "Voltaje: 2,2V". At a 3.3 V GPIO this
  decides everything: with 3.5 V the GPIO can't drive the LED; with 2.2 V there is 1.1 V left for the resistor.
- **Missing without a datasheet:** forward voltage at the chosen current and the maximum current. Forward voltage
  is measured on arrival (owner's decision below); the maximum current stays unknown, so keep the LED current low.
- **RP2040 limits** (RP2040 datasheet RP-008371-DS-1, Table 625, §5.5.3.4, p. 616; §5.5.3.5, p. 617): output high
  ≥ 2.62 V at IOVDD 3.3 V while sourcing the drive setting (2, 4, 8 or 12 mA; default 4 mA, p. 612). Sum of all
  sourced GPIO and QSPI current ≤ 50 mA (I_IOVDD_MAX). The drive setting is not a hard limit; the pin voltage drops
  as the load current rises.
- **R3–R6 = 330 Ω, provisional (owner's proposal, 2026-10-30).** Safe whatever the LED: at most 3.3 V / 330 Ω = 10 mA
  per pin, 40 mA for all four, under the 50 mA total. Brightness depends on the forward voltage (Vf):
  Vf 2.2 V gives about 1.3–3.3 mA (output high 2.62–3.3 V); Vf near 3 V gives under 1 mA or nothing; Vf 3.5 V gives
  nothing with any resistor. Confirm on the bench with the real LED; buy 220 Ω and 470 Ω as well to tune brightness.
  If Vf is about 3 V or more, drive the LEDs from 5 V through a transistor each (schematic change; ADR-0009 "Revisit if").
- **Listing drawing** (owner's screenshot, 2026-10-30; generic, not a datasheet): 3.2 × 1.6 mm, 1.1 mm high.
  Cathode (−) at the end with the green "T" mark on the underside. Confirm with calipers on arrival.
- **Fit (from the listing drawing):** body 3.2 × 1.6 mm in the 5.00 × 2.25 mm window. KiCad stock footprints
  (10.0 library): `LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder` pads span 4.40 × 1.75 mm (pads at ±1.4875 mm,
  1.425 × 1.75 mm), leaving 0.30 mm at each end and 0.25 mm at each side; `LED_1206_3216Metric` spans
  4.05 × 1.75 mm. Both fit. Centre the LED on the window: (−0.70, −5.175) mm in the switch footprint's
  coordinates, long axis along X. Height 1.1 mm against about 5.5 mm of room (3D model estimate).
- **Polarity:** KiCad `Device:LED` pin 1 = K and the stock footprints' pad 1 = cathode, so the green-marked end
  goes on pad 1.
- **Footprint:** `hardware/kicad/lib/minipad.pretty/LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder.kicad_mod`,
  an unchanged copy of the KiCad 10.0.4 stock footprint (2026-10-30). 3D model: KiCad's stock
  `LED_1206_3216Metric.step`.
- **Decision (owner, 2026-10-30):** buy, since they are cheap and convenient; measure the forward voltage on arrival
  instead of waiting for a datasheet.

- [ ] Calipers: length, width, height (expect 3.2 × 1.6 × 1.1 mm from the listing drawing)
- [ ] Forward voltage and current from 3.3 V through a known resistor (multimeter across the LED and the resistor)
- [ ] R3–R6 value calculated from the measured forward voltage and the RP2040 GPIO limit
- [x] Footprint: both pads inside the switch's LED window (numbers above; recheck visually in KiCad)
- [ ] Polarity marking on the part matches the listing drawing (cathode = pad 1)
- [ ] Lights at the chosen current from a 3.3 V source, before any switch is soldered over it
- [ ] Switch sits flat over a soldered LED (real switch)

### ENC1–ENC2: EC11
**Footprint (candidate, 2026-10-30):** `minipad.pretty/RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm`, an unchanged
copy of the KiCad 10 stock footprint (based on Alps EC11E). Pads A, B, C, S1, S2 match the `RotaryEncoder_Switch`
symbol. Compared with the SR Passives EC11E20-20P20C-SW drawing (`datasheets/README.md`, PDF p. 2, "Mounting Hole"),
a generic EC11 that matches our listing (shaft L = 20 mm; listing's 30 mm overall = 3.5 mm pins + 6.5 mm body + 20 mm):

| Item | SR Passives p. 2 | Stock footprint | Match |
|---|---|---|---|
| A–C–B pins | 2.5 mm pitch (A to B 5 mm) | 2.5 mm pitch | yes |
| Switch pins (D/E = S1/S2) | 5 mm apart | 5 mm apart | yes |
| Pin row to switch row | 7.5 + 7 = 14.5 mm | 14.5 mm | yes |
| Tab line from the A–C–B row | 7.5 mm | 7.5 mm | yes |
| Pin hole | 5 × Ø1.2 mm | drill 1.0 mm | **differs** |
| Mounting tabs | slots 1.8 × 2.2 mm, 12.2 mm over the outer edges (so about 10.4 mm centre to centre) | oval drill 2.8 × 1.5 mm, 11.2 mm centre to centre | **differs** |

**3D model (2026-10-30):** KiCad's stock model for this footprint is not installed (no `Rotary_Encoder.3dshapes` in
KiCad 10.0.4). Stand-in: Bourns PEC11R-4220F-S0024 (from the owner's ProdDeck project, via a community "Adafruit
PEC11R" KiCad repo; licence not stated), copied to `hardware/kicad/lib/3d/Bourns_PEC11R-4220F-S0024.step` (gitignored).
Same pin pattern as our footprint (2.5 mm pitch, 14.5 mm between rows, from its own footprint). Height from its
vertices: shaft top 26.6 mm above the PCB, pins 3.2 mm below, about 29.8 mm overall, against the listing's 30 mm.
Differences: Bourns body and a flatted shaft instead of our knurled one. Placed with offset (7.5, −2.5, 0) mm and
rotation Z −90°; checked with `kicad-cli pcb render` on a test board (pins in the holes, tabs in the slots, body on
the board). Our footprint copy now differs from KiCad stock in this model line only.

The pin pattern agrees; the pin hole and the tab slots don't. Ours is a generic clone, so the real encoder decides:
measure the pin cross-section (hole = pin + 0.2 to 0.3 mm, `fabrication.md`) and the tab width, thickness and spacing,
then adjust our copy if needed.

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
- Second listing photo (owner, 2026-10-30): front header again VCC, GND, SCL, SDA left to right, VCC on the square
  pad; four corner mounting holes; front marked "DST-015" and "L15"; a second board behind it is marked HW-239.
  Not measured. Schematic J1: pin 1 VCC, 2 GND, 3 SCL, 4 SDA, which matches these photos.
- Listing details (owner's paste and screenshot, 2026-10-30; seller data, not measured): manufacturer QWORK, part
  number WD46221. Module 27.3 × 27.8 mm (which side is which is not stated), active area 21.744 × 10.864 mm,
  pins VCC-GND-SCL-SDA, 3.3 V / 5 V, about 25 mA when on and 1.5 mA when off. Not given: hole diameter, hole
  positions, header position. So the outline is known only roughly, and the holes and header offset are TBD.
- Symbol (2026-10-30): `minipad:OLED_SSD1306_I2C_4pin` in `hardware/kicad/lib/minipad.kicad_sym`, reference DISP.
  Pins 1 VCC, 2 GND, 3 SCL, 4 SDA, at the same positions as `Conn_01x04_Socket`, so it can replace J1 with
  KiCad's Change Symbol without moving wires.
- **Owner's decision (2026-10-30, replaces the female-socket choice made earlier the same day): no socket.** The
  module's own 1×4 male header is soldered straight into four through-holes on our board. Lower and stiffer than a
  socket; replacing a module means desoldering four pins.
- DISP1 footprint (2026-10-30): `PinHeader_1x04_P2.54mm_Vertical` (KiCad 10 stock: 1.7 mm pads, 1.0 mm drill,
  2.54 mm pitch; its 3D model, a header with a plastic spacer, stands in for the module's own pins). The schematic
  and PCB link KiCad's stock `Connector_PinHeader_2.54mm` library, not the identical `minipad.pretty` copy: owner's
  choice (2026-10-31), the one exception to "every footprint in `minipad.pretty`", until our own OLED footprint
  replaces it.
- **Mounting holes: undecided** (owner, 2026-10-30). Options in `mechanical.md`, Q7 inputs.
- [ ] Module's male pins: present or loose in the bag? Solder them to the module first if loose
- [ ] Header pitch 2.54 mm and pin diameter (calipers), to confirm the 1.0 mm drill
- [ ] Module outline, header position, mounting holes (diameter, spacing), for our own footprint and the case
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
