#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);
  if (!bme.begin(0x76)) {
    Serial.println("BME280 δεν βρέθηκε!");
    while (1);
  }
}

void loop() {
  Serial.print("Θερμοκρασία: ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Υγρασία: ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  delay(2000);
}
