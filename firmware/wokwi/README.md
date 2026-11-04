# Wokwi prototype files

This folder contains the firmware and circuit definition used for the CyberBand virtual prototype.

## Run

1. Open a new ESP32 project in Wokwi.
2. Add sketch.ino, diagram.json, and libraries.txt from this folder.
3. Run the simulation and open the serial monitor at 115200 baud.
4. Click NEXT or press N to cycle Home → Wi-Fi → Battery.
5. Click SCAN or press S to run a passive simulated Wi-Fi scan.
6. Adjust the potentiometer to change the simulated battery level. Open the DHT22 component to change its sensor values.

## Modeled components

ESP32 DevKit C V4, SSD1306 128×64 OLED at 0x3C, DHT22, two pushbuttons, piezo buzzer, potentiometer, green scan LED, blue haptic-indicator LED, and two 1 kΩ resistors.

This is a simulator design. The potentiometer is not a battery circuit and the blue LED is not a vibration motor. Check physical module voltages and I²C pull-ups before wiring. Test results are in ../../documentation/SIMULATION-TESTS.md.

## Component references

See the official Wokwi references for the [ESP32](https://docs.wokwi.com/guides/esp32), [SSD1306](https://docs.wokwi.com/parts/board-ssd1306), [DHT22](https://docs.wokwi.com/parts/wokwi-dht22), [buttons](https://docs.wokwi.com/parts/wokwi-pushbutton), [buzzer](https://docs.wokwi.com/parts/wokwi-buzzer), [potentiometer](https://docs.wokwi.com/parts/wokwi-potentiometer), [LEDs](https://docs.wokwi.com/parts/wokwi-led), and [resistors](https://docs.wokwi.com/parts/wokwi-resistor).
