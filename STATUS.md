# Status

**Updated:** 2026-10-28 · **Phase:** 2, Prototype · **Step:** 03, Buy the parts (ordered, in transit)

## Next actions
1. Agree whether the owner's earlier KiCad 10 project replaces the tutorial for step 05, then `/gate` step 05.
2. Create the KiCad project in `hardware/kicad/` ("Create a new folder" unticked) and draw a **draft**
   schematic with the candidate pins. It stays provisional until step 04 confirms them.
3. Record the exact keycap model in `docs/hardware/parts.md` (Q8).
4. When parts arrive: run `/check-part` on each part and measure the RP2040-Zero clone with calipers.
5. Then step 04: solder headers to **one** RP2040-Zero only. Keep the second one bare (Q4).

## Blockers
- Parts in transit (ordered 2026-10-28 from Amazon).

## Open questions
| ID | Question | Needed by | How it gets settled |
|---|---|---|---|
| Q1 | Hot-swap sockets or solder the switches directly? | Step 07 | ADR |
| Q2 | Final I2C pins for the OLED | Step 06 | Breadboard test |
| Q3 | Does the OLED module have I2C pull-ups on board? | Step 06 | Inspect or measure the module |
| Q4 | Mount the RP2040-Zero flat on its edge pads, or on headers? | Step 07 | ADR, after measuring the clone |
| Q5 | Key pitch for the chosen low-profile keycaps | Step 08 | Keycap drawing or measurement |
| Q6 | Knob height vs keycap height (shorten the shaft? lower knob?) | Step 08 | Stack-up in `mechanical.md` |
| Q7 | Case approach (3D print? plate sandwich?) | Step 13 | ADR |
| Q8 | Exact keycap model and link | Now | Owner fills in `parts.md` |

## Steps
- [x] 01 Lock the spec
- [x] 02 Pick switches and mounting (footprint family fixed; hot-swap still open, see Q1)
- [~] 03 Buy the parts (ordered 2026-10-28)
- [ ] 04 Breadboard and flash firmware
- [~] 05 Install KiCad 10 and do the tutorial (KiCad 10.0.4 installed; awaiting `/gate`)
- [ ] 06 Draw the schematic
- [ ] 07 Verify every footprint
- [ ] 08 Place the parts
- [ ] 09 Route and pour ground
- [ ] 10 Run the pre-order checks
- [ ] 11 Get a design review
- [ ] 12 Export and order
- [ ] 13 Assemble and test

Legend: `[x]` done · `[~]` in progress · `[ ]` not started. Exit criteria for each step are in `docs/phases/`.
