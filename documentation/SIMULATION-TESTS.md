# Wokwi simulation verification

**Run date:** 2026-11-04  
**Target:** ESP32 DevKit C V4 in Wokwi  
**Result:** Firmware compiled and ran in the simulator.

## Observations

| Check | Result |
|---|---|
| Boot | Serial monitor printed CyberBand simulation ready. |
| OLED | SSD1306 initialized at I²C address 0x3C and displayed the CyberBand home screen. |
| DHT22 | Home screen showed configured values of 24.0 °C and 45% humidity. |
| Passive Wi-Fi scan | SCAN completed; serial monitor reported one simulated network and one open network. OLED showed the scan result. The network was Wokwi-GUEST. |
| Screen navigation | NEXT opened the Battery screen. |
| Simulated battery input | Potentiometer minimum and maximum displayed 0% and 100%. |

The scan-complete firmware requests a 1750 Hz tone for 100 ms and turns on the scan and haptic-indicator LEDs for 130 ms. The browser-based run did not separately measure the audible tone or capture the brief LED pulses.

## Scope

This run validates the sketch against Wokwi's virtual components and simulated Wi-Fi environment only. It does not validate nearby physical networks, physical voltage levels, current draw, RF behavior, sensor accuracy, a battery circuit, vibration motor operation, soldering, PCB layout, enclosure fit, or wearability. No physical hardware test was performed.
