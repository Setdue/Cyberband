# CyberBand — Smart Wearable Security Badge

CyberBand is a planned ESP32-based wearable badge for cybersecurity awareness. The concept combines passive discovery of nearby Wi-Fi networks with environmental readings, a small display, and user alerts.

## Project status

This repository currently contains planning and documentation scaffolding. Hardware details, compatibility, wiring, firmware, enclosure dimensions, and PCB design still need to be verified and developed. No completed circuit, test, or working build is claimed here.

## Planned subsystems

- **Controller and wireless:** ESP32 development board for the user interface and passive nearby Wi-Fi network discovery.
- **Display and controls:** Small OLED display and buttons for viewing information and navigating the interface.
- **Environmental sensing:** Temperature and humidity readings from a compatible sensor.
- **Alerts and power:** Visual, sound, or vibration alerts; portable power with battery monitoring.

These are requirements and candidate components, not a verified final bill of materials. Confirm exact parts, voltage levels, current draw, pin assignments, and library support before wiring or ordering replacements.

## Safety and privacy

The wireless feature is intended for passive, local awareness only. Do not use CyberBand to capture traffic, collect credentials, disrupt networks, or access systems without permission. Minimize retention of network identifiers and use the device only where scanning is permitted.

Check battery polarity, charging requirements, and voltage compatibility before connecting power. Validate the selected hardware and circuit before wearing the device.

## Repository layout

- `firmware/` — planned ESP32 firmware
- `hardware/schematics/` — circuit diagrams and wiring notes
- `hardware/pcb/` — PCB design files and fabrication notes
- `hardware/bom/` — bill of materials and part research
- `enclosure/` — enclosure CAD and fit notes
- `documentation/` — requirements, setup, and project notes
- `media/` — project photos and other approved media
- `JOURNAL.md` — Fallen-format project journal

## Getting started

There is no firmware to flash yet. Begin by checking the available components, confirming exact module variants and electrical requirements, then documenting a safe schematic before powering a circuit.

## Journal

See [JOURNAL.md](JOURNAL.md) for the project log. Time spent is left for the project author to record accurately.
