# Fabrication: PCBWay (ADR-0012)

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
| Solder mask colour | Green, white silkscreen (owner, 2026-11-01). Black was quoted at about €14 extra: rejected for Rev A, reconsider for Rev B |
| Assembly (PCBA) | No: everything is hand-soldered by the owner. All parts are through-hole except the four 1206 LEDs D1–D4 (ADR-0012, carried over from ADR-0009) |
| Order-number marking | TBD: PCBWay's capabilities page doesn't mention it. Ask PCBWay whether they add one and where (ADR-0012). |

## Project design rules (conservative)
These rules are deliberately looser than PCBWay's 2-layer minimums. Before ordering, check them
against PCBWay's current capabilities page (https://www.pcbway.com/capabilities.html)
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

Capabilities page checked on: **2026-11-01** (Claude, via the page text; standard 2-layer, 1 oz, 1.6 mm). Every
rule above is at or looser than PCBWay's limit:

| Item | PCBWay (2026-11-01) | This board |
|---|---|---|
| Track width / spacing | min 0.1 / 0.1 mm | 0.25 / 0.2 mm |
| Via | min drill 0.15 mm; **extra charge under 0.2 mm**; via diameter not listed | 0.3 / 0.6 mm |
| Drill range | 0.15–6.0 mm; **extra charge over 6 mm** | 0.8–3.2 mm plated, 5.25 mm non-plated |
| Annular ring | min 0.15 mm | min 0.2 mm (EC11 tab slots, long axis), U1 0.254 mm, the rest ≥ 0.35 mm |
| Pad hole to hole | not listed for standard boards | ≥ about 1.3 mm |
| Copper to board edge | not listed for standard boards (advanced process: 0.25 mm) | ≥ 0.5 mm |
| Silkscreen line / text height | ≥ 0.15 mm / ≥ 0.8 mm | 0.15 mm / 1.0 mm (line width at the limit) |
| Pad to silkscreen | not listed | no silkscreen on pads (DRC copy with silk clearance 0.15 mm, 2026-11-01) |
| Drill tolerance | plated ±0.08 mm, non-plated ±0.05 mm | e.g. 1.0 mm plated → 0.92–1.08 mm; use when matching pins to holes |
| Order number on the board | not mentioned | TBD: ask PCBWay before ordering (ADR-0012) |

Many stock footprints draw silkscreen at 0.12 mm (switch 0.14 mm, U1 0.127 mm), under the 0.15 mm rule; DRC doesn't
check it. Cosmetic only; proposed to accept (design review 2026-11-01, owner to confirm). JLCPCB was also checked on 2026-11-01 (ADR-0012, Sources).

## Pre-order checklist (step 10, run through `/pre-order`)
- [ ] ERC clean (or every remaining item explained in the log)
- [ ] DRC clean with the rules above, schematic parity on
- [ ] Every footprint `verified` in `parts.md`
- [ ] 1:1 paper print with the real parts placed on it (`mechanical.md`)
- [ ] RP2040-Zero orientation correct (mirrored if mounted on the back), USB-C at the edge
- [ ] OLED pin order on the footprint matches the **received** module
- [ ] Silkscreen: K1–K4, ENC1/ENC2, OLED pin labels, board name, revision, date
- [ ] Mounting holes placed and matching the case plan
- [ ] Gerbers checked in a Gerber viewer (PCBWay's, if offered, or KiCad's GerbView) and passed PCBWay's DFM review
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
| A | 2026-11-03 (17:50, PCBWay time as shown) | TBD: commit not recorded, no `rev-a` tag | 5 | $11.91 order total, boards $6.50 (breakdown not shown in the order screenshot) | PCBWay order YR1841165, product W1173661ASX3, file `mini-pdeck-rev-a-gerbers.zip`. Status "In fabrication", 17%, on the screenshot of 2026-11-04. Ordered before step 10 checks (ADR-0011, ADR-0012). |
