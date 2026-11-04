# CyberBand virtual-circuit connections

These connections describe the tested Wokwi diagram in [firmware/wokwi/diagram.json](../../firmware/wokwi/diagram.json). They record simulator wiring, not a physically validated circuit.

| Part | Wokwi connection | Notes |
|---|---|---|
| SSD1306 OLED | SDA → GPIO 21; SCL → GPIO 22; VCC → VIN; GND → GND | I²C address 0x3C. Check actual module voltage and pull-ups before physical wiring. |
| DHT22 | SDA/data → GPIO 23; VCC → 3V3; GND → GND | Simulation starts at 24 °C and 45% humidity. Check whether a real sensor module includes the required data pull-up. |
| NEXT button | GPIO 18 to GND | Active-low; firmware enables the internal pull-up. Wokwi key N. |
| SCAN button | GPIO 19 to GND | Active-low; firmware enables the internal pull-up. Wokwi key S. |
| Piezo buzzer | Pin 2 → GPIO 25; pin 1 → GND | Firmware requests a 1750 Hz, 100 ms tone after a scan. Confirm physical buzzer type and drive needs. |
| Battery simulation potentiometer | SIG → GPIO 34; VCC → 3V3; GND → GND | Simulator control only; not a battery divider. |
| Green scan LED | GPIO 2 → 1 kΩ resistor → LED anode; LED cathode → GND | Brief scan indicator. |
| Blue haptic-indicator LED | GPIO 26 → 1 kΩ resistor → LED anode; LED cathode → GND | Visual stand-in for a future motor driver output. |

## Physical-design checks

- ESP32 GPIO is 3.3 V logic. The simulated OLED is powered from VIN; verify the real module’s I²C pull-ups do not pull SDA/SCL above safe ESP32 levels.
- GPIO 34 is input-only and is used only for the simulation potentiometer here. A physical battery monitor needs a properly calculated divider, calibration, and a protected battery/charging design.
- A physical vibration motor must not be driven directly from an ESP32 GPIO. Select a suitable transistor or MOSFET stage and protection after choosing the motor.
- Confirm button, sensor, buzzer, and board variants before building.

## Simulator references

- [Wokwi ESP32 simulation](https://docs.wokwi.com/guides/esp32)
- [Wokwi SSD1306 part](https://docs.wokwi.com/parts/board-ssd1306)
- [Wokwi DHT22 controls](https://docs.wokwi.com/parts/wokwi-dht22)
- [Wokwi pushbutton behavior](https://docs.wokwi.com/parts/wokwi-pushbutton)
- [Wokwi potentiometer range](https://docs.wokwi.com/parts/wokwi-potentiometer)
- [Espressif GPIO reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html)
