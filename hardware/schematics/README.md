# Schematics and wiring

The repository includes a Wokwi circuit definition and its GPIO map. The simulated circuit was run with the ESP32 firmware; see [CONNECTIONS.md](CONNECTIONS.md) and [firmware/wokwi/diagram.json](../../firmware/wokwi/diagram.json).

This is not a reviewed physical schematic. Check the exact display module's supply and I²C pull-ups, DHT22 pull-up needs, buzzer drive, and all power and current limits before building.
