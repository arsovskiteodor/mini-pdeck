# ADR-0001: MCU: RP2040-Zero clone, soldered on as a module

- **Status:** Accepted
- **Date:** 2026-10-28
- **Step:** 01 Lock the spec

## Context
The board needs native USB HID, 12 GPIO (4 keys, 2 encoders × A/B/push, 2 for I2C), and must be
hand-solderable on a first board. The goal is to learn PCB design, so the MCU circuitry
(flash, crystal, regulator, USB) should come ready-made. That leaves fewer unknowns
when something doesn't work.

## Options considered
| Option | For | Against |
|---|---|---|
| Bare RP2040 on our PCB | Cheapest per unit, teaches the full circuit | QFN package needs JLCPCB assembly; flash, crystal, regulator and USB are all new failure points. Good for v2. |
| Seeed XIAO RP2040 | Tiny, solders flat, well documented | Only 11 GPIO: not enough once the OLED and encoder pushes were added |
| Waveshare RP2040-Zero (original) | Documented dimensions | Costs more than the clones |
| **RP2040-Zero clone, DUBEUYEW 2-pack, €9.99** | About 20 edge GPIO, USB-C, fast delivery | Clone: dimensions not guaranteed; only one spare |
| RP2040-Zero clone, AYWHP 3-pack, €9.99 | Better value, two spares | Slower delivery (owner chose speed) |
| Pro Micro (ATmega32U4) | Classic keyboard MCU | Less flash, fragile micro-USB, older platform |
| ESP32-S3 | Wireless | Wireless not needed; adds complexity |

## Decision
Use an RP2040-Zero clone (DUBEUYEW 2-pack from Amazon) as a module soldered onto our PCB.

## Consequences
- The footprint starts from Waveshare's drawing but **must** be checked against the measured clone.
- GP16 drives the onboard WS2812 RGB LED, so don't assign it to anything else (it can show the current layer).
- The BOOT button must stay reachable in the case, or Bootmagic must be configured in QMK.
- Only one spare: solder headers to one board only, and keep the other bare for flat mounting (STATUS Q4).

## Revisit if
- The clone's dimensions or pin positions don't match the footprint.
- For v2: switch to a bare RP2040 with JLCPCB assembly.

## Sources
- Waveshare RP2040-Zero wiki: https://www.waveshare.com/wiki/RP2040-Zero
- RP2040 datasheet: https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf
- Lectronz clone listing (dimensions not confirmed against the original): https://lectronz.com/products/rp2040-zero-clone
