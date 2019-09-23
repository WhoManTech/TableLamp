#include <Arduino.h>

#define LAMP_SETT_PIN 2
#define PIR_PIN 3

int bright;

void setup() {
  pinMode(LAMP_SETT_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  bright = map(analogRead(LAMP_SETT_PIN), 0, 1023, 0, 255);
  
}