#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASS";

WebServer server(80);
const int relayPin = 5;

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(1000);

  server.on("/", []() {
    server.send(200, "text/html", "<h1>Light Control</h1><a href='/on'>ON</a> | <a href='/off'>OFF</a>");
  });

  server.on("/on", []() {
    digitalWrite(relayPin, HIGH);
    server.send(200, "text/plain", "Light ON");
  });

  server.on("/off", []() {
    digitalWrite(relayPin, LOW);
    server.send(200, "text/plain", "Light OFF");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
