#include <Arduino.h>
#include <NewPing.h>

const int trigPin = 11;
const int echoPin = 12;
const int MAX_DISTANCE = 200; // 最大測量距離（單位：厘米）
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

void setup() {
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A3, INPUT);
    pinMode(A5, INPUT);

    Serial.begin(9600);
}

void loop() {
    unsigned int distance = sonar.ping_cm();

    int IR_L = digitalRead(A0);
    int IR_R = digitalRead(A1);
    int IR_L2 = digitalRead(A3);
    // int IR_R2 = digitalRead(A5);

// Serial.print("IR_L: ");
// Serial.print(IR_L == 1 ? "白" : "黑");
// Serial.print(" | IR_L2: ");
// Serial.print(IR_L2 == 1 ? "黑" : "白");
// Serial.print(" | IR_R: ");
// Serial.println(IR_R == 1 ? "白" : "黑");

Serial.print(IR_L);
Serial.print(" ");
Serial.print(IR_L2);
Serial.print(" ");
Serial.print(IR_R);
Serial.println();

delay(500);

// Serial.print("cm: ");
// Serial.println(distance);

// delay(500);

//     Serial.print("cm: ");
//     Serial.println(distance);

//     delay(500);
}