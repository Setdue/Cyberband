#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHTesp.h>

// CyberBand virtual prototype: passive Wi-Fi discovery, environment, display, alerts.
// It never connects to scanned networks or captures traffic.
constexpr int PIN_SCAN_LED = 2, PIN_DHT = 23, PIN_NEXT = 18, PIN_SCAN = 19;
constexpr int PIN_BUZZER = 25, PIN_HAPTIC_LED = 26, PIN_BATTERY_SIM = 34;
constexpr int PIN_SDA = 21, PIN_SCL = 22, SCREEN_W = 128, SCREEN_H = 64;
constexpr unsigned long SENSOR_INTERVAL = 2200;
Adafruit_SSD1306 display(SCREEN_W, SCREEN_H, &Wire, -1);
DHTesp dht;
enum Screen : uint8_t { HOME, WIFI, BATTERY };
Screen screen = HOME;
float tempC = NAN, humidity = NAN;
int batteryPercent = 0, networkCount = -1, openNetworkCount = 0, firstRssi = 0;
String firstSsid;
bool nextWasDown = false, scanWasDown = false;
unsigned long lastNext = 0, lastScan = 0, lastSensorRead = 0, lastRefresh = 0;
unsigned long scanLedOffAt = 0, hapticLedOffAt = 0;

void updateBatterySimulation() {
  // Potentiometer is a Wokwi control, not a physical battery connection.
  batteryPercent = constrain((analogRead(PIN_BATTERY_SIM) * 100L) / 4095L, 0, 100);
}
void readEnvironment() {
  TempAndHumidity r = dht.getTempAndHumidity();
  if (!isnan(r.temperature) && !isnan(r.humidity)) { tempC = r.temperature; humidity = r.humidity; }
}
void batteryIcon() {
  display.drawRect(103, 2, 22, 10, SSD1306_WHITE); display.fillRect(125, 5, 2, 4, SSD1306_WHITE);
  int w = map(batteryPercent, 0, 100, 0, 16); if (w > 0) display.fillRect(106, 5, w, 4, SSD1306_WHITE);
}
void drawHome() {
  display.clearDisplay(); display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 3); display.print("CYBERBAND"); batteryIcon(); display.drawFastHLine(0, 15, 128, SSD1306_WHITE);
  display.setCursor(0, 23); display.print("TEMP: "); if (isnan(tempC)) display.print("--.- C"); else { display.print(tempC, 1); display.print(" C"); }
  display.setCursor(0, 36); display.print("HUM:  "); if (isnan(humidity)) display.print("-- %"); else { display.print(humidity, 0); display.print(" %"); }
  display.setCursor(0, 53); display.print("N: next   S: scan"); display.display();
}
void drawWifi() {
  display.clearDisplay(); display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 3); display.print("PASSIVE WI-FI"); display.drawFastHLine(0, 15, 128, SSD1306_WHITE);
  display.setCursor(0, 23);
  if (networkCount < 0) { display.print("Press S to scan"); display.setCursor(0, 39); display.print("Nearby networks"); }
  else {
    display.print("Networks: "); display.print(networkCount); display.setCursor(0, 35); display.print("Open: "); display.print(openNetworkCount);
    display.setCursor(0, 47);
    if (networkCount == 0) display.print("No networks found");
    else { display.print(firstSsid.substring(0, 13)); display.print(" "); display.print(firstRssi); display.print("dBm"); }
  }
  display.setCursor(0, 57); display.print("S: rescan"); display.display();
}
void drawBattery() {
  display.clearDisplay(); display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 3); display.print("POWER STATUS"); display.drawFastHLine(0, 15, 128, SSD1306_WHITE);
  display.setCursor(0, 25); display.print("Simulated level: "); display.print(batteryPercent); display.print("%");
  display.drawRect(8, 42, 108, 13, SSD1306_WHITE); int w = map(batteryPercent, 0, 100, 0, 100);
  if (w > 0) display.fillRect(12, 46, w, 5, SSD1306_WHITE);
  display.setCursor(0, 58); display.print("Turn pot to change"); display.display();
}
void drawScreen() { if (screen == HOME) drawHome(); else if (screen == WIFI) drawWifi(); else drawBattery(); }
void signalScanComplete() {
  tone(PIN_BUZZER, 1750, 100); digitalWrite(PIN_SCAN_LED, HIGH); digitalWrite(PIN_HAPTIC_LED, HIGH);
  scanLedOffAt = millis() + 130; hapticLedOffAt = millis() + 130;
}
void scanWifi() {
  screen = WIFI; networkCount = -1; firstSsid = ""; drawScreen();
  Serial.println("Starting passive Wi-Fi scan..."); WiFi.mode(WIFI_STA); WiFi.disconnect(); delay(100);
  int found = WiFi.scanNetworks(false, true); networkCount = found > 0 ? found : 0; openNetworkCount = 0; firstRssi = 0;
  if (found > 0) {
    firstSsid = WiFi.SSID(0); firstRssi = WiFi.RSSI(0);
    for (int i = 0; i < found; i++) if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) openNetworkCount++;
  } else firstSsid = "";
  WiFi.scanDelete();
  Serial.print("Scan complete: "); Serial.print(networkCount); Serial.print(" network(s), ");
  Serial.print(openNetworkCount); Serial.println(" open"); signalScanComplete(); drawScreen();
}
void setup() {
  Serial.begin(115200); pinMode(PIN_SCAN_LED, OUTPUT); pinMode(PIN_HAPTIC_LED, OUTPUT);
  pinMode(PIN_NEXT, INPUT_PULLUP); pinMode(PIN_SCAN, INPUT_PULLUP); pinMode(PIN_BATTERY_SIM, INPUT);
  Wire.begin(PIN_SDA, PIN_SCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { Serial.println("ERROR: SSD1306 not detected at 0x3C"); while (true) delay(100); }
  dht.setup(PIN_DHT, DHTesp::DHT22); WiFi.mode(WIFI_STA); WiFi.disconnect();
  display.clearDisplay(); display.setTextColor(SSD1306_WHITE); display.setTextSize(1); display.setCursor(0, 20);
  display.println("CYBERBAND"); display.println("Starting..."); display.display();
  Serial.println("CyberBand simulation ready"); delay(500); readEnvironment(); updateBatterySimulation(); drawScreen();
}
void loop() {
  unsigned long now = millis();
  if (now - lastSensorRead >= SENSOR_INTERVAL) { lastSensorRead = now; readEnvironment(); updateBatterySimulation(); }
  bool nextDown = digitalRead(PIN_NEXT) == LOW;
  if (nextDown && !nextWasDown && now - lastNext > 35) { screen = static_cast<Screen>((screen + 1) % 3); lastNext = now; drawScreen(); }
  nextWasDown = nextDown;
  bool scanDown = digitalRead(PIN_SCAN) == LOW;
  if (scanDown && !scanWasDown && now - lastScan > 35) { lastScan = now; scanWifi(); }
  scanWasDown = scanDown;
  if (scanLedOffAt && now >= scanLedOffAt) { digitalWrite(PIN_SCAN_LED, LOW); scanLedOffAt = 0; }
  if (hapticLedOffAt && now >= hapticLedOffAt) { digitalWrite(PIN_HAPTIC_LED, LOW); hapticLedOffAt = 0; }
  if (now - lastRefresh >= 300) { lastRefresh = now; updateBatterySimulation(); drawScreen(); }
}
