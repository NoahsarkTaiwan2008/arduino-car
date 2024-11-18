#include <Arduino.h>
#include <NewPing.h>
#include "motor.h"

const int trigPin = 11;
const int echoPin = 12;
const int MAX_DISTANCE = 200; // 最大測量距離（單位：厘米）
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    unsigned int distance = sonar.ping_cm();
<<<<<<< HEAD
    Serial.print("距離：");
    Serial.print(distance);
    Serial.println("cm");

    if (distance > 0 && distance <= 15) {
        // 停止並直接繞過障礙物
        stop();
        delay(500);

        right(150); // 或 left(150)，根據需要轉向
        delay(500);

        run(255);
=======

    if (distance <= 15) {
        delay(1000);
        stop();
        back(180);
        left(130);
>>>>>>> 3eff6225aa7d447a02b7d5df80e7d965e7957726
    } else {
        run(255);
    }
}