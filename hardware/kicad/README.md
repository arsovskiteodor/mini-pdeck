# KiCad project

Created with KiCad 10 (draft schematic, 2026-10-30), named `mini-pdeck`: `mini-pdeck.kicad_pro`,
`mini-pdeck.kicad_sch` and `mini-pdeck.kicad_pcb`, directly in this folder. Keep them here: `${KIPRJMOD}`
(the project folder) is how the library table and the 3D model links find `lib/`.

## Libraries
Libraries are project-local, so the repo works on any machine without changing global KiCad settings.

```
hardware/kicad/
├── lib/
│   ├── minipad.pretty/         # OUR footprints: every one verified against a real part
│   ├── minipad.kicad_sym       # OUR symbols (if any are needed)
│   └── third_party/
│       └── key-switches.pretty # git submodule, never edited
└── production/                 # fab outputs, gitignored
```

- Add the switch library as a submodule:
  `git submodule add https://github.com/siderakb/key-switches.pretty hardware/kicad/lib/third_party/key-switches.pretty`
- Register libraries in **Preferences → Manage Footprint Libraries → Project Specific Libraries**
  with paths like `${KIPRJMOD}/lib/minipad.pretty`.
- **Copy before you change.** To use or tweak a third-party or stock footprint, copy it into
  `minipad.pretty` first. Note its source and verification status in `docs/hardware/parts.md`.

## Footprint sources (starting points, all to be verified in step 07)
| Part | Starting footprint | Verify against |
|---|---|---|
| RP2040-Zero | Candidate: `minipad.pretty/MODULE_RP2040-ZERO`, SnapMagic copy with the Waveshare 3D model added (`parts.md`, U1). Final choice in step 07 | Waveshare drawing and the measured clone |
| Gateron KS-33 | `minipad.pretty/SW_Gateron_LowProfile_THT`: copy of `key-switches.pretty` (soldered, Q1) with Gateron's 3D model added (`lib/3d/`, gitignored). Checked against the Gateron drawing (`parts.md`, SW1–SW4) | Real switch, 1:1 print |
| White LED 1206 (D1–D4, ADR-0009) | `minipad.pretty/LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder`: unchanged copy of KiCad 10 stock | Pads inside the switch's LED window (`parts.md`, D1–D4); real LED with calipers |
| EC11 | `minipad.pretty/RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm`: copy of KiCad 10 stock with a Bourns PEC11R 3D model as stand-in (`lib/3d/`, gitignored). Pin hole and tab slots differ from the SR Passives drawing (`parts.md`, ENC1–ENC2) | Real encoder, 1:1 print |
| OLED | Now: `minipad.pretty/PinHeader_1x04_P2.54mm_Vertical`, unchanged copy of KiCad 10 stock (the module's header is soldered in, no socket). Later: our own footprint with the module outline, and mounting holes if chosen (Q7), from calipers | Received module (pin order!) |
| Resistors R1–R6 (pull-ups, LED series) | `minipad.pretty/R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal`: unchanged copy of KiCad 10 stock (1/4 W, body 6.3 × Ø2.5 mm, 7.62 mm pitch, 0.8 mm drill) | Real resistor: body size and lead diameter with calipers |

## Habits
- Commit after each milestone: schematic done, footprints assigned, placement done, routing done.
  These give you restore points.
- Run ERC and DRC often, not just at the end.
- Don't hand-edit `.kicad_sch` or `.kicad_pcb` text files. Make changes in KiCad.
