#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>

// GSM pins (example)
#define MODEM_RX 16
#define MODEM_TX 17
#define MODEM_RST 5

const char apn[] = "your_apn";        // from your SIM provider
const char gprsUser[] = "";
const char gprsPass[] = "";

TinyGsm modem(Serial2);   // use Serial2 connected to GSM module
TinyGsmClient client(modem);

const char* server = "api.thingspeak.com";
const int port = 80;
String WRITE_API_KEY = "YOUR_WRITE_API_KEY";

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);
  modem.restart();
  modem.waitForNetwork();
  modem.gprsConnect(apn, gprsUser, gprsPass);
}

void loop() {
  // Read sensors as before...
  float temp = 30.5; // example

  String postData = "api_key=" + WRITE_API_KEY +
                    "&field1=" + String(temp) +   // add all fields
                    "&field2=" + String(hum) + "...";
  
  if (!client.connect(server, port)) {
    Serial.println("Connection failed");
    return;
  }
  
  client.print(String("POST /update HTTP/1.1\r\n"));
  client.print(String("Host: ") + server + "\r\n");
  client.print("Content-Type: application/x-www-form-urlencoded\r\n");
  client.print("Content-Length: " + String(postData.length()) + "\r\n");
  client.print("\r\n");
  client.print(postData);
  
  // Read response
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") break;
  }
  String response = client.readString();
  Serial.println(response);
  client.stop();
  
  delay(15000);
}
