#include <Arduino.h>
#include <NewPing.h>
#include "motor.h"

const int trigPin = 11;
const int echoPin = 12;
const int MAX_DISTANCE = 200; // 最大測量距離（單位：厘米）
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);


void line_following(int ir_center, int ir_left, int ir_right) {

    if (ir_left == 1 && ir_center == 0 && ir_right == 1) { // stop or back
        stop();
        delay(200);
        back(120);
    } else if (ir_left == 1 && ir_center == 1 && ir_right == 1) { // run
        back(0);
        run(120);
        delay(500);
    } else if (ir_left == 1 && ir_center == 0 && ir_right == 0) { // right
        back(0);
        motor(100, 0, 0, 0);
        delay(500);
    } else if (ir_left == 0 && ir_center == 0 && ir_right == 1)  { //left
        back(0);
        motor(0, 0, 100, 0);
        delay(500);
    } else if (ir_left == 0 && ir_center == 1 && ir_right == 1) { //big right
        back(0);
        right(100);
        delay(500);
    } else if (ir_left == 1 && ir_center == 1 && ir_right == 0) { // big left
        back(0);
        left(100);
        delay(500);
    } else {
        back(120);
        delay(500);
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

    // back(0);
    // run(120);
    // delay(2000);

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