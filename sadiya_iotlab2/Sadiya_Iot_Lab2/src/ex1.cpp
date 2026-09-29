#include <Arduino.h>

const int RED = 26;
const int GREEN = 27;
const int YELLOW = 12;
const int BLUE = 14;

const int leds[] = {RED, GREEN, YELLOW, BLUE, YELLOW, GREEN};
const char* names[] = {"RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"};

int stepIndex = 0;

void setup() {
  Serial.begin(115200);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(BLUE, LOW);

  digitalWrite(leds[stepIndex], HIGH);

  Serial.print("chase=");
  Serial.println(names[stepIndex]);

  stepIndex++;
  if (stepIndex >= 6) {
    stepIndex = 0;
  }

  delay(150);
}