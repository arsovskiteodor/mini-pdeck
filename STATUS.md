# Status

**Updated:** 2026-11-10 · **Phase:** 2, Prototype · **Step:** 03, Buy the parts (all electronics in hand except the switches, expected 2026-11-12; keycaps TBD), with Rev A ordered (step 12, early under ADR-0011)

## Next actions
1. Owner: from the encoder bench test, give `last` per click (QMK `resolution`), which sign is clockwise and the `bad` count. Then test the second encoder (log 2026-11-05).
2. Owner: OK for Claude to regenerate the Gerbers from `a389c1f` in a scratch worktree and compare them with the ordered zip (log 2026-11-05). Then record the commit in `fabrication.md` and tag `rev-a` after your OK. Also say whether Rev A has any bottom-silkscreen marking.
3. Owner: LED stage 2, one LED from a GPIO through 220 Ω (Claude writes the one-pin test firmware on request); compare 220/330 Ω under a switch once the switches arrive. Say whether you got a multimeter; if so, measure Vf and V across the resistor (Q12) (log 2026-11-10).
4. Owner: confirm the QMK branch (`master` or `develop`, log 2026-11-04 Session 2). Claude then builds a reference RP2040 board (build only). Then step 04 on **one** RP2040-Zero.
5. Owner decisions: the basis for "no external pull-ups" (Q9, log 2026-11-10) and whether it needs an ADR; the ADR-0011 phase-file question (`docs/phases/04-order-build.md`), the ADR-0009 reference in `.claude/rules/hardware.md`, and whether `main` (one unrelated commit) should get the history from `parts`. Later: keycap model (Q8), then key pitch (Q5); Q1 ADR; step 07 prep.

## Blockers
- No multimeter or calipers recorded (owner, 2026-11-04; nothing new 2026-11-10). Q12's Vf number needs a multimeter.
- Rev A's Gerber commit not confirmed (candidate `a389c1f`, log 2026-11-05). No `rev-a` tag.

## Open questions
| ID | Question | Needed by | How it gets settled |
|---|---|---|---|
| Q2 | Final I2C pins for the OLED | Step 06 | Breadboard test (step 04) |
| Q5 | Key pitch for the chosen low-profile keycaps | Step 08 | 19.1 mm provisional (owner, 2026-11-01, `mechanical.md`); confirm with the keycap drawing or a measurement. Depends on Q8 |
| Q6 | Knob height vs keycap height | Step 08 | Stack-up in `mechanical.md` (encoder model: shaft top 26.6 mm above the PCB) |
| Q7 | Case approach, including OLED support (board mounting holes settled: ADR-0010) | Step 08 | ADR. Inputs: `mechanical.md`, "Inputs for the case decision" |
| Q8 | Exact keycap model and link | Now | Owner fills in `parts.md` |
| Q9 | External I2C pull-ups (2.2 kΩ, 4.7 kΩ or none). Owner, 2026-11-10: none needed, settled in an earlier session; no record found. On file: module pull-ups work on the 5 V Pro Micro (2026-11-04) | Step 06 | Owner points to the basis, or the RP2040 breadboard test (step 04) runs the OLED without them (log 2026-11-10) |
| Q11 | Step 05 heading still says "do the tutorial". Reword it? | Now | Owner decision (log 2026-10-29, Session 6) |
| Q12 | White LED forward voltage, and can a 3.3 V GPIO drive it? Lights from 3V3 through 220 Ω (owner, 2026-11-10), so Vf < 3.3 V; number not measured | Step 08 | Multimeter reading and the GPIO test (`parts.md`, D1–D4); if too dim from a GPIO, 5 V + transistor (ADR-0009 "Revisit if") |
| Q13 | `docs/phases/03-design.md` step 06 says "optional 4.7 kΩ" pull-ups; Q9 may pick 2.2 kΩ. Reword to "value from Q9"? | Step 06 | Owner agreement (phase file change, log 2026-10-30) |
| Q14 | Do the EC11's flat blade pins (diagonal) pass the Rev A pad drill (1.2 mm)? | Step 07 | Test-fit on the Rev A board before soldering, or calipers (`parts.md`, ENC1–ENC2) |

## Steps
- [x] 01 Lock the spec
- [x] 02 Pick switches and mounting (footprint family fixed; soldered, Q1 answered, ADR pending)
- [~] 03 Buy the parts (encoders and OLED arrived 2026-11-04, RP2040-Zero 2026-11-08, LEDs and resistors bought 2026-11-10, all owner; switches expected 2026-11-12; keycaps TBD)
- [~] 04 Breadboard and flash firmware (QMK install checked 2026-11-04; no `minipad` folder yet; RP2040-Zero used only as a 3V3 supply, 2026-11-10. Pro Micro bench tests of the OLED and one EC11 don't count toward the exit criterion)
- [x] 05 Install KiCad 10 and do the tutorial (gate passed 2026-10-29 under the narrowed criterion; log Session 5)
- [~] 06 Draw the schematic (draft, ERC 0 errors, 1 warning: DISP1 `lib_symbol_mismatch`, fix pending owner; pins not yet breadboard-confirmed)
- [ ] 07 Verify every footprint (candidates recorded in `parts.md`; needs the real parts; EC11 pad drills changed to 1.2 mm for Rev A, not measured)
- [~] 08 Place the parts (draft: 69.8 × 69.1 mm outline, M3 corner holes per ADR-0010; key pitch 19.1 mm provisional; footprints not yet verified)
- [~] 09 Route and pour ground (draft: all nets routed on F.Cu, GND pour both layers, DRC clean 2026-10-31; will change after 07/08)
- [~] 10 Run the pre-order checks (brought forward by ADR-0011; checklist in `fabrication.md` still open; Rev A ordered before it was run)
- [ ] 11 Get a design review
- [~] 12 Export and order (Rev A ordered 2026-11-03, PCBWay order YR1841165, ADR-0012; commit not confirmed)
- [ ] 13 Assemble and test

Legend: `[x]` done · `[~]` in progress · `[ ]` not started. Exit criteria for each step are in `docs/phases/`.
