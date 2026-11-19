# ADR-0002: Switches: Gateron KS-33 Low Profile 2.0 Red Silent

- **Status:** Accepted
- **Date:** 2026-10-28
- **Step:** 02 Pick switches and mounting

## Context
The owner wants a low-profile look. The choice of switch family fixes the footprint,
the keycaps, the hot-swap sockets and the case height.

## Options considered
| Option | For | Against |
|---|---|---|
| MX-compatible | Most footprints, sockets and keycaps; most guides | Tall; not the look the owner wants |
| Kailh Choc v1 | The common low-profile standard for DIY keyboards | Own footprint and keycaps |
| **Gateron KS-33 Low Profile 2.0** | Low profile; linear and silent; 35 for €15.26 | Own footprint (not MX, not Choc); needs matching low-profile keycaps; hot-swap needs Gateron's own sockets |

## Decision
Gateron KS-33 Low Profile 2.0 Red Silent (linear, 45 gf), 35 pieces from Amazon.

## Consequences
- **Footprint:** Gateron low-profile, shared by KS-27 and KS-33. Source: `siderakb/key-switches.pretty`
  (soldered and hot-swap variants). Verify it against a real switch in step 07.
- The Amazon listing says "for MX mechanical keyboard". That's wrong; Keebio says these
  don't fit MX or Choc boards.
- Keycaps must fit KS-33. The owner has chosen a model; record it in `parts.md` (STATUS Q8).
- Hot-swap or soldered is still open (STATUS Q1). Hot-swap needs Gateron low-profile sockets.
- The encoder knobs will sit higher than the keys (STATUS Q6).

## Revisit if
- The keycaps don't fit, or the footprint doesn't match the real switch.

## Sources
- Keebio KS-33 page (footprint compatibility): https://keeb.io/products/gateron-ks-33-low-profile-2-0-switches
- beekeeb Gateron low-profile socket (not compatible with Choc or MX): https://shop.beekeeb.com/products/gateron-low-profile-hotswap-socket-compatible-with-gateron-ks-27-switches-5pcs
- KiCad footprints: https://github.com/siderakb/key-switches.pretty
