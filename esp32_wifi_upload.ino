#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak settings
const String CHANNEL_ID = "YOUR_CHANNEL_ID";
const String WRITE_API_KEY = "YOUR_WRITE_API_KEY";   // Write API Key, not Read!

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void loop() {
  // 1. Read all sensors (replace with your actual code)
  float temp = readDHTTemperature();    // from DHT
  float hum = readDHTHumidity();
  int soil = analogRead(SOIL_PIN);      // map to 0-100%
  int water = analogRead(WATER_PIN);    // map to 0-100%
  int light = analogRead(LIGHT_PIN);    // raw or lux
  int gateOpen = digitalRead(GATE_PIN); // 0 or 1
  int pumpOn = digitalRead(PUMP_PIN);   // 0 or 1

  // 2. Prepare ThingSpeak URL
  String url = "http://api.thingspeak.com/update?api_key=" + WRITE_API_KEY;
  url += "&field1=" + String(temp);
  url += "&field2=" + String(hum);
  url += "&field3=" + String(soil);
  url += "&field4=" + String(water);
  url += "&field5=" + String(light);
  url += "&field6=" + String(gateOpen);
  url += "&field7=" + String(pumpOn);

  // 3. Send HTTP GET request
  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.println("Data sent: " + http.getString());
  } else {
    Serial.println("Error sending data");
  }
  http.end();

  delay(15000); // ThingSpeak free account allows update every 15 seconds
}
