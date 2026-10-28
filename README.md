# Minipad

A small USB macropad: 4 low-profile keys, 2 rotary encoders with push buttons and a
0.96" OLED, on a custom 2-layer PCB. It's a learning project covering the full path
from part selection to a working board: KiCad schematic and layout, JLCPCB
fabrication, QMK firmware and, later, a PC app for remapping keys.

**Status:** see [STATUS.md](STATUS.md).

## Hardware at a glance
| Part | Choice | Why (ADR) |
|---|---|---|
| MCU | RP2040-Zero (clone), soldered on as a module | [0001](docs/decisions/0001-mcu-rp2040-zero-module.md) |
| Switches | Gateron KS-33 Low Profile 2.0 Red Silent | [0002](docs/decisions/0002-switches-gateron-ks33-low-profile.md) |
| Encoders | EC11 with push switch, 20 detents | [0003](docs/decisions/0003-encoders-ec11-with-push.md) |
| Display | 0.96" 128×64 SSD1306, I2C | [0004](docs/decisions/0004-oled-ssd1306-i2c.md) |
| Firmware | QMK, with VIA for remapping | [0005](docs/decisions/0005-firmware-qmk.md), [0008](docs/decisions/0008-remapping-via-then-own-app.md) |
| PCB | JLCPCB, 2 layers, at most 100 × 100 mm, through-hole only | [0007](docs/decisions/0007-fab-jlcpcb-2layer-tht.md) |

Full parts list: [docs/hardware/parts.md](docs/hardware/parts.md).

## Repository layout
```
.
├── CLAUDE.md                 # Instructions Claude Code loads every session
├── STATUS.md                 # Where the project is right now (single source of truth)
├── .claude/
│   ├── settings.json         # Permissions: what Claude may run without asking
│   ├── rules/                # Rules that load only when Claude touches matching files
│   ├── skills/               # Slash commands: /where-are-we, /log-session, /decision, ...
│   └── agents/               # design-reviewer: independent review before gates
├── docs/
│   ├── phases/               # The 13 steps in 4 phases, with exit criteria
│   ├── decisions/            # ADRs: what we chose, what we rejected and why
│   ├── log/                  # One file per day, append-only
│   └── hardware/             # Parts, pinout, mechanical, fabrication, bring-up
├── hardware/kicad/           # KiCad project and project-local libraries
├── firmware/qmk/minipad/     # QMK keyboard definition (created in step 04)
└── case/                     # Enclosure files (step 13)
```

## Getting started
```sh
git init
git add .
git commit -m "repo: initial project structure"
# Step 07: add the low-profile switch footprint library as a submodule
git submodule add https://github.com/siderakb/key-switches.pretty hardware/kicad/lib/third_party/key-switches.pretty
```

The name `minipad` is a placeholder used for the KiCad project and the QMK keyboard.
To rename it, search and replace `minipad` across the repo before creating those files.

## Working with Claude Code
Run `claude` from the repository root.

| Command | When |
|---|---|
| `/where-are-we` | Start of a session |
| `/check-part <part>` | Evaluating a listing, or when a part arrives |
| `/decision <title>` | After choosing between real alternatives |
| `/gate` | When you think a step is done |
| `/pre-order` | Step 10, before ordering the PCB |
| `/log-session` | End of a session |

Commit messages: `area: summary`, where area is `hw`, `fw`, `docs`, `case` or `repo`.
Example: `hw: add verified EC11 footprint`.
