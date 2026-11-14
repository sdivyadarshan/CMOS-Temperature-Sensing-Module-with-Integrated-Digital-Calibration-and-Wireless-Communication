/*
  ESP32 Wi-Fi Temperature Monitoring Prototype
  Sensor: DS18B20 waterproof digital temperature sensor
  Data pin: GPIO 4
  Interface: One-Wire
  Web server: HTTP on port 80

  Before uploading:
  1. Replace YOUR_WIFI_SSID with your 2.4 GHz Wi-Fi network name.
  2. Replace YOUR_WIFI_PASSWORD with the network password.
  3. Install the OneWire and DallasTemperature libraries.

  Credentials are placeholders so private network details are not published.
*/

#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

// ====== Wi-Fi credentials ======
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ====== Objects ======
WiFiServer server(80);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// ====== Calibration offset ======
float offset = 0.0;   // Adjust after comparison with a reference thermometer

void setup() {
  Serial.begin(9600);

  // Start temperature sensor
  sensors.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start web server
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    sensors.requestTemperatures();
    float tempC = sensors.getTempCByIndex(0);
    float calibratedTemp = tempC + offset;

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<head><meta http-equiv='refresh' content='5'></head>");
    client.println("<body>");
    client.println("<h2>ESP32 Temperature Monitoring</h2>");
    client.print("<p>Temperature: ");
    client.print(calibratedTemp, 2);
    client.println(" &deg;C</p>");
    client.println("</body>");
    client.println("</html>");

    client.stop();
  }
}
