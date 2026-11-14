# Status

**Updated:** 2026-11-14 · **Phase:** 2, Prototype · **Step:** 04, Breadboard and flash firmware (10 of 16 pins proven, on the assembled Rev A board; only the 6 encoder pins left). Rev A arrived 2026-11-13 and is assembled except ENC1–ENC2 (step 13 started early under ADR-0011). Step 03 still open: PEC11L encoders expected 2026-11-18 (ADR-0013); D-shaft knobs and keycaps TBD

## Next actions
1. Before committing: move `LIB_PEC11L-4115F-S0020.zip` out of the repo root (or gitignore it; licensed model). Then commit 2026-11-13 and 2026-11-14 separately (log 2026-11-14).
2. When the PEC11L arrives (expected 2026-11-18): `/check-part` it (arrived), test-fit unsoldered on Rev A (Q16), solder ENC1–ENC2 (datasheet p. 1: hand soldering "not recommended", keep it short). Then Claude adds the encoders to `keyboard.json` (turn = volume, push = mute) and the owner tests: step 04's last 6 pins (GP6–GP8, GP26–GP28).
3. Owner: `/check-part` the switches (arrived, already soldered; record the arrival date). Say which end of each LED (green mark or not) went on pad 1 (`parts.md`, D1–D4).
4. Owner: choose D-shaft knobs for the PEC11L (6 mm, 4.5 mm across the flat, bore no deeper than 10 mm, low; `parts.md`, ADR-0013) and the keycaps (Q8).
5. Housekeeping:
   - Add the download links for the Waveshare and SamacSys models to `datasheets/README.md`.
   - Gerbers from `a389c1f` and the `rev-a` tag (log 2026-11-05).
   - Owner decisions from log 2026-11-11: ADR-0011 phase file, the ADR-0009 reference in `.claude/rules/hardware.md`, `main` history. Windows Security check for QMK MSYS.
   - Later: Q8 → Q5, Q1 ADR, Q15, Q13, step 07 prep.

## Blockers
- No multimeter or calipers recorded (owner, 2026-11-04; nothing new 2026-11-14). Q12's Vf number needs a multimeter.
- Rev A's Gerber commit not confirmed (candidate `a389c1f`, log 2026-11-05). No `rev-a` tag.

## Open questions
| ID | Question | Needed by | How it gets settled |
|---|---|---|---|
| Q5 | Key pitch for the chosen low-profile keycaps | Step 08 | 19.1 mm provisional (owner, 2026-11-01, `mechanical.md`); confirm with the keycap drawing or a measurement. Depends on Q8 |
| Q6 | Knob height vs keycap height | Step 08 | Stack-up in `mechanical.md`. PEC11L model: shaft top 19.6 mm above the PCB (ADR-0013); depends on the D-shaft knob and the keycaps (Q8) |
| Q7 | Case approach, including OLED support (board mounting holes settled: ADR-0010) | Step 08 | ADR. Inputs: `mechanical.md`, "Inputs for the case decision" |
| Q8 | Exact keycap model and link | Now | Owner fills in `parts.md` |
| Q11 | Step 05 heading still says "do the tutorial". Reword it? | Now | Owner decision (log 2026-10-29, Session 6) |
| Q12 | White LED forward voltage. R3–R6 = 220 Ω fitted on Rev A; all four LEDs light and breathe (owner, 2026-11-14) | Rev B | Multimeter: V across the LED and the resistor (`parts.md`, D1–D4) |
| Q13 | `docs/phases/03-design.md` step 06 says "optional 4.7 kΩ" pull-ups. Q9 settled on none (log 2026-11-14). Reword to "not fitted (Q9)"? | Rev B | Owner agreement (phase file change, log 2026-10-30) |
| Q15 | How do the four key LEDs behave (together or per key; steady, breathing, reacting to keys)? Driver answered: own PWM code on slices 4B, 5A, 5B, 6A, because QMK's multi-pin backlight drivers can't breathe on the RP2040 (log 2026-11-14). The sample breathes all four together | Step 13 (firmware) | Owner decision; `/decision` if it shapes the firmware |
| Q16 | Do the PEC11L-4115F's pins (1.2 mm drills) and snap tabs (1.5 × 2.8 mm slots) enter the Rev A holes? The 3D model says yes, with the barbs flexing about 0.6 mm | Step 13 (assembly) | Test-fit unsoldered on Rev A when the parts arrive (`parts.md`, ENC1–ENC2 arrival checks; log 2026-11-13) |

## Steps
- [x] 01 Lock the spec
- [x] 02 Pick switches and mounting (footprint family fixed; soldered, Q1 answered, ADR pending)
- [~] 03 Buy the parts (OLED arrived 2026-11-04, RP2040-Zero 2026-11-08, LEDs and resistors bought 2026-11-10, switches arrived by 2026-11-14 (date not reported), all owner; encoders: 6 × PEC11L-4115F-S0020 ordered 2026-11-13 from Farnell, expected 2026-11-18 (ADR-0013), generic EC11s kept as spares; D-shaft knobs and keycaps TBD; `/check-part` arrived still missing for the switches)
- [~] 04 Breadboard and flash firmware (2026-11-14, reported by owner, on Rev A: K1–K4 type a–d, D1–D4 breathe, OLED shows text; 10 of 16 pins ✔ in `pinout.md`, encoders left. Builds in WSL: `wsl bash firmware/build.sh`, QMK `d194c077ed`)
- [x] 05 Install KiCad 10 and do the tutorial (gate passed 2026-10-29 under the narrowed criterion; log Session 5)
- [~] 06 Draw the schematic (draft, ERC 0 errors, 1 warning: DISP1 `lib_symbol_mismatch`, fix pending owner; 10 of 16 pins proven on Rev A)
- [ ] 07 Verify every footprint (candidates recorded in `parts.md`; needs the real parts; encoder footprint now carries the PEC11L 3D model, pads unchanged, fit per the model only, Q16)
- [~] 08 Place the parts (draft: 69.8 × 69.1 mm outline, M3 corner holes per ADR-0010; key pitch 19.1 mm provisional; footprints not yet verified)
- [~] 09 Route and pour ground (draft: all nets routed on F.Cu, GND pour both layers, DRC clean 2026-10-31; will change after 07/08)
- [~] 10 Run the pre-order checks (brought forward by ADR-0011; checklist in `fabrication.md` still open; Rev A ordered before it was run)
- [ ] 11 Get a design review
- [~] 12 Export and order (Rev A ordered 2026-11-03, PCBWay order YR1841165, arrived 2026-11-13, ADR-0012; commit not confirmed)
- [~] 13 Assemble and test (Rev A assembled 2026-11-14 except ENC1–ENC2; keys, LEDs and OLED work, owner)

Legend: `[x]` done · `[~]` in progress · `[ ]` not started. Exit criteria for each step are in `docs/phases/`.
