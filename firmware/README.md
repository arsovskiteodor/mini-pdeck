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
2. Run `qmk new-keyboard`: name `minipad`, MCU **RP2040**, layout "none".
3. Move the generated folder into this repo, then link it back:
   - macOS / Linux:
     ```sh
     mv ~/qmk_firmware/keyboards/minipad firmware/qmk/minipad
     ln -s "$PWD/firmware/qmk/minipad" ~/qmk_firmware/keyboards/minipad
     ```
   - Windows (Command Prompt, not QMK MSYS): create a directory junction:
     ```bat
     mklink /J %USERPROFILE%\qmk_firmware\keyboards\minipad C:\path\to\repo\firmware\qmk\minipad
     ```
4. Build: `qmk compile -kb minipad -km default`. The `.uf2` file appears in `qmk_firmware/`.
5. Flash: hold BOOT, plug in, and drag the `.uf2` onto the `RPI-RP2` drive (or run `qmk flash`).

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
