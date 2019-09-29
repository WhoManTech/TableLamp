#include <Arduino.h>

#define LAMP_SETT_PIN 1
#define PIR_PIN 3
#define LAMP_PIN 0
#define FAN_PIN 4
#define FAN_SETT_PIN 5

int bright;
int fan_speed;



void setup() {
  pinMode(LAMP_SETT_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(LAMP_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(FAN_SETT_PIN, INPUT);
}



void loop(){
  bright = map(analogRead(LAMP_SETT_PIN), 0, 1023, 0, 255);
  if(digitalRead(PIR_PIN) == 1){
    digitalWrite(FAN_PIN, HIGH);
  }
  else{
    digitalWrite(FAN_PIN, LOW);
  }
  analogWrite(LAMP_PIN, bright);
}