# ADR-0013: Encoders: Bourns PEC11L-4115F-S0020 replaces the generic EC11

- **Status:** Accepted
- **Date:** 2026-11-13
- **Step:** 03 Buy the parts
- **Supersedes:** ADR-0003

## Context
ADR-0003 chose a generic EC11 with a 20 mm knurled shaft and noted that a 20 mm shaft is tall next to low-profile
keys (STATUS Q6). The 3D stand-in for that part puts the shaft top at 26.6 mm above the PCB. Our clone hasn't been
measured. The owner wants the knobs lower and asked for an encoder that fits the existing footprint (Rev A is
already ordered, ADR-0011).

What we knew on 2026-11-13 (details and pages in `parts.md`, ENC1–ENC2):
- **Footprint:** `RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm`. A–C–B at 2.5 mm pitch, switch pins 5 mm apart,
  14.5 mm between rows, 1.2 mm drills, tab slots 1.5 × 2.8 mm at 11.2 mm.
- **Pins:** Bourns PEC11L, TT EN11, Same Sky ACZ11 and Bourns PEC11R all use that pin pattern (their datasheets).
  Their recommended tab holes differ: 12.8, 11.1, 9.4 and 13.2 mm.
- **PEC11L tabs:** the 3D model shows the tab legs at 11.0–11.9 mm, inside our slots. Only the snap barbs below the
  board have to flex about 0.6 mm. The datasheet's 12.8 mm is the spacing of wider holes, not of the tabs. This
  comes from the model, not a measured part.
- **PEC11L height:** the 3D model puts the shaft top at 19.6 mm above the PCB, about 7 mm lower than the stand-in.
- ADR-0003 had already considered "Bourns PEC11L, 15 mm shaft". It passed because of the separate distributor order
  and because the pin layout was unconfirmed. The datasheet now confirms the layout; the extra order is accepted
  (see Decision).
- **The Q6 gap (knob top vs keycap top) hasn't been measured.** This decision is made on the expected benefit.

## Options considered
| Option | For | Against |
|---|---|---|
| Keep the generic EC11 (20 mm) and use a lower knob, or cut the shaft | Already owned, works on the RP2040 (2026-11-11), €0 | Shaft top about 26.6 mm (stand-in model). Cutting removes the knurl, which sits at the top of the shaft |
| Generic EC11 with a 15 mm shaft (seller listing) | Same clone family, so its tabs probably match ours; cheapest | Listing only, no datasheet; listing says D-shaft; about 21.5 mm if the body matches ours |
| Bourns PEC11L-4115K-S0020 (knurled) | Lowest (about 19.6 mm); keeps the knurled knobs; 20 detents / 20 PPR | RS: out of stock until 2027-03-18. DigiKey: 1,026 in stock, but €25 shipping under €75, about €43 for 5 |
| **Bourns PEC11L-4115F-S0020 (flatted)** | Lowest (about 19.6 mm); 20 / 20 with push; 100,000-cycle rotation and switch life; Farnell: 4,197 in stock, €31.50 for 6 delivered | Needs D-shaft knobs. Datasheet: hand soldering "not recommended", contact bounce up to 10 ms. Tabs fit per the model only |
| TT EN11-HSM1AF15 | Tabs at 11.1 mm match the footprint exactly; 2,253 in stock (DigiKey) | About 21.6 mm, so 2 mm taller; flatted; DigiKey shipping; the knurled AQ15 has no stock (34 weeks) |
| Same Sky ACZ11BR1E-15KQD1-20C | Knurled, keeps the knobs; hand soldering allowed (350 °C, 3 s) | About 21.5 mm; tabs 9.4 mm (ours 11.2); 207 in stock; DigiKey shipping |
| Bourns PEC11R-4215K-S0024 | Knurled, 15 mm with push | 24 detents, not 20; about 21.5 mm; tabs 13.2 mm |
| PEC11L-4115F via Unikey (Singapore reseller) | Same part, $11.16 for 5 | Shipping and import costs not shown before paying; independent reseller, date code unknown |

## Decision
ENC1–ENC2 become the Bourns PEC11L-4115F-S0020. Six were ordered from Farnell on 2026-11-13 (owner): two for
the board, four spares. The generic EC11s stay on the breadboard.

## Consequences
- **Knobs:** buy D-shaft knobs (6 mm, 4.5 mm across the flat, datasheet p. 2) whose bore is no deeper than the
  10 mm of shaft above the bushing. Q6 now depends on the knob's height.
- **Rev A:** test-fit the pins and snap tabs before soldering (arrival checklist in `parts.md`). If the barbs won't
  pass, bend or trim them.
- **Soldering:** Bourns doesn't recommend hand soldering. Keep each joint short. Accepted risk, since the board
  is hand-soldered (ADR-0012).
- **Firmware:** 20 PPR with 20 detents, the same ratio as before. Confirm one step per detent and the direction in
  QMK with the new part. Watch for bounce (up to 10 ms).
- **Storage:** Bourns says to use the parts within 6 months of delivery (p. 1).
- **Footprint:** keeps its pads and now uses the PEC11L 3D model (gitignored: SamacSys licence). For Rev B, rename
  it, and keep or change the slots depending on the test-fit.
- **No pinout change:** same five functions on the same pads. `pinout.md`, the schematic and `keyboard.json` don't
  change.
- **Q14** (do the EC11's blade pins pass the 1.2 mm drill) no longer applies to the fitted part. The PEC11L's
  recommended hole is 1.0 +0.2 mm, so 1.2 mm is at the top of that range.
- **Q6 stays open.**

## Revisit if
- The PEC11L's pins or tabs don't enter the Rev A holes without more than flexing the barbs.
- QMK shows skipped or doubled steps that debouncing doesn't fix.
- No D-shaft knob fits the 10 mm of exposed shaft and still lets the push switch click.
- For Rev B the PEC11L can't be bought. The fallback is the EN11-HSM1AF15, whose tabs match the footprint.

## Sources
- Bourns PEC11L datasheet, REV. 04/26: https://www.bourns.com/docs/Product-Datasheets/PEC11L.pdf (p. 1 ordering
  code and ratings, p. 2 dimensions and PCB layout)
- Bourns PEC11R datasheet, REV. 07/14: https://static.chipdip.ru/lib/276/DOC012276510.pdf (p. 2)
- TT Electronics EN11 datasheet, Issue D 10/2021: https://cdn.components.ru/media/PDF/622148.pdf (p. 2–3)
- Same Sky ACZ11 datasheet, 05/07/2026: https://sameskydevices.com/product/resource/acz11.pdf (p. 1, 2, 4)
- Alps EC11 catalogue (f5kav.fr copy): https://www.f5kav.fr/wp-content/uploads/simple-file-list/F5RCT/Realisations/Squirrely/Module-PLL/ALPS_EC11.pdf
- 3D model: SamacSys library for PEC11L-4115F-S0020, Part ID 903309. Measurements in `parts.md`, ENC1–ENC2
- Listings, all 2026-11-13: DigiKey ES (PEC11L-4115K, EN11-HSM1AQ15, ACZ11BR1E-15KQD1-20C), RS ES 854-499, Unikey cart,
  Farnell checkout (owner's screenshots)
- ADR-0003 (superseded), ADR-0011, ADR-0012
