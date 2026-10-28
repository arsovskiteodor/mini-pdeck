# Phase 3: Design (steps 05–11)

**Goal:** a schematic and PCB that pass every check, with every footprint verified
against the real part.

## 05 Install KiCad 10 and do the tutorial
- **Exit criterion:** one practice board routed, start to finish, in the official tutorial.
- **Evidence:** a log entry. The practice project stays out of this repo.

## 06 Draw the schematic
- Use the pins confirmed in step 04. Add optional 4.7 kΩ SDA/SCL pull-ups, marked "do not fit".
- Label every net (SDA, SCL, K1…K4, ENC1_A…). Give the switches and encoders clear reference designators.
- **Exit criterion:** ERC passes, and the pins match the breadboard (`pinout.md`).
- **Evidence:** ERC report summary in the log, and the schematic committed.

## 07 Verify every footprint
- Settle STATUS Q1 (hot-swap or soldered) and Q4 (how the MCU is mounted) first, each with an ADR.
- For each footprint, compare it with the datasheet **and** the measured part.
  Print the footprints at 1:1 and set the real parts on the paper.
- Put every footprint we use in `hardware/kicad/lib/minipad.pretty`. Third-party libraries stay untouched.
- **Exit criterion:** every footprint matches its part. Each part is `verified` in `parts.md`.

## 08 Place the parts
- Board outline at most 100 × 100 mm. Key pitch from Q5. Knob clearance from Q6.
- USB-C at the board edge, the RP2040-Zero's BOOT button reachable (or Bootmagic planned),
  and the mounting holes placed.
- **Exit criterion:** outline under 100 × 100 mm, spacing checked with a 1:1 paper print and the real parts.

## 09 Route and pour ground
- Signal traces plus a GND pour on both layers, stitched with vias.
  USB runs on the RP2040-Zero module, so nothing on this board is high-speed.
- **Exit criterion:** no unrouted nets.

## 10 Run the pre-order checks
- Run `/pre-order`.
- **Exit criterion:** DRC is clean with the rules in `fabrication.md`, the 3D view has been checked,
  and the real parts fit on the 1:1 print. Module orientation is checked: it is mirrored if mounted on the back.

## 11 Get a design review
- First the `design-reviewer` agent, then a human review: post the schematic and layout on r/PrintedCircuitBoard.
- **Exit criterion:** every comment is either fixed or rejected with a written reason (in the log).

## Pitfalls
- Drawing a footprint from a product photo. Measure the part instead.
- Editing a footprint inside a third-party library. Copy it into the project library first.
- Silkscreen text over pads, or missing labels for K1–K4 and the OLED pin order.
  You'll be soldering from the silkscreen.
- Forgetting JLCPCB's order-number marking (see `fabrication.md`).
