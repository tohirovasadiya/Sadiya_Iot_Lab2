#include <Arduino.h>
const int LIGHT = 33;

unsigned long lastSampleTime = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (millis() - lastSampleTime >= 1000) {
    lastSampleTime = millis();

    int minimum = 4095;
    int maximum = 0;
    long total = 0;

    for (int i = 0; i < 10; i++) {
      int value = analogRead(LIGHT);

      if (value < minimum) minimum = value;
      if (value > maximum) maximum = value;

      total += value;
    }

    int average = total / 10;

    Serial.print("min=");
    Serial.print(minimum);
    Serial.print(" max=");
    Serial.print(maximum);
    Serial.print(" avg=");
    Serial.println(average);
  }
}
