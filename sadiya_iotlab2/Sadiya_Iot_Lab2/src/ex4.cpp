


#include "Arduino.h"

const int RED = 26;
const int GREEN = 27;
const int YELLOW = 12;
const int BLUE = 14;

const int BUTTON = 25;

const int leds[] = {RED, GREEN, YELLOW, BLUE};

int count = 0;
int lastButtonState = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  pinMode(BUTTON, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON);

  // Rising-edge detection: LOW -> HIGH
  if (buttonState == HIGH && lastButtonState == LOW) {
    count++;

    if (count > 4) {
      count = 0;
    }

    Serial.print("count=");
    Serial.println(count);

    // Turn all LEDs off first
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }

    // Turn on exactly 'count' LEDs
    for (int i = 0; i < count; i++) {
      digitalWrite(leds[i], HIGH);
    }
  }

  lastButtonState = buttonState;
}