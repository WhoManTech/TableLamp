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
bool fan_sett_flag = false;



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

void doubleClick(){
  fan_sett_flag = !fan_sett_flag;
}


void setup(){
  pinMode(LAMP_SETT_PIN, INPUT);
  pinMode(LAMP_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);

  button.attachClick(click1);
  button.attachDoubleClick(doubleClick);
  //button.attachDuringLongPress(longPress);
  //button.attachLongPressStop(longPressStop);
}



void loop(){
  button.tick();
  bright = map(analogRead(LAMP_SETT_PIN), 0, 1023, 0, 255);



  if(light_flag){
    analogWrite(LAMP_PIN, bright);
    if(fan_sett_flag){
      analogWrite(FAN_PIN, 255);
    }
    else if(!fan_sett_flag){
      analogWrite(FAN_PIN, 0);
    }
  }
  else if(!light_flag){
    analogWrite(LAMP_PIN, 0);
    analogWrite(FAN_PIN, 0);
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