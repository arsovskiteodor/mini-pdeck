# Status

**Updated:** 2026-11-17 · **Phase:** 2, Prototype · **Step:** 04, Breadboard and flash firmware (10 of 16 pins proven, on the assembled Rev A board; only the 6 encoder pins left). Rev A arrived 2026-11-13 and is assembled except ENC1–ENC2 (step 13 started early under ADR-0011). Step 03 still open: PEC11L encoders expected 2026-11-18 (ADR-0013); keycaps ordered 2026-11-16 (Q8); D-shaft knobs TBD

## Next actions
1. PEC11L (expected 2026-11-18): Claude first prepares the encoder firmware in `keyboard.json` (turn = volume, push = mute; `resolution` from the PEC11L datasheet p. 1). On arrival: `/check-part` (arrived), test-fit unsoldered (Q16), solder ENC1–ENC2 (datasheet p. 1: hand soldering "not recommended", keep it short), owner tests step 04's last 6 pins (GP6–GP8, GP26–GP28).
2. Go public (log 2026-11-17): owner photographs Rev A with encoders (EXIF stripped, resized) into `docs/images/` and replaces the README placeholder; settles Q17; PR `dev` → `main`; makes the repo public; deletes the merged branches.
3. Restore `knockout` on the SW1–SW4 reference labels in KiCad, then a new `hw:` commit (lost in the 2026-11-16 Update Footprint and committed in `a412114`; log 2026-11-17).
4. Parts (owner): keycap price and delivery date, one-key fit test on arrival (`parts.md`, Keycaps; 30-day return); `/check-part` the switches; which end of each LED went on pad 1 (`parts.md`, D1–D4); D-shaft knobs (6 mm, 4.5 mm across the flat, bore ≤ 10 mm; `parts.md`, ADR-0013).
5. Housekeeping:
   - `datasheets/README.md`: download links for the Waveshare, SamacSys and FreeCAD KS-33 models; SnapMagic original author (ADR-0014).
   - `hardware/kicad/README.md`: out of date outside the licence table (log 2026-11-17).
   - Gerbers from `a389c1f` and the `rev-a` tag (log 2026-11-05).
   - Owner decisions from log 2026-11-11: ADR-0011 phase file, the ADR-0009 reference in `.claude/rules/hardware.md`. Windows Security check for QMK MSYS.
   - Later: Q8 → Q5, Q1 ADR, Q15, Q13, step 07 prep; CERN-OHL board marking (ADR-0014).

## Blockers
- No multimeter or calipers recorded (owner, 2026-11-04; nothing new 2026-11-14). Q12's Vf number needs a multimeter.
- Rev A's Gerber commit not confirmed (candidate `a389c1f`, log 2026-11-05). No `rev-a` tag.

## Open questions
| ID | Question | Needed by | How it gets settled |
|---|---|---|---|
| Q5 | Key pitch for the chosen low-profile keycaps | Step 08 | 19.1 mm provisional (owner, 2026-11-01, `mechanical.md`); confirm with the keycap drawing or a measurement. Depends on Q8 |
| Q6 | Knob height vs keycap height | Step 08 | Stack-up in `mechanical.md`. PEC11L model: shaft top 19.6 mm above the PCB (ADR-0013); depends on the D-shaft knob and the keycaps (Q8) |
| Q7 | Case approach, including OLED support (board mounting holes settled: ADR-0010) | Step 08 | ADR. Inputs: `mechanical.md`, "Inputs for the case decision" |
| Q8 | Exact keycap model and link. Candidate ordered 2026-11-16: LQXQ low-profile PBT shine-through, ASIN B0H1C8RZP7 (sold for Gateron MX, not KS-33) | Now | Arrival checks pass (`parts.md`, Keycaps): fit on the KS-33 at full travel, shine-through, width |
| Q11 | Step 05 heading still says "do the tutorial". Reword it? | Now | Owner decision (log 2026-10-29, Session 6) |
| Q12 | White LED forward voltage. R3–R6 = 220 Ω fitted on Rev A; all four LEDs light and breathe (owner, 2026-11-14) | Rev B | Multimeter: V across the LED and the resistor (`parts.md`, D1–D4) |
| Q13 | `docs/phases/03-design.md` step 06 says "optional 4.7 kΩ" pull-ups. Q9 settled on none (log 2026-11-14). Reword to "not fitted (Q9)"? | Rev B | Owner agreement (phase file change, log 2026-10-30) |
| Q15 | How do the four key LEDs behave (together or per key; steady, breathing, reacting to keys)? Driver answered: own PWM code on slices 4B, 5A, 5B, 6A, because QMK's multi-pin backlight drivers can't breathe on the RP2040 (log 2026-11-14). The sample breathes all four together | Step 13 (firmware) | Owner decision; `/decision` if it shapes the firmware |
| Q16 | Do the PEC11L-4115F's pins (1.2 mm drills) and snap tabs (1.5 × 2.8 mm slots) enter the Rev A holes? The 3D model says yes, with the barbs flexing about 0.6 mm | Step 13 (assembly) | Test-fit unsoldered on Rev A when the parts arrive (`parts.md`, ENC1–ENC2 arrival checks; log 2026-11-13) |
| Q17 | Track `CLAUDE.md` in the public repo? It's gitignored since `67aaccb`, so visitors see `.claude/` but not the main instructions | Before going public | Owner decision; if yes, remove `CLAUDE*.md`/`claude*.md` from `.gitignore` and add it to the README layout (log 2026-11-17) |

## Steps
- [x] 01 Lock the spec
- [x] 02 Pick switches and mounting (footprint family fixed; soldered, Q1 answered, ADR pending)
- [~] 03 Buy the parts (OLED arrived 2026-11-04, RP2040-Zero 2026-11-08, LEDs and resistors bought 2026-11-10, switches arrived by 2026-11-14 (date not reported), all owner; encoders: 6 × PEC11L-4115F-S0020 ordered 2026-11-13 from Farnell, expected 2026-11-18 (ADR-0013), generic EC11s kept as spares; keycaps ordered 2026-11-16 (Amazon.es, Q8); D-shaft knobs TBD; `/check-part` arrived still missing for the switches)
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
