# Status

**Updated:** 2026-10-29 · **Phase:** 2, Prototype · **Step:** 03, Buy the parts (ordered, in transit)

## Next actions
1. Record the keycap model and link in `docs/hardware/parts.md`, then mark Q8 done (owner).
2. Decide whether to write ADRs for Q1 and Q4. Both answers are in the log, not yet in an ADR.
3. Start the draft schematic from the candidate pins in `docs/hardware/pinout.md`. Mark it provisional until step 04 confirms the pins. This can run while parts are in transit.
4. When parts arrive: `/check-part` each one, measure the RP2040-Zero clone with calipers, measure the OLED module's pull-ups and address pad (Q3, Q10), and find the SSD1306 I2C timing table (Q9).
5. Then step 04: solder headers to **one** RP2040-Zero only. Keep the second one bare.

## Blockers
- Parts in transit (ordered 2026-10-28 from Amazon).
- Q9 (external pull-up value) waits for the bus capacitance, which needs the boards.

## Open questions
| ID | Question | Needed by | How it gets settled |
|---|---|---|---|
| Q2 | Final I2C pins for the OLED | Step 06 | Breadboard test. Still open: photos don't cover the MCU side |
| Q3 | Does the OLED module have I2C pull-ups on board? | Step 06 | Measure the module on arrival. The chip needs pull-ups on SDA and SCL (SSD1306 §8.1.5, page TBD), so if the module has none we add them. Still open |
| Q5 | Key pitch for the chosen low-profile keycaps | Step 08 | Keycap drawing or measurement. **In progress** (owner, 2026-10-29); depends on Q8 |
| Q6 | Knob height vs keycap height (shorten the shaft? lower knob?) | Step 08 | Stack-up in `mechanical.md` |
| Q7 | Case approach (3D print? plate sandwich?) | Step 13 | ADR |
| Q8 | Exact keycap model and link | Now | Owner fills in `parts.md` |
| Q9 | External I2C pull-up value on our board | Step 06 | Sizing from `parts.md` (DISP1): measured bus capacitance, plus the SSD1306 tr limit (page TBD) |
| Q10 | Is the received OLED the module in the listing photos (board "HW-239", row says QWORK)? Which address pad is bridged? | Step 04 | Inspect the received module |
| Q11 | Step 05 heading still says "do the tutorial", but the exit criterion no longer asks for it. Reword the heading? | Now | Owner decision (log 2026-10-29, Session 6) |

## Steps
- [x] 01 Lock the spec
- [x] 02 Pick switches and mounting (footprint family fixed; hot-swap still open, see Q1)
- [~] 03 Buy the parts (ordered 2026-10-28)
- [ ] 04 Breadboard and flash firmware
- [x] 05 Install KiCad 10 and do the tutorial (gate passed 2026-10-29 under the narrowed criterion; log Session 5)
- [ ] 06 Draw the schematic
- [ ] 07 Verify every footprint
- [ ] 08 Place the parts
- [ ] 09 Route and pour ground
- [ ] 10 Run the pre-order checks
- [ ] 11 Get a design review
- [ ] 12 Export and order
- [ ] 13 Assemble and test

Legend: `[x]` done · `[~]` in progress · `[ ]` not started. Exit criteria for each step are in `docs/phases/`.
