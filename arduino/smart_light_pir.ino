int pirPin = 7;
int relayPin = 8;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  if (motion == HIGH) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Κίνηση ανιχνεύτηκε!");
    delay(10000);
  } else {
    digitalWrite(relayPin, LOW);
  }
}
