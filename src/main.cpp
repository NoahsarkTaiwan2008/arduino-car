#include <Arduino.h>
#include <NewPing.h>
#include "motor.h"

const int trigPin = 11;
const int echoPin = 12;
const int MAX_DISTANCE = 200; // 最大測量距離（單位：厘米）
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

// L100:R130
void line_following(int IR_L, int IR_R) {

    if (IR_L == 0 && IR_R == 0) {
        motor(100, 0, 130, 0);
    } else if (IR_L == 1 && IR_R == 0) {
        motor(90, 0, 0, 0);
        delay(300);
    } else if (IR_L == 0 && IR_R == 1) {
        motor(0, 0, 90, 0);
        delay(300);
    } else {
        motor(0, 0, 0, 0);
        delay(2000);
        stop();
    }
}

void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A3, INPUT);
    pinMode(A5, INPUT);
    
    Serial.begin(9600);
}

void loop() {
    unsigned int distance = sonar.ping_cm();
    // int IR_L = digitalRead(A0);
    // int IR_R = digitalRead(A1);

    int IR_L = digitalRead(A0);
    int IR_R = digitalRead(A1);

    int IR_L2 = digitalRead(A3);
    int IR_R2 = digitalRead(A5);

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");
    Serial.print("IR_L: ");
    Serial.print(IR_L);
    Serial.print(" IR_R: ");
    Serial.println(IR_R);
    Serial.print(" IR_L2: ");
    Serial.print(IR_L2);
    Serial.print(" IR_R2: ");
    Serial.println(IR_R2);
    delay(500);

    if (distance > 0 && distance <= 15) {
        // 停止並直接繞過障礙物
        stop();
        delay(500);

        right(150); // 或 left(150)，根據需要轉向
        delay(500);

        run(255);
    } else {
        line_following(IR_L, IR_R);
    }
}