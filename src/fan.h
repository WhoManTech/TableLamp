#ifndef _FAN_H_
#define _FAN_H_

#include <Arduino.h>


class Fan{
    public:
        Fan(uint8_t pin);
        void update(uint8_t bright);
        void on();
        void off();
        bool isOn() {return is_on_;}

    private:
        uint8_t pin_;
        uint8_t bright_;
        bool is_on_;
};





#endif // _FAN_H_