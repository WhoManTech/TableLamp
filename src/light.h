#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <Arduino.h>


class Light{
    public:
        Light(uint8_t light_pin, uint8_t sensor_pin);
        void update();
        void on();
        void off();
        uint8_t getBrightness() {return bright_;}
        bool isOn() {return is_on_;}

    private:
        uint8_t light_pin_;
        uint8_t sensor_pin_;
        uint8_t bright_;
        bool is_on_;
        unsigned long timer_;
};





#endif // _LIGHT_H_