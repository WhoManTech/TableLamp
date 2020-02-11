#include <light.h>



Light::Light(uint8_t light_pin, uint8_t sensor_pin)
    : light_pin_(light_pin)
    , sensor_pin_(sensor_pin)
    , bright_(0)
    , is_on_(true)
    {
        pinMode(light_pin_, OUTPUT);
        pinMode(sensor_pin_, INPUT);
    }



void Light::update() {
    if (is_on_) {
        bright_ = map(analogRead(sensor_pin_), 0, 1032, 0, 255);
        analogWrite(light_pin_, bright_);
    }

    else if(!is_on_) {
        analogWrite(light_pin_, 0);
    }
}



void Light::off() {
    for (uint8_t i = bright_; i > 0;) {
        if (millis() - timer_ > 10) {
            i--;
            analogWrite(light_pin_, i);
            is_on_ = false;
            timer_ = millis();
        }
    }
}



void Light::on() {
    for (uint8_t i = 0; i < bright_;) {
        if (millis() - timer_ > 10) {
            i++;
            analogWrite(light_pin_, i);
            is_on_ = true;
            timer_ = millis();
        }
    }
}





