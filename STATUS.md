# Status

**Updated:** 2026-11-11 · **Phase:** 2, Prototype · **Step:** 04, Breadboard and flash firmware (first `minipad` firmware runs; 2 of 16 pins proven). Step 03 still open (switches expected 2026-11-12; keycaps TBD). Rev A ordered (step 12, early under ADR-0011)

## Next actions
1. Owner: when the switches arrive (expected 2026-11-12), `/check-part` them. Then compare 220/330/470 Ω under one switch at full duty (breathing off) to choose R3–R6 (log 2026-11-11).
2. Owner: wire ENC1 fully (A → GP6, B → GP7, C → GND, push → GP8). Claude then adds the encoder to `keyboard.json` (turn = volume, push = mute): direction and steps per detent come from that test, in place of the Pro Micro numbers asked for on 2026-11-05. Then the second encoder and K2–K4.
3. Then the OLED on GP0/GP1 at 3.3 V without external pull-ups (I2C in `halconf.h`/`mcuconf.h`): settles Q2 and Q9.
4. Owner: Windows Security checks for the blocked QMK MSYS `collect2.exe`/`git.exe` (log 2026-11-11). OK for Claude to regenerate the Gerbers from `a389c1f` in a scratch worktree and compare them with the ordered zip (log 2026-11-05), then record the commit in `fabrication.md` and tag `rev-a`; say whether Rev A has any bottom-silkscreen marking.
5. Owner decisions: the basis for "no external pull-ups" (Q9) and whether it needs an ADR; the ADR-0011 phase-file question (`docs/phases/04-order-build.md`), the ADR-0009 reference in `.claude/rules/hardware.md`, and whether `main` (one unrelated commit) should get the history from `parts`. Later: keycap model (Q8), then key pitch (Q5); Q1 ADR; Q15; step 07 prep.

## Blockers
- No multimeter or calipers recorded (owner, 2026-11-04; nothing new 2026-11-11). Q12's Vf number needs a multimeter.
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
| Q12 | White LED forward voltage. GPIO drive answered: very bright from GP9 through 220 Ω (owner, 2026-11-11), so no 5 V + transistor needed for brightness | Step 13 | Multimeter: V across the LED and the resistor (`parts.md`, D1–D4) |
| Q13 | `docs/phases/03-design.md` step 06 says "optional 4.7 kΩ" pull-ups; Q9 may pick 2.2 kΩ. Reword to "value from Q9"? | Step 06 | Owner agreement (phase file change, log 2026-10-30) |
| Q14 | Do the EC11's flat blade pins (diagonal) pass the Rev A pad drill (1.2 mm)? | Step 07 | Test-fit on the Rev A board before soldering, or calipers (`parts.md`, ENC1–ENC2) |
| Q15 | How do the four key LEDs behave (together or per key; steady, breathing, reacting to keys) and what drives them in QMK (backlight `timer` driver for several pins, or own PWM code)? Hardware allows either: GP9–GP12 are PWM slices 4B, 5A, 5B, 6A | Step 13 (firmware) | Owner decision; `/decision` if it shapes the firmware (log 2026-11-11) |

## Steps
- [x] 01 Lock the spec
- [x] 02 Pick switches and mounting (footprint family fixed; soldered, Q1 answered, ADR pending)
- [~] 03 Buy the parts (encoders and OLED arrived 2026-11-04, RP2040-Zero 2026-11-08, LEDs and resistors bought 2026-11-10, all owner; switches expected 2026-11-12; keycaps TBD)
- [~] 04 Breadboard and flash firmware (2026-11-11, reported by owner: `minipad` firmware flashed; GP2 key and GP9 LED, steady and PWM, breadboard ✔; 14 pins left. Builds in WSL: `wsl bash firmware/build.sh`. Firmware not yet committed)
- [x] 05 Install KiCad 10 and do the tutorial (gate passed 2026-10-29 under the narrowed criterion; log Session 5)
- [~] 06 Draw the schematic (draft, ERC 0 errors, 1 warning: DISP1 `lib_symbol_mismatch`, fix pending owner; 2 of 16 pins breadboard-confirmed)
- [ ] 07 Verify every footprint (candidates recorded in `parts.md`; needs the real parts; EC11 pad drills changed to 1.2 mm for Rev A, not measured)
- [~] 08 Place the parts (draft: 69.8 × 69.1 mm outline, M3 corner holes per ADR-0010; key pitch 19.1 mm provisional; footprints not yet verified)
- [~] 09 Route and pour ground (draft: all nets routed on F.Cu, GND pour both layers, DRC clean 2026-10-31; will change after 07/08)
- [~] 10 Run the pre-order checks (brought forward by ADR-0011; checklist in `fabrication.md` still open; Rev A ordered before it was run)
- [ ] 11 Get a design review
- [~] 12 Export and order (Rev A ordered 2026-11-03, PCBWay order YR1841165, ADR-0012; commit not confirmed)
- [ ] 13 Assemble and test

Legend: `[x]` done · `[~]` in progress · `[ ]` not started. Exit criteria for each step are in `docs/phases/`.
