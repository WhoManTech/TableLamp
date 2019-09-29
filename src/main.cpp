#include <Arduino.h>
#include <OneButton.h>

#define LAMP_SETT_PIN A1
#define LAMP_PIN 0
#define PIR_PIN 3
#define FAN_PIN 4
#define BUTT_PIN 1
#define TIMER 10000

OneButton button(BUTT_PIN, false);

unsigned long timer;

int bright;
int fan_speed;
int move_inf;

bool light_flag = true;
bool fan_up_flag = true;



void click1(){
  light_flag = !light_flag;
  analogWrite(FAN_PIN, 255);
}

void longPress(){
  if(fan_up_flag){
    fan_speed++;
  }
  else if(!fan_up_flag){
    fan_speed--;
  }
}

void longPressStop(){
  fan_up_flag = !fan_up_flag;
}


void setup(){
  pinMode(LAMP_SETT_PIN, INPUT);
  pinMode(LAMP_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  //pinMode(BUTT_PIN, INPUT_PULLUP);

  button.attachClick(click1);
  //button.attachDuringLongPress(longPress);
  //button.attachLongPressStop(longPressStop);
}



void loop(){
  button.tick();
  bright = map(analogRead(LAMP_SETT_PIN), 0, 1032, 0, 255);


  if(light_flag){
    analogWrite(LAMP_PIN, bright);
  }
  else if(!light_flag){
    analogWrite(LAMP_PIN, 0);
  }  

  if(move_inf == 1){
    if(light_flag){
       if(millis() - timer > TIMER){
        timer = millis();
        light_flag = false;
      }
    }
    else{
      light_flag = true;
    }
  }
  

}