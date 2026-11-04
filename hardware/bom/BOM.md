# CyberBand virtual-prototype bill of materials

Counts below are the quantities in the Wokwi circuit. These entries identify simulator parts; they are not purchase confirmations or verified physical part selections.

| Qty | Simulated item | Role / interface | Physical selection status |
|---:|---|---|---|
| 1 | ESP32 DevKit C V4 | Controller; 3.3 V GPIO; Wi-Fi | Exact real board revision and power budget to confirm |
| 1 | SSD1306 128×64 I²C OLED | User display; address 0x3C; SDA GPIO 21, SCL GPIO 22 | Exact module supply and pull-up behavior to confirm |
| 1 | DHT22 | Temperature/humidity; data GPIO 23 | Exact bare-sensor or breakout variant and pull-up needs to confirm |
| 2 | Momentary pushbuttons | NEXT GPIO 18 and SCAN GPIO 19; active-low | Physical switch footprint and mounting to select |
| 1 | Piezo buzzer | Scan alert; GPIO 25 | Confirm passive/active type and whether a driver is needed |
| 1 | Potentiometer | Simulated battery input; SIG GPIO 34 | Simulation control only; physical battery measurement requires a separate divider design |
| 1 | Green LED | Scan indicator; GPIO 2 through series resistor | Select physical LED and verify current |
| 1 | Blue LED | Haptic-output stand-in; GPIO 26 through series resistor | Not a motor; physical motor and driver remain unselected |
| 2 | 1 kΩ resistors | LED current limiting, one per LED | Confirm resistor power rating and LED current for chosen parts |
| As needed | Jumper wires / breadboard | Virtual interconnections | Physical wiring materials not selected |

## Not represented by the simulation

- No LiPo cell, charging IC, protection circuit, or battery-monitor divider is modeled.
- No vibration motor, transistor/MOSFET driver, or motor protection part is modeled.
- No physical PCB, enclosure, or assembly materials are selected.

No prices, vendors, purchases, or physical verification are claimed. Research exact module datasheets and electrical limits before ordering or building.

## Research references

These references describe the ESP32 device and Wokwi's modeled components. They do not select a purchasable breakout board or validate its electrical behavior:

- [Espressif ESP32 datasheet](https://documentation.espressif.com/esp32_datasheet_en.html)
- [Espressif ESP32 GPIO guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html) — GPIO 34 is input-only, matching its use as the analog input.
- Wokwi: [ESP32 simulation](https://docs.wokwi.com/guides/esp32), [SSD1306](https://docs.wokwi.com/parts/board-ssd1306), [DHT22](https://docs.wokwi.com/parts/wokwi-dht22), [pushbutton](https://docs.wokwi.com/parts/wokwi-pushbutton), [buzzer](https://docs.wokwi.com/parts/wokwi-buzzer), [potentiometer](https://docs.wokwi.com/parts/wokwi-potentiometer), [LED](https://docs.wokwi.com/parts/wokwi-led), and [resistor](https://docs.wokwi.com/parts/wokwi-resistor).

Before ordering physical parts, use the datasheet for the exact board, OLED breakout, DHT22 module, buzzer, and selected battery/motor parts.
