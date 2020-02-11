#include <fan.h>



Fan::Fan(uint8_t pin)
    : pin_(pin)
    , bright_(0)
    , is_on_(false)
    {
        pinMode(pin_, OUTPUT);
    }



void Fan::update(uint8_t bright) {
    bright_ = bright;
    if (is_on_) {
        digitalWrite(pin_, HIGH);
        if (bright_ <= 0) {
            is_on_ = false;
        }
    }

    else if (!is_on_) {
        digitalWrite(pin_, LOW);
        if (bright_ > 200) {
            is_on_ = true;
        }
    }
}



void Fan::off() {
    is_on_ = false;
}



void Fan::on() {
    is_on_ = true;
}