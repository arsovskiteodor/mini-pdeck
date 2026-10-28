# KiCad project

Created in step 06 with KiCad 10: **File → New Project** in this folder, named `minipad`.
That gives `minipad.kicad_pro`, `minipad.kicad_sch` and `minipad.kicad_pcb`.

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
| RP2040-Zero | TBD (Waveshare drawing, or a community footprint) | Measured clone (parts.md) |
| Gateron KS-33 | `key-switches.pretty`: Gateron LowProfile, THT or HotSwap (Q1) | Real switch, 1:1 print |
| EC11 | KiCad stock `RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm` | Real encoder, 1:1 print |
| OLED | Our own 4-pin 2.54 mm header plus module outline on the silkscreen | Received module (pin order!) |
| Pull-ups | KiCad stock axial resistor (THT) | — |

## Habits
- Commit after each milestone: schematic done, footprints assigned, placement done, routing done.
  These give you restore points.
- Run ERC and DRC often, not just at the end.
- Don't hand-edit `.kicad_sch` or `.kicad_pcb` text files. Make changes in KiCad.
