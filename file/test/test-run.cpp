#include <Arduino.h>
#include "motor.h"

void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
}

void loop() {
    // digitalWrite(5, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
}