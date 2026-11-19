# Parts

**Status flow:** `ordered` → `arrived` → `verified` → `in design`.
`verified` means every item in the part's checklist below has evidence (a measurement or datasheet page).
A footprint may only be finalised from a `verified` part.

## Bill of materials (v1)
| Ref | Part | Qty need / bought | Source | Price | Status | ADR |
|---|---|---|---|---|---|---|
| U1 | RP2040-Zero clone (DUBEUYEW), USB-C, 2 MB flash | 1 / 2 | Amazon | €9.99 (2) | arrived 2026-11-08 (owner) | [0001](../decisions/0001-mcu-rp2040-zero-module.md) |
| SW1–SW4 | Gateron KS-33 Low Profile 2.0 Red Silent, linear, 45 gf | 4 / 35 | Amazon | €15.26 (35) | arrived (date not reported); soldered on Rev A 2026-11-14 (owner). `/check-part` (arrived) not run | [0002](../decisions/0002-switches-gateron-ks33-low-profile.md) |
| — | Keycaps: **LQXQ 143 Low Profile Keycaps, PBT, Shine Through, Black/Blue/White** (ASIN B0H1C8RZP7). Listing says "with Gateron MX Switches", not KS-33: fit on the KS-33 not confirmed (STATUS Q8). Details: "Keycaps" below | 4 / 143 | Amazon.es, https://www.amazon.es/dp/B0H1C8RZP7 | TBD | arrived by 2026-11-19 (date not reported), fitted on SW1–SW4 (owner, 2026-11-19); price TBD; fit checks partly open ("Keycaps" below) | [0002](../decisions/0002-switches-gateron-ks33-low-profile.md) |
| ENC1–ENC2 | **Bourns PEC11L-4115F-S0020** (2026-11-13): low-profile 11 mm encoder, push switch, 20 detents / 20 PPR, 6 mm flatted shaft 15 mm long. Shaft top about 19.6 mm above the PCB (3D model, not measured). EC11 pin pattern; tabs fit the Rev A slots per the 3D model (test-fit). Details: "Candidate replacement" below | 2 / 6 | Farnell, order code 4014824 | €2.34 each excl. VAT; order €31.50 incl. €11.99 delivery and VAT | arrived by 2026-11-19 (date not reported); soldered on Rev A 2026-11-19; both turn and push correctly in QMK (owner). `/check-part` (arrived) not run | [0013](../decisions/0013-encoders-bourns-pec11l-4115f.md) |
| — | Knobs for the PEC11L: 6 mm D-shaft, 4.5 mm across the flat (datasheet p. 2). Low profile; bore depth no more than the shaft above the bushing (L − B = 10 mm). The included EC11 knobs don't fit (knurled) | 2 / 0 | TBD | TBD | not bought | [0013](../decisions/0013-encoders-bourns-pec11l-4115f.md) |
| (spare) | Generic EC11, push switch, 20 steps/turn, 6 mm knurled shaft 20 mm, knobs included (Xatgiouy). Was ENC1–ENC2 until 2026-11-13; kept for the breadboard | 0 / 5 | Amazon | €7.99 (5) | arrived 2026-11-04 (owner) | [0003](../decisions/0003-encoders-ec11-with-push.md) |
| DISP1 | 0.96" OLED 128×64, SSD1306, I2C, 4-pin (QWORK; received board marked HW-239) | 1 / 3 | Amazon | €10.55 (3) | arrived 2026-11-04 (owner) | [0004](../decisions/0004-oled-ssd1306-i2c.md) |
| R1–R2 | THT 1/4 W axial (footprint DIN0207, 7.62 mm pitch), SDA/SCL pull-ups: **fit only if needed** (Q3), value TBD (Q9). Buying 2.2 kΩ and 4.7 kΩ (5 each) to choose on the bench: Fast mode up to about 160 pF and 75 pF bus capacitance (UM10204 formula, see DISP1) | 0–2 / 0 | TBD | — | not bought: owner, 2026-11-10, says not needed (module pull-ups; basis to confirm, Q9) | [0004](../decisions/0004-oled-ssd1306-i2c.md) |
| — | No OLED socket: the module's own male header is soldered into the board (owner, 2026-10-30) | 0 | — | — | — | — |
| D1–D4 | White SMD LED, 1206, under each switch. Candidate: Diotronic LSMD1206B (maker and part number unknown) | 4 / 10 | Diotronic | €0.16 excl. VAT, MOQ 10 | bought 2026-11-10 (owner; shop and exact part to confirm). Soldered on Rev A 2026-11-14; all four light and breathe (owner). Vf not measured | [0009](../decisions/0009-fab-tht-plus-hand-soldered-1206-leds.md) |
| R3–R6 | LED series resistors, THT 1/4 W axial (footprint DIN0207, 7.62 mm pitch), **220 Ω provisional** (owner, 2026-11-10: bright enough from 3V3; 330 Ω not compared yet; GPIO test pending) | 4 / 15 (5 each of 220, 330, 470 Ω) | local shop | — | bought 2026-11-10; **220 Ω fitted** on Rev A 2026-11-14 (owner) | [0009](../decisions/0009-fab-tht-plus-hand-soldered-1206-leds.md) |
| PCB | PCBWay 2-layer, 5 boards | 5 | PCBWay | Quote 2026-11-01: $5.00 boards (24 h build) + $4.52 Global Direct shipping (6–10 business days) = $9.52, excl. customs and VAT. Ordered 2026-11-03: $6.50 boards, $11.91 order total (owner's screenshot, 2026-11-04); details in `fabrication.md`, Order history | ordered (step 12, ADR-0011) | [0012](../decisions/0012-fab-pcbway-instead-of-jlcpcb.md) |

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

**Compared with the Waveshare drawing (2026-11-01, Claude, before ordering Rev A, ADR-0011).** Sources: the wiki's
dimension image (https://www.waveshare.com/w/upload/f/f4/900px-RP2040-Zero-details-size.jpg, top view, mm) and pinout
image (https://www.waveshare.com/w/upload/1/1f/900px-RP2040-Zero-details-7.jpg). Both are for the original, not the clone.

| Item | Waveshare drawing | `minipad` footprint (SnapMagic copy) | Match |
|---|---|---|---|
| Outline | 18.00 × 23.50 mm, corner R1.00 | F.Fab 18.0 × 23.5 mm (x ±9.0, y ±11.75) | yes |
| Pin pitch | 2.54 mm, all three edges | 2.54 mm | yes |
| First pin to the USB-C end | 1.59 mm | 11.75 − 10.16 = 1.59 mm | yes |
| Pin centre to the long edge | 1.38 mm (so rows 15.24 mm apart) | 9.0 − 7.62 = 1.38 mm | yes |
| Bottom row, GP9 to the right edge | 3.92 mm | 9.0 − 5.08 = 3.92 mm | yes |
| Pin order, top view, USB-C up | Left: 5V, GND, 3V3, 29, 28, 27, 26, 15, 14. Right: 0–8. Bottom, left to right: 13, 12, 11, 10, 9 | Same, pad by pad through the schematic symbol | yes (23/23) |
| Onboard WS2812 | GP16, bottom-side only | not on a footprint pad | — |

- The bobu01 footprint (independent source) agrees with this one on all 23 pads, rotated 90°.
- On the board: U1 on F.Cu, not rotated, USB-C end toward the top edge; module outline 0.15 mm inside the board edge.
  U1's nets match `pinout.md`. The module's bottom pads (GP17–GP25, GND) face our board; the 16 GND vias under it
  are tented on both sides (board setting).
- Not settled by the drawing: drill size (1.0 mm here, 0.8 or 1.0 mm in bobu01) depends on the header pins used, and
  the clone's dimensions. The footprint stays a candidate until the clone is measured (checklist below).

**Owner decision, 2026-11-08:** no ruler measurements of pin pitch or row spacing. The pin geometry is checked by
test-fitting the module (with headers) into Rev A's U1 before soldering. Pins must pass all 23 holes without bending.

- [ ] Length, width, thickness (with the USB-C connector). PCB only: 23 × 18 mm, ruler (Measurements); USB-C overhang
  and thickness TBD, needed for the case (Q7)
- [ ] Pin pitch along each edge, and spacing between opposite rows (by the Rev A test fit, see above)
- [ ] USB-C position relative to the board edge
- [ ] Which GPIOs are on edge pads vs bottom pads; compare with Waveshare's pinout
- [x] Enters `RPI-RP2` mode with BOOT held, and accepts a test UF2 (reported by owner, 2026-11-11). `INFO_UF2.TXT`:
  `UF2 Bootloader v3.0`, `Model: Raspberry Pi RP2`, `Board-ID: RPI-RP2`. The `minipad` QMK firmware runs, so the
  clone's flash works with QMK's default second-stage bootloader (W25Q080-compatible, `docs/platformdev_rp2040.md`
  in QMK); no `RP2040_FLASH_*` define needed. Flash chip part number not identified.
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
- **Visible model since 2026-11-16 (owner's request):** a third-party FreeCAD model,
  `lib/3d/Gateron_KS-33_v3_FreeCAD.step` (source and licence TBD, `datasheets/README.md`), offset (0, 0, +2.5) mm,
  no rotation. The official model above stays in the footprint, hidden. The FreeCAD model is simplified: pin 2
  sits at Y = 5.375 mm instead of 5.75 mm and is a flat blade, not round; stem top 9.55 mm above the PCB vs 8.90 mm
  (log 2026-11-16). Use it for renders only; the numbers below come from the official model.
- **From the 3D model, not measured** (Z = 0 is the PCB top, after the −3.25 mm offset): the switch stands on
  four corner feet; the housing base is 0.30 mm above the PCB; the top is 8.90 mm above the PCB. The centre post
  reaches 3.25 mm below the PCB top, and the terminal tips about 2.5 to 2.65 mm below. With a 1.6 mm PCB that is
  about 1.65 mm (post) and about 1.0 mm (terminals, untrimmed) below the board's underside.

- [ ] Pins: 2 metal pins + centre post; positions match the footprint above (1:1 print test). Waiting for
      the parts (ordered 2026-10-28)
- [ ] Centre post and terminal length below the PCB, with calipers (→ `mechanical.md`, underside row)
- [ ] Keycap fits and the travel feels right
- [ ] Height of keycap top above the PCB surface, switch seated (→ `mechanical.md`)

### Keycaps: LQXQ low-profile PBT shine-through (ASIN B0H1C8RZP7)
**Candidate check, 2026-11-16 (listing and seller photos only):**
- **Listing claims:** low profile ("only half as tall as other keycaps"), double-shot PBT, shine-through (title),
  fits "all key switches with a cruciform shaft", "with Gateron MX Switches (Not ISO Compatible)". 143 keys,
  ANSI US. No dimensions given (width, height, skirt depth). KS-33 / Gateron Low Profile 2.0 is not named.
- **Seller photos:** shown on full-height MX switches. Underside photo: MX cross socket in a round boss;
  translucent inner body inside a black outer shell (double-shot shine-through construction).
- **Owner's switch photo (2026-11-16):** the KS-33 stem top is a round red disc with an MX "+", the "pill"
  noted under SW1–SW4 above. The cap's cross socket matches it.
- **Open risk:** the KS-33 has an MX-style stem, but "not every MX keycap will clear the switch housing without
  collisions" (Keeb.io, https://blog.keeb.io/low-profile-keycap-options-what-works-with-what/). Whether this
  cap's skirt clears the KS-33 housing at full travel (3.0 mm, Gateron drawing, see SW1–SW4) is unknown.
  Bought as a test under Amazon.es's 30-day return (owner, 2026-11-16).
- **Width:** unknown. Pitch is 19.1 mm (provisional, Q5), so a 1u cap up to about 19 mm fits.

**Arrival checks (test on one key before fitting all four):**
- [~] Arrived: by 2026-11-19, 1u keys present and fitted on SW1–SW4 (owner); date and count not reported
- [ ] Cross socket goes onto the KS-33 stem pushed straight down, without forcing
- [ ] Full travel: bottom-out with the cap feels the same as the bare switch (no earlier, harder or scratchy stop)
- [ ] Side view at full press: visible gap between the cap's skirt and the switch housing
- [x] Shine-through: D1–D4 light the legends, not just a ring around the cap (QMK breathing firmware, dim room): legends lit in the owner's photo (`docs/images/rev-a-running.jpg`, 2026-11-19). The light looks blue in the photo; the LEDs are white, it's the camera (owner)
- [ ] Width, with calipers (→ Q5); adjacent caps don't touch when pressed together at 19.1 mm pitch
- [ ] Keycap top above the PCB, switch seated (→ `mechanical.md`, Q6; same item as under SW1–SW4)
- [ ] Return deadline recorded if any check fails

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
- **Bench test 1, reported by owner, 2026-11-10:** RP2040-Zero 3V3 pin → 220 Ω → LED → GND, LED held on jumper wires.
  Lights, "pretty bright" (owner, bare LED, room light, photo). So Vf < 3.3 V at this current; the listing's 3.5 V
  looks wrong, but Vf is **not measured** (no multimeter reading) and Q12 stays open for the number. Looks bluish
  in the photo; colour to the eye not confirmed. Not yet tested: 330 Ω and 470 Ω, under a switch, from a GPIO
  (output high ≥ 2.62 V at 4 mA drive, so expect it dimmer on the board).
- **R3–R6 = 220 Ω, provisional (owner, 2026-11-10),** replacing 330 Ω. Safe whatever the Vf: at most
  (3.3 − 2.2) V / 220 Ω = 5 mA per LED with the listing's lower Vf, 20 mA for four, under the 50 mA total. May
  change to 330 Ω after the under-switch / GPIO test.
- **Bench test 2, reported by owner, 2026-11-11:** GPIO drive. RP2040-Zero GP9 → 220 Ω → LED → GND, `minipad` QMK
  firmware. Steady (GP9 driven high): lights. PWM (QMK backlight, slice 4 channel B, breathing): fades smoothly.
  Brightness at full duty, bare LED: "perfect, very bright", leaves an afterimage when stared at (owner). So a 3.3 V
  GPIO drives it well at 220 Ω; the 5 V + transistor fallback (ADR-0009 "Revisit if") is not needed for brightness.
  Vf and current still **not measured**. 220 Ω may be brighter than needed: compare 220/330/470 Ω under a real
  switch at full duty and pick the brightest level actually wanted (PWM dims below it).
- **Rev A, reported by owner, 2026-11-14:** D1–D4 hand-soldered, R3–R6 = 220 Ω (the 220/330/470 Ω comparison
  under a switch was not done). All four light and breathe under the switches. On the board pad 1 (cathode) goes to
  GND (`mini-pdeck.kicad_pcb`, all four at 0°), so lighting proves the cathode is on pad 1. Not yet reported: which
  end of the part (green mark or not) went on pad 1, and whether each LED was lit before its switch went on.

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
| Pin hole | 5 × Ø1.2 mm | drill 1.2 mm, pad Ø2.0 mm (was 1.0 mm stock; changed 2026-11-01, owner, ADR-0011) | yes |
| Mounting tabs | slots 1.8 × 2.2 mm, 12.2 mm over the outer edges (so about 10.4 mm centre to centre) | oval drill 2.8 × 1.5 mm, 11.2 mm centre to centre | **differs** |

**3D model (2026-10-30):** KiCad's stock model for this footprint is not installed (no `Rotary_Encoder.3dshapes` in
KiCad 10.0.4). Stand-in: Bourns PEC11R-4220F-S0024 (from the owner's ProdDeck project, via a community "Adafruit
PEC11R" KiCad repo; licence not stated), copied to `hardware/kicad/lib/3d/Bourns_PEC11R-4220F-S0024.step` (gitignored).
Same pin pattern as our footprint (2.5 mm pitch, 14.5 mm between rows, from its own footprint). Height from its
vertices: shaft top 26.6 mm above the PCB, pins 3.2 mm below, about 29.8 mm overall, against the listing's 30 mm.
Differences: Bourns body and a flatted shaft instead of our knurled one. Placed with offset (7.5, −2.5, 0) mm and
rotation Z −90°; checked with `kicad-cli pcb render` on a test board (pins in the holes, tabs in the slots, body on
the board). Our footprint copy differs from KiCad stock in this model line and, since 2026-11-01, in the five pin
drills (1.0 → 1.2 mm, owner's choice before ordering Rev A, ADR-0011: a larger hole also takes a thinner pin).
**2026-11-13: the footprint's model is now the Bourns PEC11L-4115F-S0020** (see the candidate below). The PEC11R file
stays in `lib/3d/` but nothing uses it.

The pin pattern and pin hole agree with the drawing; the tab slots don't (left as stock for Rev A, owner,
2026-11-01). Ours is a generic clone, so the real encoder decides: measure the pin cross-section (hole = pin + 0.2 to
0.3 mm, `fabrication.md`) and the tab width, thickness and spacing, then adjust our copy if needed.

- Received 2026-11-04 (owner's photos): knurled split shaft on a threaded bushing. The pins are **flat blades**, not
  round, so what must pass the round 1.2 mm drill is the blade diagonal, √(width² + thickness²): TBD (Q14, closed 2026-11-13: this EC11 is no longer fitted, ADR-0013). Owner
  checked spacings with a ruler (0.5 mm resolution at best) and reports they match the footprint; no numbers recorded.
  Tab spacing (the item marked **differs** above) not yet measured. Test-fit on the Rev A board before soldering.
- [x] 5 pins (A, C, B on one side; 2 switch pins on the other) plus 2 mounting tabs (visual, owner's photos, 2026-11-04)
- [x] Detents per turn: **20** (owner, counted by hand, 2026-11-04)
- [x] Rotation and push switch: "the EC11 works" (owner, 2026-11-05), one encoder on a Pro Micro with
  `firmware/bench/encoder_test_promicro/` (A → D0, C → GND, B → D1, switch → D4 and GND, internal pull-ups). So the
  middle pin is the common pin on this clone. Not recorded: edges per detent (QMK `resolution`), which sign is
  clockwise, the `bad` (bounce) count, and the second encoder.
- [x] Push switch on the RP2040 in QMK: ENC1's S1/S2 wired as K1 (S1 → GP2, S2 → GND, A/B/C unconnected), one press
  types one `a` (reported by owner, 2026-11-11). Rotation not yet tested in QMK.
- [ ] Pin and tab positions match `RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm` (1:1 print test)
- [ ] Shaft top above the PCB; knob height; knob top above the PCB (→ `mechanical.md`)

**Replacement, check 2026-11-13: Bourns PEC11L-4115K-S0020, ordered as the flatted PEC11L-4115F-S0020** (bullets below).
Lower shaft for Q6. Decided in ADR-0013 (supersedes ADR-0003).
- Code (datasheet p. 1, "How To Order"): 4 = rear-facing PC pins (vertical), 1 = 20 detents / 20 pulses, 15 = 15.0 mm
  shaft, K = metal knurled (18 teeth, p. 2), S = push momentary switch, 0020 = 20 pulses.
- Pins (p. 2, PCB layout): A–C–B 2.5 mm pitch (A to B 5.0 mm), switch pins 5.0 mm apart, 7.5 + 7.0 = 14.5 mm between
  rows: **matches** our footprint. Recommended hole 1.0 +0.2/−0 mm; our 1.2 mm drill is at the top of that range.
- Tabs (p. 2): recommended holes 12.8 mm apart against **11.2 mm** on our footprint. The Bourns 3D model (below)
  shows why that isn't a mismatch: the tab legs sit at 5.5–5.97 mm from the shaft axis (11.0–11.9 mm apart), inside
  our slots (4.85–6.35 mm). Only the snap-in barbs, which reach 6.92 mm below the board, have to flex about 0.6 mm
  to pass. The datasheet's wider holes give the barbs clearance. **Model, not measurement:** test-fit before soldering.
- Height (p. 2, side view, Claude's reading of the drawing): 4.5 mm body + L 15 ± 0.5 mm ≈ **19.5 mm** shaft top above
  the PCB, about ±1 mm. Exposed shaft above the bushing: L − B = 15 − 5 = 10 mm (20 mm part: 13 mm), so the knob bore depth matters.
- Datasheet notes: "Hand Soldering: Not recommended" (p. 1); contact bounce 10 ms max at 60 RPM (p. 1); rotational
  and switch life 100,000 cycles (p. 1).
- Listing: DigiKey ES 118-PEC11L-4115K-S0020-ND, Active, 1,026 in stock, €2.44 (1) / €2.094 (5) before VAT;
  shipping €25 under €75 (page fetched 2026-11-13). The listing gives no shaft length; the datasheet wins.
- Listing: RS ES 854-499, manufacturer part number PEC11L-4115K-S0020, title "20 Pulsos, eje de 6 mm Moleteado"
  (owner's screenshot, 2026-11-13). Bag of 5 at €1.982 each = €9.91, delivery €8.00 (free over €95), VAT €3.76,
  **total €21.67**. **Out of stock ("Agotado temporalmente"), delivery 2027-03-18** (owner's cart screenshot,
  2026-11-13). The product photo shows the series (flatted and knurled, longer shafts), not this part.

- 3D model (2026-11-13): Bourns STEP from the SamacSys library zip for PEC11L-4115F-S0020 (Part ID 903309, model
  file `pec11l-4x15f-sxxxx`, SolidWorks 2022, inch units), copied to
  `hardware/kicad/lib/3d/Bourns_PEC11L-4115F-S0020.step` (gitignored: the SamacSys licence forbids redistributing
  the models as library components). Measured from the model's vertices: seating plane to shaft tip **19.6 mm**,
  pins 3.55 mm below the seating plane, A–C–B 7.5 mm and switch pins 7.0 mm from the shaft axis. Attached to
  `RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm` with offset (7.5, −2.5, 12) mm and rotation (90, 0, 90)°, replacing
  the PEC11R stand-in. Checked with `kicad-cli pcb render` on a scratch copy of the board: body on the board, pins
  centred in the pads, tabs inside the slots.
- Flatted variant **PEC11L-4115F-S0020** (same code except F = metal flatted shaft, so it needs D-shaft knobs):
  4,197 in stock, €2.34 (1), order code 4014824 (owner's screenshot, 2026-11-13; shop not named, probably
  Farnell; shipping TBD). Same pins, tabs and height as the K version. **Ordered** from Farnell 2026-11-13: 6 pcs,
  UK warehouse, expected 2026-11-18 (owner's checkout screenshot).

**PEC11L-4115F-S0020 checks on arrival:**
- [ ] Part number on the bag and the Bourns marking; date/lot code (datasheet p. 1: use within 6 months of delivery)
- [ ] Shaft length and flat: 15 mm, D-flat (datasheet p. 2)
- [x] Pins pass the Rev A 1.2 mm drills; tabs and barbs enter the 1.5 × 2.8 mm slots (test-fit, unsoldered): entered without forcing (owner, 2026-11-19; Q16)
- [ ] Shaft top above the PCB when seated (model: 19.6 mm) → `mechanical.md`
- [x] Rotation in QMK: one step per detent, direction, no skipped or doubled steps (contact bounce up to 10 ms, p. 1): one turn = 20 on the OLED counter, clockwise counts up, both encoders, `resolution` 4 (owner, 2026-11-19)
- [x] Push switch on its GPIO: ENC1 (GP8) Mute, ENC2 (GP28) Enter (owner, 2026-11-19)
- [ ] Knob (D-shaft) seats without touching the bushing, and the push still clicks with the knob on

**Other low-profile candidates, not bought (check 2026-11-13).** All have the same pin pattern: A–C–B at 2.5 mm, switch
pins 5 mm apart, rows 7.5 + 7 = 14.5 mm. Heights are Claude's reading of the drawings, about ±1 mm.
- **TT Electronics EN11-HSM1AF15** (datasheet Issue D 10/2021, p. 2 ordering code, p. 3 EN11-HSM drawing): H = top
  adjust (vertical), S = switch, M = threaded bushing, 1 = 20 detents / 20 PPR, A = 5 mm bushing, F = flatted shaft,
  15 = L. Tabs **11.1 ± 0.05 mm** apart (ours 11.2 mm: match), hole 1.8 × 2.6 mm; pin holes Ø1.1 +0.1. Body 6.6 mm,
  so the shaft top is about 21.6 mm. **Flatted shaft: needs D-shaft knobs.** DigiKey ES: 2,253 in stock, €3.92 (1)
  (page fetched 2026-11-13). The knurled EN11-HSM1AQ15 has no stock and a 34-week lead time.
- **Same Sky ACZ11BR1E-15KQD1-20C** (datasheet 05/07/2026, p. 1 part number key, p. 2 shaft table, p. 4 vertical
  drawing): switch, bushing 1 = M7 × 0.75 (H = 5), 15 mm knurled (KQ), D = vertical, 20C = 20 PPR / 20 detents. Tabs
  **9.4 mm** apart, hole 1.8 × 2.1 mm (ours 11.2 mm: **no match**); pin holes Ø1.2. Body 6.5 mm, so the shaft top
  is about 21.5 mm. Hand soldering allowed: 350 °C max for 3 s (p. 1). DigiKey ES: 207 in stock, €4.00 (1).

### DISP1: OLED
- Listing photos (owner screenshots, 2026-10-29; seller not recorded), not measured on the received module:
  front header labels read VCC, GND, SCL, SDA from left to right. The back shows address pads labelled
  0x78 and 0x7A, and chip resistors and capacitors printed R5, R6, R7, R10 and C1 to C9 (values not legible).
  The board is marked "HW-239", but the DISP1 row above says QWORK, so confirm the photos match the ordered module.
- Received module (owner's photos, 2026-11-04): back marked **HW-239**, the same board as in the listing photos.
  Address-select resistor on the 0x78 pads, 0x7A pads empty (as far as the photo shows). R5–R10 appear to read
  "472" (4.7 kΩ) in the photo; which nets they sit on is not visible. Regulator U2 (SOT-23): marking not legible, TBD.
- [x] **Pin order as printed on the module:** VCC, GND, SCL, SDA, left to right from the front, header at the top
  (owner's photo, 2026-11-04). Matches schematic DISP1/J1 pins 1–4.
- [x] Works on a bench test, at **5 V** VCC: Pro Micro (ATmega32U4, 5 V/16 MHz, enumerates as Arduino Leonardo),
  sketch `firmware/bench/oled_test_promicro/`, SDA → D2, SCL → D3. Pings ACK every second, 0 NACKs (serial log,
  2026-11-04). Picture clean, box visible on all four edges, no sideways shift (owner, 2026-11-04): consistent with
  an SSD1306 driving a 128×64 panel. Animation demo `firmware/bench/oled_demo_promicro/` runs at about 17 fps (UI
  mock-up) to 25 fps (simple scenes) at the library's 400 kHz I2C (serial log, 2026-11-04).
- [ ] Works at 3.3 V on the breadboard (step 04, RP2040-Zero)
- [x] I2C address: **0x3C** (7-bit), found by the I2C scan and pinged every second (serial log, 2026-11-04). Agrees with
  the resistor on the 0x78 pads (0x78 = 0x3C × 2, the 8-bit write address). Background: (0x3C or 0x3D). SSD1306 §8.1.5 (page TBD): 7-bit `0111100` (0x3C) or `0111101` (0x3D), chosen by the SA0 bit, which the D/C# pin provides. Write address 0x78 / 0x7A. Confirm which pad is bridged on the module.
- [x] On-board pull-ups: **yes, functional evidence** (2026-11-04). With the AVR's internal pull-ups switched off after
  init (`DISABLE_INTERNAL_PULLUPS 1`), the OLED still ACKed every ping, 0 NACKs. Something on the bus holds SDA/SCL
  high; the module is the likely source. The owner found no resistors on the Pro Micro's D2/D3 (visual, 2026-11-04),
  so the module is the only source. Value and rail (VCC pin or U2 output) not measured: no multimeter yet. Photo suggests 4.7 kΩ.
  Original check, still the way to get the value: (with power off, measure the resistance SDA→VCC and SCL→VCC). SSD1306 §8.1.5 (page TBD) says SDA and SCL must both be connected to pull-up resistors. If the module has none, we add them on our board, with values from the datasheet's I2C timing, not from memory. The RP2040's internal pulls (50 to 80 kΩ, RP2040 datasheet Table 625, p. 616) are not a substitute: §4.3 (p. 441) says external pull-ups should be on the board, because the internal ones may not be strong enough.
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
- [x] Module's male pins: already soldered to the module, plastic spacer on the back (owner's photo, 2026-11-04)
- [ ] Header pitch 2.54 mm and pin diameter (calipers), to confirm the 1.0 mm drill
- [ ] Module outline, header position, mounting holes (diameter, spacing), for our own footprint and the case
- [ ] Glass top height above the PCB when mounted on the header (→ `mechanical.md`)

## Measurements
| Part | Item | Value | Method | Date | By |
|---|---|---|---|---|---|
| ENC1–ENC2 | Pin and tab spacing vs footprint | "match" (no numbers recorded) | Ruler | 2026-11-04 | Owner |
| ENC1–ENC2 | Pin shape | Flat blades, not round | Photo | 2026-11-04 | Owner |
| ENC1 | Rotation and push switch | Work (details not recorded) | Pro Micro bench sketch | 2026-11-05 | Owner |
| DISP1 | Pin order | VCC, GND, SCL, SDA (front, left to right) | Photo | 2026-11-04 | Owner |
| DISP1 | I2C address | 0x3C (7-bit) | I2C scan, Pro Micro bench sketch | 2026-11-04 | Claude (serial log), owner wired |
| DISP1 | On-board pull-ups | Present (value TBD) | Bus works with AVR internal pull-ups off, 0 NACKs | 2026-11-04 | Claude (serial log), owner wired |
| U1 | PCB outline, length × width (USB-C overhang **not** included) | 23 × 18 mm, ±0.5 mm (drawing: 23.50 × 18.00 mm; no conflict within ruler resolution) | Ruler | 2026-11-08 | Owner |
| U1 | Bottom-edge holes (opposite USB-C) | 5 present (spacing not measured) | Visual count | 2026-11-08 | Owner |
| U1 | Bootloader | `UF2 Bootloader v3.0`, Model `Raspberry Pi RP2`, Board-ID `RPI-RP2` | `INFO_UF2.TXT` on the `RPI-RP2` drive | 2026-11-11 | Owner |
| D1 | Brightness from GPIO (GP9, 220 Ω, full duty, bare LED) | "Very bright", afterimage when stared at (qualitative) | Eye, QMK firmware | 2026-11-11 | Owner |
| ENC1 | Push switch on RP2040 (as K1 on GP2) | One press = one `a` | QMK firmware, Notepad | 2026-11-11 | Owner |
| D1–D4 | On Rev A, 220 Ω, own PWM breathing (GP9–GP12) | All four light and breathe together | QMK firmware (log 2026-11-14) | 2026-11-14 | Owner |
| SW1–SW4 | On Rev A, direct pins GP2–GP5 | K1–K4 type a, b, c, d on the expected keys | QMK firmware, text editor | 2026-11-14 | Owner |
| DISP1 | On Rev A, I2C0 GP0/GP1, no external pull-ups (RP2040 internal pull-ups on, set by QMK) | Shows text the right way up; press counter updates | QMK firmware | 2026-11-14 | Owner |

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
| PEC11L-4115K-S0020 via RS (854-499) | Right part, but out of stock until 2027-03-18 | 2026-11-13 | 0013 |
| PEC11L-4115F-S0020 via Unikey (Singapore) | Independent reseller; shipping and import costs not shown before paying. Order USO261114036511 left unpaid | 2026-11-13 | 0013 |
| TT EN11-HSM1AF15 | Tabs match the footprint exactly, but about 2 mm taller than the PEC11L; knurled EN11-HSM1AQ15 has no stock | 2026-11-13 | 0013 |
| Same Sky ACZ11BR1E-15KQD1-20C | About 2 mm taller than the PEC11L; tabs 9.4 mm apart (ours 11.2 mm); 207 in stock | 2026-11-13 | 0013 |
| PEC11L-4120F / -4125F | 20 / 25 mm shafts: only 2 mm lower than before, or taller | 2026-11-13 | 0013 |
| LZH-LP 113-key doubleshot ABS keycaps, OEM profile (Amazon.es ASIN B0DG5RH2FK) | Full-height OEM profile for standard MX, not low profile; skirt may collide with the KS-33 housing; defeats the low-profile goal | 2026-11-16 | 0002 |
