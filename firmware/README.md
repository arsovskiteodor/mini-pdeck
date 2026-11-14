# Firmware (QMK)

The keyboard definition lives in this repo at `firmware/qmk/minipad/`. QMK builds keyboards from
inside its own `qmk_firmware/keyboards/` folder, so we link our folder in there. QMK's
External Userspace documentation only covers keymaps for keyboards QMK already has, which is why we link.

## One-time setup
1. Install QMK. Follow the "Newbs" guide at https://docs.qmk.fm (Windows: QMK MSYS;
   macOS/Linux: the `qmk` CLI), then run `qmk setup`.
2. Prove the toolchain works: compile any existing RP2040-based keyboard from the QMK repo.
   If that works, later build errors come from our config, not the install.

## Create the keyboard (step 04)
1. Check the name is free: `ls ~/qmk_firmware/keyboards/minipad` should not exist.
2. Write `keyboard.json` and `keymaps/default/keymap.c` by hand in `firmware/qmk/minipad/`
   (owner, 2026-11-11). `qmk new-keyboard` was not used: its template has AVR pins and a diode matrix,
   which would all need rewriting for an RP2040 with direct pins.
3. Link the folder into QMK:
   - macOS / Linux:
     ```sh
     ln -s "$PWD/firmware/qmk/minipad" ~/qmk_firmware/keyboards/minipad
     ```
   - Windows (Command Prompt, not QMK MSYS): create a directory junction:
     ```bat
     mklink /J %USERPROFILE%\qmk_firmware\keyboards\minipad C:\path\to\repo\firmware\qmk\minipad
     ```
4. Build: from the repo root, `wsl bash firmware/build.sh` (or `bash firmware/build.sh` inside WSL).
   It runs `qmk compile -kb minipad -km default` in WSL and copies the result to
   `firmware/out/minipad_default.uf2` (ignored by git). QMK is installed in WSL (Ubuntu), not QMK MSYS:
   on this PC Windows refuses to start QMK MSYS's `collect2.exe` and `git.exe` ("Permission denied",
   2026-11-11, cause not yet found).
5. Flash: hold BOOT, plug in, and drag the `.uf2` onto the `RPI-RP2` drive.

## QMK version
Our files are the only project files: `~/qmk_firmware/keyboards/minipad` in WSL is a symlink to
`firmware/qmk/minipad/` in this repo (checked 2026-11-14), and the rest of `~/qmk_firmware` is QMK's own code.
To rebuild exactly what was flashed, use the same QMK commit.

| Date | QMK commit | What was built |
|---|---|---|
| 2026-11-14 | `d194c077ed` (`0.34.7-3-gd194c077ed`, master, commit date 2026-11-08) | K1–K4 a–d, OLED status screen, breathing D1–D4. Works on Rev A (owner, 2026-11-14) |

Check yours with `git -C ~/qmk_firmware describe --tags`. Go back to a listed commit with
`git -C ~/qmk_firmware checkout <commit> && qmk git-submodule`.

## Configuration notes
- Pins come from `docs/hardware/pinout.md`. Don't invent them here.
- Prefer data-driven config in `keyboard.json` (`matrix_pins.direct`, `encoder.rotary`, features).
  Use `config.h` only for what JSON can't express.
- **OLED on RP2040:** enable QMK's I2C driver for the RP2040 and set the SDA/SCL pins.
  Follow the "Raspberry Pi RP2040" platform page and the "OLED Driver" page in the QMK docs.
- **Bootmagic:** enable it so a key held while plugging in enters the bootloader once the board is in its case.
- **USB vendor/product IDs:** the defaults are fine for a personal board. VIA needs its definition to match them (ADR-0008).
- **GP16:** onboard WS2812 LED. It can show the current layer later.

## Planned layout
```
firmware/qmk/minipad/
├── keyboard.json          # hardware: MCU, pins, encoders, features
├── config.h               # only what keyboard.json can't express (e.g. I2C pins)
├── halconf.h / mcuconf.h  # enable I2C for RP2040 (per QMK RP2040 docs)
└── keymaps/
    ├── default/keymap.c   # step 04
    └── via/               # ADR-0008, after the board works
```
