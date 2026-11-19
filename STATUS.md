# Status

**Updated:** 2026-11-19 · **Phase:** 3, Design · **Step:** 06, Draw the schematic (pins match `pinout.md`, all 16 proven on Rev A; left: the DISP1 `lib_symbol_mismatch` warning, then ERC and `/gate`). Step 04 gate passed 2026-11-19. Rev A fully assembled 2026-11-19 (step 13 started early under ADR-0011). Phase 2's step 03 still open: `/check-part` (arrived) for switches, encoders and keycaps; knob model not reported

## Next actions
1. Step 06: owner fixes the DISP1 `lib_symbol_mismatch` warning in KiCad; run ERC (`kicad-cli sch erc`); `/gate` 06 (exit: "ERC passes, and the pins match the breadboard"; the pins half is met).
2. Step 07 prep: `/check-part` (arrived) for the switches, encoders and keycaps (also closes step 03). Footprint verification itself needs calipers (Blockers).
3. Go public (log 2026-11-17): settle Q17; make the repo public; delete the merged branches (`dev` → `main` done, PR #6).
4. Restore `knockout` on the SW1–SW4 reference labels in KiCad, then a new `hw:` commit (lost in the 2026-11-16 Update Footprint and committed in `a412114`; log 2026-11-17).
5. Parts and housekeeping:
   - Owner: keycap checks left (full travel, skirt gap, width, height; `parts.md`, Keycaps; 30-day return); knob model and link, push still clicks with the knob on; which end of each LED went on pad 1 (`parts.md`, D1–D4). Optional: swap ENC1/ENC2 functions so the top knob does volume (log 2026-11-19).
   - `datasheets/README.md`: download links for the Waveshare, SamacSys and FreeCAD KS-33 models; SnapMagic original author (ADR-0014).
   - `hardware/kicad/README.md`: out of date outside the licence table (log 2026-11-17). `firmware/qmk/minipad/readme.md` missing (`qmk lint`).
   - Gerbers from `a389c1f` and the `rev-a` tag (log 2026-11-05).
   - Owner decisions from log 2026-11-11: ADR-0011 phase file, the ADR-0009 reference in `.claude/rules/hardware.md`. Windows Security check for QMK MSYS.
   - Later: Q8 → Q5, Q1 ADR, Q15, Q13; CERN-OHL board marking (ADR-0014).

## Blockers
- No multimeter or calipers recorded (owner, 2026-11-04; nothing new 2026-11-14). Q12's Vf number needs a multimeter.
- Rev A's Gerber commit not confirmed (candidate `a389c1f`, log 2026-11-05). No `rev-a` tag.

## Open questions
| ID | Question | Needed by | How it gets settled |
|---|---|---|---|
| Q5 | Key pitch for the chosen low-profile keycaps | Step 08 | 19.1 mm provisional (owner, 2026-11-01, `mechanical.md`); confirm with the keycap drawing or a measurement. Depends on Q8 |
| Q6 | Knob height vs keycap height | Step 08 | Stack-up in `mechanical.md`. PEC11L model: shaft top 19.6 mm above the PCB (ADR-0013). Knobs and keycaps now fitted (owner, 2026-11-19): measure knob top and keycap top above the PCB |
| Q7 | Case approach, including OLED support (board mounting holes settled: ADR-0010) | Step 08 | ADR. Inputs: `mechanical.md`, "Inputs for the case decision" |
| Q8 | Exact keycap model and link. LQXQ low-profile PBT shine-through, ASIN B0H1C8RZP7 (sold for Gateron MX): arrived and fitted on Rev A, legends shine through (owner, 2026-11-19) | Now | Remaining arrival checks (`parts.md`, Keycaps): full travel, skirt gap, width |
| Q11 | Step 05 heading still says "do the tutorial". Reword it? | Now | Owner decision (log 2026-10-29, Session 6) |
| Q12 | White LED forward voltage. R3–R6 = 220 Ω fitted on Rev A; all four LEDs light and breathe (owner, 2026-11-14) | Rev B | Multimeter: V across the LED and the resistor (`parts.md`, D1–D4) |
| Q13 | `docs/phases/03-design.md` step 06 says "optional 4.7 kΩ" pull-ups. Q9 settled on none (log 2026-11-14). Reword to "not fitted (Q9)"? | Rev B | Owner agreement (phase file change, log 2026-10-30) |
| Q15 | How do the four key LEDs behave (together or per key; steady, breathing, reacting to keys)? Driver answered: own PWM code on slices 4B, 5A, 5B, 6A, because QMK's multi-pin backlight drivers can't breathe on the RP2040 (log 2026-11-14). The sample breathes all four together | Step 13 (firmware) | Owner decision; `/decision` if it shapes the firmware |
| Q17 | Track `CLAUDE.md` in the public repo? It's gitignored since `67aaccb`, so visitors see `.claude/` but not the main instructions | Before going public | Owner decision; if yes, remove `CLAUDE*.md`/`claude*.md` from `.gitignore` and add it to the README layout (log 2026-11-17) |

## Steps
- [x] 01 Lock the spec
- [x] 02 Pick switches and mounting (footprint family fixed; soldered, Q1 answered, ADR pending)
- [~] 03 Buy the parts (all on the desk, owner: OLED 2026-11-04, RP2040-Zero 2026-11-08, LEDs and resistors 2026-11-10, switches by 2026-11-14, PEC11L encoders and keycaps by 2026-11-19 (dates not reported); knobs fitted, model not reported; `/check-part` (arrived) missing for switches, encoders and keycaps)
- [x] 04 Breadboard and flash firmware (gate passed 2026-11-19; reported by owner, on Rev A: 2026-11-14 K1–K4 type a–d, D1–D4 breathe, OLED shows text; 2026-11-19 both encoders 20 steps per turn, right direction, pushes work. All 16 pins ✔ in `pinout.md`; firmware `29842c6`)
- [x] 05 Install KiCad 10 and do the tutorial (gate passed 2026-10-29 under the narrowed criterion; log Session 5)
- [~] 06 Draw the schematic (draft, ERC 0 errors, 1 warning: DISP1 `lib_symbol_mismatch`, fix pending owner; all 16 pins proven on Rev A, owner 2026-11-19)
- [ ] 07 Verify every footprint (candidates recorded in `parts.md`; all real parts now here; PEC11L pins and tabs fit the Rev A footprint without forcing, owner 2026-11-19)
- [~] 08 Place the parts (draft: 69.8 × 69.1 mm outline, M3 corner holes per ADR-0010; key pitch 19.1 mm provisional; footprints not yet verified)
- [~] 09 Route and pour ground (draft: all nets routed on F.Cu, GND pour both layers, DRC clean 2026-10-31; will change after 07/08)
- [~] 10 Run the pre-order checks (brought forward by ADR-0011; checklist in `fabrication.md` still open; Rev A ordered before it was run)
- [ ] 11 Get a design review
- [~] 12 Export and order (Rev A ordered 2026-11-03, PCBWay order YR1841165, arrived 2026-11-13, ADR-0012; commit not confirmed)
- [~] 13 Assemble and test (Rev A fully assembled 2026-11-19, keycaps and knobs on; keys, LEDs, OLED and encoders work, owner; case not started)

Legend: `[x]` done · `[~]` in progress · `[ ]` not started. Exit criteria for each step are in `docs/phases/`.
