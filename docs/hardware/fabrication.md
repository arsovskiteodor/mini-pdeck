# Fabrication: JLCPCB

## Order settings (Rev A)
| Setting | Value |
|---|---|
| Layers | 2 |
| Material | FR4 |
| Thickness | 1.6 mm |
| Quantity | 5 (minimum) |
| Size | at most 100 × 100 mm (outline from Edge.Cuts) |
| Surface finish | HASL lead-free |
| Copper weight | 1 oz |
| Solder mask colour | Owner's choice (check that it doesn't add cost or build time) |
| Assembly (PCBA) | No: everything is hand-soldered by the owner. All parts are through-hole except the four 1206 LEDs D1–D4 (ADR-0009) |
| Order-number marking | Choose "specify location" and place JLCPCB's placeholder text on the back silkscreen, or accept their default placement. **Check the current option names on the order page.** |

## Project design rules (conservative)
These rules are deliberately looser than JLCPCB's 2-layer minimums. Before ordering, check them
against JLCPCB's current capabilities page (https://jlcpcb.com/capabilities/pcb-capabilities)
and record the date you checked.

| Rule | Value |
|---|---|
| Signal track width | ≥ 0.25 mm |
| Power/GND track width | ≥ 0.4 mm |
| Clearance | ≥ 0.2 mm |
| Via | 0.3 mm drill / 0.6 mm diameter |
| THT hole | pin diameter + 0.2–0.3 mm (from the datasheet or caliper) |
| Copper to board edge | ≥ 0.5 mm |
| Silkscreen line / text height | ≥ 0.15 mm / ≥ 1.0 mm |

Capabilities page checked on: TBD

## Pre-order checklist (step 10, run through `/pre-order`)
- [ ] ERC clean (or every remaining item explained in the log)
- [ ] DRC clean with the rules above, schematic parity on
- [ ] Every footprint `verified` in `parts.md`
- [ ] 1:1 paper print with the real parts placed on it (`mechanical.md`)
- [ ] RP2040-Zero orientation correct (mirrored if mounted on the back), USB-C at the edge
- [ ] OLED pin order on the footprint matches the **received** module
- [ ] Silkscreen: K1–K4, ENC1/ENC2, OLED pin labels, board name, revision, date
- [ ] Mounting holes placed and matching the case plan
- [ ] Gerbers checked in JLCPCB's online viewer
- [ ] Design review done (step 11)
- [ ] Commit tagged `rev-a`

## Fab outputs
Generated into `hardware/kicad/production/` (gitignored):
- Gerbers: F.Cu, B.Cu, F.Mask, B.Mask, F.Silkscreen, B.Silkscreen, Edge.Cuts
- Drill: Excellon, plated and non-plated holes
- Zip both for upload.

## Order history
| Rev | Date | Tag / commit | Qty | Cost (boards + shipping) | Notes |
|---|---|---|---|---|---|
| | | | | | |
