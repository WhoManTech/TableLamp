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

  // bright = map(analogRead(LAMP_SETT_PIN), 0, 1032, 0, 255);
  // move_inf = digitalRead(PIR_PIN);


  // if(light_flag){
  //   if(!effect_flag){
  //     effect_flag = true;
  //     switchEffectOn();
  //   }

  //   analogWrite(LAMP_PIN, bright);
  //   if(bright >= 200){
  //     fan_flag = true;
  //   }

  //   if(fan_flag){
  //     analogWrite(FAN_PIN, 255);
  //   }
  //   else if(!fan_flag){
  //     analogWrite(FAN_PIN, 0);
  //   }

  //   if(move_inf == 1){
  //     timer = millis();
  //   }
  if (lamp.isOn()) {
    if(millis() - timer > 600000){
      timer = millis();
      lamp.off();
      fan.off();
    }
  }


  // else if(!light_flag){
  //   if(effect_flag){
  //     effect_flag = false;
  //     switchEffectOff();
  //   }
  //   analogWrite(LAMP_PIN, 0);
  //   analogWrite(FAN_PIN, 0);

  //   if(!search_flag){
  //     if(millis() - search_timer > TIMER_SEARCH){
  //       search_timer = millis();
  //       search_flag = true;
  //     }
  //   }
  //   else if(search_flag){
  //     if(move_inf == 1){
  //       light_flag = true;
  //       search_flag = false;
  //     }
  //   }
  // }
}