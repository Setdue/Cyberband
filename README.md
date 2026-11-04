# CyberBand — ESP32 wearable cyber-awareness band

CyberBand is a wearable status-band concept for cybersecurity awareness. Its ESP32 virtual prototype combines temperature and humidity readings, an OLED interface, passive Wi-Fi discovery, and simple scan alerts.

## Project status

A Wokwi virtual prototype has been implemented and exercised. The simulation firmware compiles and runs with the modeled components described below. No physical circuit has been assembled or tested. A production battery circuit, vibration motor driver, PCB, and enclosure remain unbuilt.

## What the virtual prototype does

- Shows temperature and humidity from a DHT22 on an SSD1306 OLED.
- Uses NEXT to cycle through Home, Wi-Fi, and Battery screens.
- Uses SCAN to passively discover networks in Wokwi’s simulated environment.
- Reports the network count, open-network count, and first network’s signal strength.
- Uses a potentiometer as a simulated battery-level input.
- Commands a piezo tone and green/blue LED indicators after a scan. The blue LED stands in for a vibration motor.

The Wi-Fi code disconnects before scanning. It does not join scanned networks, capture traffic, collect credentials, or store scan history.

## Simulation and verification

The Wokwi files are in [firmware/wokwi](firmware/wokwi). The simulation was exercised on 2026-11-04:

- Firmware compiled and booted; the serial monitor reported CyberBand simulation ready.
- The OLED initialized and showed the DHT22’s configured 24.0 °C and 45% humidity.
- A passive simulated scan found one network, Wokwi-GUEST, and reported it as open.
- NEXT opened the battery screen. The potentiometer endpoints displayed 0% and 100%.

The scan completion handler issues a 1750 Hz, 100 ms tone and drives both indicator LEDs for 130 ms. Their command path is present in the exercised firmware; audible buzzer output and the brief LED pulses were not independently measured.

The Wokwi project reference is [project 479775195076006913](https://wokwi.com/projects/479775195076006913). The editor showed Sign In when the simulation was tested, so its latest edits were not saved to Wokwi. The repository files are the reproducible source for this revision; save the editor after signing in before relying on that Wokwi link to show these changes.

## Pin map

| Function | ESP32 GPIO / connection |
|---|---|
| OLED SDA / SCL | GPIO 21 / GPIO 22; I²C address 0x3C |
| DHT22 data | GPIO 23 |
| NEXT / SCAN buttons | GPIO 18 / GPIO 19 to GND, active-low with internal pull-ups |
| Piezo buzzer | GPIO 25 and GND |
| Simulated battery potentiometer | GPIO 34 signal; 3V3 and GND |
| Scan indicator | GPIO 2 through 1 kΩ to green LED; LED cathode to GND |
| Haptic stand-in | GPIO 26 through 1 kΩ to blue LED; LED cathode to GND |

## Use the Wokwi files

Open an ESP32 project in Wokwi, then add the files from firmware/wokwi: sketch.ino, diagram.json, and libraries.txt. The simulation uses an ESP32 DevKit C V4 and these libraries:

- Adafruit SSD1306
- Adafruit GFX Library
- DHT sensor library for ESPx

Open the serial monitor at 115200 baud. Press N or click NEXT to change screens. Press S or click SCAN to scan. Adjust the potentiometer for simulated battery level. The DHT22 component can be opened in Wokwi to change its sensor values.

## Physical-build notes

- The Wokwi OLED is powered from VIN. Before wiring a real display, check the exact module’s allowed supply voltage and I²C pull-up voltage. Keep ESP32 GPIO at 3.3 V levels.
- The potentiometer only stands in for battery monitoring. Do not connect a LiPo cell directly to GPIO 34. A physical design needs a calculated voltage divider, ADC calibration, charging/protection components, and battery testing.
- The blue LED is not a motor. A real vibration motor needs a suitable transistor or MOSFET driver and protection selected for the motor.
- Verify the exact DHT22 module, pull-up requirements, buzzer type, current draw, and power budget before ordering or powering hardware.
- The simulation does not validate physical RF performance, electrical safety, soldering, enclosure fit, or battery behavior.

## Repository map

- [firmware](firmware/README.md) — virtual-prototype firmware and Wokwi files
- [hardware](hardware/README.md) — simulation wiring, component list, and future hardware work
- [simulation verification](documentation/SIMULATION-TESTS.md)
- [Fallen journal](JOURNAL.md)
- [enclosure](enclosure/README.md) and [PCB](hardware/pcb/README.md) — not designed yet
- [media](media/README.md) — add only approved project progress media

## References

- [Espressif ESP32 datasheet](https://documentation.espressif.com/esp32_datasheet_en.html) and [ESP32 GPIO guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html)
- Wokwi references: [ESP32 simulation](https://docs.wokwi.com/guides/esp32), [SSD1306 OLED](https://docs.wokwi.com/parts/board-ssd1306), [DHT22](https://docs.wokwi.com/parts/wokwi-dht22), [pushbutton](https://docs.wokwi.com/parts/wokwi-pushbutton), [buzzer](https://docs.wokwi.com/parts/wokwi-buzzer), [potentiometer](https://docs.wokwi.com/parts/wokwi-potentiometer), [LED](https://docs.wokwi.com/parts/wokwi-led), and [resistor](https://docs.wokwi.com/parts/wokwi-resistor).
