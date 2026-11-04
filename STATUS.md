# Status

**Updated:** 2026-11-04 · **Phase:** 2, Prototype · **Step:** 03, Buy the parts (encoders and OLED arriving; LEDs and resistors not ordered), with Rev A already ordered (step 12, early under ADR-0011)

## Next actions
1. Owner: compare the Gerber zip's export time with the last saves of `mini-pdeck.kicad_pcb` and `mini-pdeck.kicad_sch`, and say which commit matches (log 2026-11-04). Then commit (suggested: `hw: Rev A as ordered`) and tag `rev-a` after your OK.
2. Owner: say whether Rev A has any bottom-silkscreen marking. PCBWay asks for an order number there only if one is required (log 2026-11-04).
3. Owner: order the 10 white 1206 LEDs and THT resistors 330 Ω, 220 Ω, 470 Ω, 2.2 kΩ, 4.7 kΩ. Not ordered as of the last record.
4. When the encoders and OLED are on the desk: `/check-part` each (EC11 pin diameter with calipers, OLED Q3/Q10). Then step 04 on **one** RP2040-Zero.
5. Decide whether `docs/phases/04-order-build.md` needs an owner-agreed change for ADR-0011 (log 2026-11-01). Decide whether `CLAUDE.md` hard rule 5 changes from JLCPCB to PCBWay (ADR-0012).
6. Record the keycap model (Q8), then confirm the key pitch (Q5, 19.1 mm provisional). Write the Q1 ADR (soldered switches). Step 07 prep: compare the three RP2040-Zero footprint candidates in `lib/third_party/` with the Waveshare drawing.

## Blockers
- LEDs and resistors not ordered. Q12 (LED forward voltage) cannot be tested without them.
- Rev A's Gerber commit is not recorded (log 2026-11-04). Blocks the `rev-a` tag.
- Q9 (external pull-up value) waits for the bus capacitance, which needs the boards.

## Open questions
| ID | Question | Needed by | How it gets settled |
|---|---|---|---|
| Q2 | Final I2C pins for the OLED | Step 06 | Breadboard test (step 04) |
| Q3 | Does the OLED module have I2C pull-ups on board? | Step 06 | Measure the module on arrival (`parts.md`, DISP1) |
| Q5 | Key pitch for the chosen low-profile keycaps | Step 08 | 19.1 mm provisional (owner, 2026-11-01, `mechanical.md`); confirm with the keycap drawing or a measurement. Depends on Q8 |
| Q6 | Knob height vs keycap height | Step 08 | Stack-up in `mechanical.md` (encoder model: shaft top 26.6 mm above the PCB) |
| Q7 | Case approach, including OLED support (board mounting holes settled: ADR-0010) | Step 08 | ADR. Inputs: `mechanical.md`, "Inputs for the case decision" |
| Q8 | Exact keycap model and link | Now | Owner fills in `parts.md` |
| Q9 | External I2C pull-up value (2.2 kΩ or 4.7 kΩ) | Step 06 | Measured bus capacitance and the SSD1306 tr limit (`parts.md`, DISP1) |
| Q10 | Is the received OLED the listing's module (QWORK WD46221; photos show HW-239)? Which address pad is bridged? | Step 04 | Inspect the received module |
| Q11 | Step 05 heading still says "do the tutorial". Reword it? | Now | Owner decision (log 2026-10-29, Session 6) |
| Q12 | White LED forward voltage: 3.5 V or 2.2 V (listing contradicts itself)? Can a 3.3 V GPIO drive it? | Step 08 | Bench test on arrival (`parts.md`, D1–D4); if about 3 V or more, 5 V + transistor (ADR-0009 "Revisit if") |
| Q13 | `docs/phases/03-design.md` step 06 says "optional 4.7 kΩ" pull-ups; Q9 may pick 2.2 kΩ. Reword to "value from Q9"? | Step 06 | Owner agreement (phase file change, log 2026-10-30) |

## Steps
- [x] 01 Lock the spec
- [x] 02 Pick switches and mounting (footprint family fixed; soldered, Q1 answered, ADR pending)
- [~] 03 Buy the parts (Amazon parts in transit, ordered 2026-10-28; encoders and OLED arriving 2026-11-04, owner; LEDs and resistors not ordered)
- [ ] 04 Breadboard and flash firmware
- [x] 05 Install KiCad 10 and do the tutorial (gate passed 2026-10-29 under the narrowed criterion; log Session 5)
- [~] 06 Draw the schematic (draft, ERC 0 errors, 1 warning: DISP1 `lib_symbol_mismatch`, fix pending owner; pins not yet breadboard-confirmed)
- [ ] 07 Verify every footprint (candidates recorded in `parts.md`; needs the real parts; EC11 pad drills changed to 1.2 mm for Rev A, not measured)
- [~] 08 Place the parts (draft: 69.8 × 69.1 mm outline, M3 corner holes per ADR-0010; key pitch 19.1 mm provisional; footprints not yet verified)
- [~] 09 Route and pour ground (draft: all nets routed on F.Cu, GND pour both layers, DRC clean 2026-10-31; will change after 07/08)
- [~] 10 Run the pre-order checks (brought forward by ADR-0011; checklist in `fabrication.md` still open; Rev A ordered before it was run)
- [ ] 11 Get a design review
- [~] 12 Export and order (Rev A ordered 2026-11-03, PCBWay order YR1841165, ADR-0012; commit not recorded)
- [ ] 13 Assemble and test

Legend: `[x]` done · `[~]` in progress · `[ ]` not started. Exit criteria for each step are in `docs/phases/`.
