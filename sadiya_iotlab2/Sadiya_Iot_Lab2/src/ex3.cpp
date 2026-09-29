#include <Arduino.h>

const int LIGHT = 33;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int reading = analogRead(LIGHT);

  Serial.print("LIGHT=");
  Serial.println(reading);

  delay(300);
}