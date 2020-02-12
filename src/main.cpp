#include <Arduino.h>
#include <OneButton.h>

#include "main.h"
#include "light.h"
#include "fan.h"

OneButton button(BUTT_PIN, false);
Light lamp(LAMP_PIN, LAMP_SETT_PIN);
Fan fan(FAN_PIN);

unsigned long timer;
unsigned long search_timer;

int bright;
int move_inf;

bool light_flag = true;
bool fan_flag = false;
bool effect_flag;
bool search_flag;




void click1(){
  if (lamp.isOn()) {
    lamp.off();
    fan.off();
  }
  else {
    lamp.on();
  }
}

void doubleClick(){
  if (fan.isOn()) {
    fan.off();
  }
  else {
    fan.on();
  }
}



void setup(){
  button.attachClick(click1);
  button.attachDoubleClick(doubleClick);
}



void loop(){
  button.tick();
  lamp.update();
  fan.update(lamp.getBrightness());


  if (lamp.isOn()) {
    if(millis() - timer > 600000){
      timer = millis();
      lamp.off();
      fan.off();
    }
  }

}