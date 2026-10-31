# Status

**Updated:** 2026-10-31 · **Phase:** 2, Prototype · **Step:** 03, Buy the parts (in transit), with a draft schematic (06), placement (08) and routing (09) running ahead

## Next actions
1. Send the supplier list (log 2026-10-30) and order: 10 white 1206 LEDs; THT resistors 330 Ω, 220 Ω, 470 Ω, 2.2 kΩ, 4.7 kΩ (owner).
2. Commit today's work. Then in KiCad: DISP1 Update Symbol from Library without resetting fields (clears the ERC warning), and fill the four DRC exclusion comments (log 2026-10-31).
3. Record the keycap model (Q8), then the key pitch (Q5). Write the Q1 ADR (soldered switches); Q4 waits for the clone.
4. Step 07 prep: compare the three RP2040-Zero footprint candidates in `lib/third_party/` with the Waveshare drawing.
5. When parts arrive: `/check-part` each (calipers, 1:1 prints, LED forward voltage Q12, OLED Q3/Q10, encoder pins and tabs), then step 04 on **one** RP2040-Zero.

## Blockers
- Amazon parts in transit (ordered 2026-10-28). LEDs and resistors not ordered yet.
- Q9 (external pull-up value) waits for the bus capacitance, which needs the boards.

## Open questions
| ID | Question | Needed by | How it gets settled |
|---|---|---|---|
| Q2 | Final I2C pins for the OLED | Step 06 | Breadboard test (step 04) |
| Q3 | Does the OLED module have I2C pull-ups on board? | Step 06 | Measure the module on arrival (`parts.md`, DISP1) |
| Q5 | Key pitch for the chosen low-profile keycaps | Step 08 | Keycap drawing or measurement; depends on Q8 |
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
- [~] 03 Buy the parts (Amazon ordered 2026-10-28; LEDs and resistors to order)
- [ ] 04 Breadboard and flash firmware
- [x] 05 Install KiCad 10 and do the tutorial (gate passed 2026-10-29 under the narrowed criterion; log Session 5)
- [~] 06 Draw the schematic (draft, ERC clean, pins not yet breadboard-confirmed)
- [ ] 07 Verify every footprint (candidates recorded in `parts.md`; needs the real parts)
- [~] 08 Place the parts (draft: rough ~70 × 69 mm outline, M3 corner holes per ADR-0010; key pitch and footprints not yet verified)
- [~] 09 Route and pour ground (draft: all nets routed on F.Cu, GND pour both layers, DRC clean 2026-10-31; will change after 07/08)
- [ ] 10 Run the pre-order checks
- [ ] 11 Get a design review
- [ ] 12 Export and order
- [ ] 13 Assemble and test

Legend: `[x]` done · `[~]` in progress · `[ ]` not started. Exit criteria for each step are in `docs/phases/`.
