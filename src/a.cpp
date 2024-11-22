#include <Arduino.h>
#include <NewPing.h>
#include "motor.h"

const int trigPin = 11;
const int echoPin = 12;
const int MAX_DISTANCE = 200; // 最大測量距離（單位：厘米）
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);


void line_following(int ir_center, int ir_left, int ir_right) {

    if (ir_center == 0 && ir_left == 1 && ir_right == 1) {
        // run(110);
        stop();
        delay(500);
        right(220);
    } else if (ir_center == 1 && ir_left == 1 && ir_right == 1) {
        run(220);
    } else if (ir_center == 0 && ir_left == 1 && ir_right == 0) {
        right(220);
    } else if (ir_center == 0 && ir_left == 0 && ir_right == 1) {
        left(220);
    } else {
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
    // pinMode(A5, INPUT);
    
    Serial.begin(9600);
}

void loop() {
    unsigned int distance = sonar.ping_cm();

    int ir_left = digitalRead(A0);
    int ir_right = digitalRead(A1);

    int ir_center = digitalRead(A3);
    // int right2 = digitalRead(A5);

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");
    Serial.print("left: ");
    Serial.print(ir_left);
    Serial.print(" right: ");
    Serial.println(ir_right);
    Serial.print(" center: ");
    Serial.print(ir_center);
    // Serial.print(" right2: ");
    // Serial.println(right2);
    delay(500);

    // if (distance > 0 && distance <= 15) {
    //     // 停止並直接繞過障礙物
    //     stop();
    //     delay(500);

    //     right(150); // 或 left(150)，根據需要轉向
    //     delay(500);

    //     run(100);
    // } else {
    //     line_following(ir_center, ir_left, ir_right);
    // }
    line_following(ir_center, ir_left, ir_right);
}