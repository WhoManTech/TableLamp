#include <Arduino.h>
#include <OneButton.h>

#define LAMP_SETT_PIN A1
#define LAMP_PIN 0
#define PIR_PIN 3
#define FAN_PIN 4
#define BUTT_PIN 1
#define TIMER 10000
#define TIMER_SEARCH 5000

OneButton button(BUTT_PIN, false);

unsigned long timer;
unsigned long search_timer;

int bright;
int fan_speed;
int move_inf;

bool light_flag = true;
bool fan_up_flag = true;
bool fan_flag = false;
bool search_flag;



void click1(){
  light_flag = !light_flag;
  search_flag = false;
  delay(2000);
}

void doubleClick(){
  fan_flag = !fan_flag;
}


void setup(){
  pinMode(LAMP_SETT_PIN, INPUT);
  pinMode(LAMP_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);

  button.attachClick(click1);
  button.attachDoubleClick(doubleClick);
}



void loop(){
  button.tick();
  bright = map(analogRead(LAMP_SETT_PIN), 0, 1023, 0, 255);
  move_inf = digitalRead(PIR_PIN);


  if(light_flag){
    analogWrite(LAMP_PIN, bright);
  //  if(bright >= 200){
    //  analogWrite(FAN_PIN, 255);
    //  fan_flag = true;
   // }

    if(fan_flag){
      analogWrite(FAN_PIN, 255);
    }
    else if(!fan_flag){
      analogWrite(FAN_PIN, 0);
    }

    if(move_inf == 1){
      timer = millis();
    }
    if(millis() - timer > TIMER){
      timer = millis();
      light_flag = false;
    }
  }

  else if(!light_flag){
    analogWrite(LAMP_PIN, 0);
    analogWrite(FAN_PIN, 0);
    if(move_inf == 1){
      light_flag = true;
    }
  }  
}