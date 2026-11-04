---
title: "CyberBand — ESP32 Wearable Cyber-Awareness Band"
github: "https://github.com/Setdue/Cyberband"
description: "A virtual ESP32 wearable prototype with environmental sensing, OLED feedback, passive Wi-Fi discovery, and simulated battery status."
created_at: "2026-11-02"
---

# Journal

## Entry 1: 2026-11-02

- **Time Spent:** [Add actual time spent]
- **What I did:** Began planning CyberBand and identified the project requirements: an ESP32 controller, a small display, an environmental sensor, user alerts, and portable power.
- **What I learned:** The exact board and component variants, voltage levels, pin assignments, and power requirements need to be checked before making a physical circuit.
- **Current status:** Planning and component research.

## Entry 2: 2026-11-04

- **Time Spent:** [Add actual time spent]
- **What I did:** With AI assistance, created a Wokwi virtual prototype using an ESP32 DevKit C V4, SSD1306 OLED, DHT22, two buttons, piezo buzzer, potentiometer, two indicator LEDs, and two 1 kΩ resistors. Added Home, passive Wi-Fi, and Battery screens.
- **What I learned:** The OLED works with I²C on GPIO 21 and 22 when the Wokwi diagram uses numeric GPIO pin references. The potentiometer can exercise battery-display endpoints without pretending that a real battery monitor has been built.
- **Simulation check:** Wokwi compiled and booted the firmware. The display showed 24.0 °C and 45% humidity; a passive scan reported one simulated open network; and the battery screen showed 0% and 100% at the potentiometer endpoints.
- **Current status:** Virtual prototype exercised; no physical hardware has been assembled or tested.
- **Next steps:** Save the Wokwi editor revision after signing in; confirm physical module voltage and pull-ups; research and select real battery and vibration-drive circuits; then review a physical schematic before assembly.
