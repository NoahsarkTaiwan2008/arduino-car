#include <Arduino.h>
#include "motor.h"

void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
}

void loop() {
    motor(100, 0, 130, 0);
}