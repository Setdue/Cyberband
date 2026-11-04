# Firmware

The tested virtual-prototype sketch and its Wokwi circuit files are in [wokwi](wokwi/).

The firmware reads a DHT22, renders Home/Wi-Fi/Battery screens on an SSD1306 OLED, passively scans the simulated Wi-Fi environment on request, and drives a piezo tone plus scan/haptic-indicator LEDs when a scan completes. GPIO 34 reads a simulation potentiometer; it is not connected to a physical battery monitor.

Open firmware/wokwi in Wokwi or copy its sketch.ino, diagram.json, and libraries.txt into an ESP32 Wokwi project. Use an ESP32 DevKit C V4 and serial monitor speed 115200 baud. Tested libraries are listed in libraries.txt.

Simulation test observations are recorded in ../documentation/SIMULATION-TESTS.md. The firmware has not been flashed onto physical hardware.
