#include <NewPing.h>

#define TRIGGER_PIN 11
#define ECHO_PIN 10
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// put your setup code here, to run once:
const int AIN1 = 2; // 左馬達方向1
const int AIN2 = 4; // 左馬達方向2
const int PWMA = 5; // 左馬達PWM

const int BIN1 = 7; // 右馬達方向1
const int BIN2 = 8; // 右馬達方向2
const int PWMB = 6; // 右馬達PWM

const int STBY = 9; // 馬達驅動板待機引腳

// 定義馬達速度 (PWM)
const int LeftSpeed = 143;
const int RightSpeed = 144;
const int FLeftSpeed = 173;
const int FRightSpeed = 174;

int w = 0;
int r = 0;
int p = 0;
int s = 0;

void setup()
{

    // 紅外線循跡感測器腳位
    const int IR1 = A0;
    const int IR2 = A1;
    const int IR3 = A2;
    const int IR4 = A3;
    const int IR5 = A4;

    // 紅外線循跡感測器腳位
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);
    pinMode(IR3, INPUT);
    pinMode(IR4, INPUT);
    pinMode(IR5, INPUT);

    // 馬達腳位設為輸出
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);

    pinMode(STBY, OUTPUT);
}

// 馬達控制函式
void moveForward()
{
    digitalWrite(STBY, HIGH); // 激活馬達
    // 左馬達前進
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, LeftSpeed);

    // 右馬達前進
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, RightSpeed);
}

void moveBackward()
{
    digitalWrite(STBY, HIGH); // 激活馬達
    // 左馬達後退
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, LeftSpeed);

    // 右馬達後退
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, RightSpeed);
}

void turnLeft()
{
    digitalWrite(STBY, HIGH); // 激活馬達
    // 左馬達停止
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, 0);

    // 右馬達前進
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, FRightSpeed);
}

void turnRight()
{
    digitalWrite(STBY, HIGH); // 激活馬達
    // 右馬達停止
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, 0);

    // 左馬達前進
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, FLeftSpeed);
}

void sharpLeft()
{
    digitalWrite(STBY, HIGH); // 激活馬達
    // 左馬達後退
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, FLeftSpeed);

    // 右馬達前進
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, FRightSpeed);
}

void sharpRight()
{
    digitalWrite(STBY, HIGH); // 激活馬達
    // 左馬達前進
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, FLeftSpeed);

    // 右馬達後退
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, FRightSpeed);
}

void stopCar()
{
    digitalWrite(STBY, HIGH); // 激活馬達
    // 停止所有馬達
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, 0);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, 0);
}

void plan()
{

    if (p == 0)
    {
        while (digitalRead(A0) == 0)
        {
            turnRight();
        }
        while (digitalRead(A2) == 0)
        {
            sharpLeft();
        }
    }
    else if (p == 1)
    {
        while (digitalRead(A0) == 1)
        {
            moveForward();
        }
        while (digitalRead(A4) == 0)
        {
            turnLeft();
        }
        while (digitalRead(A2) == 0)
        {
            sharpRight();
        }
    }
    else if (p == 2)
    {
        while (digitalRead(A4) == 0)
        {
            nor2();
        }
        while (digitalRead(A4) == 1)
        {
            moveForward();
        }
        delay(300);
        while (digitalRead(A4) == 0)
        {
            sharpRight();
        }
        while (digitalRead(A0) == 1)
        {
            sharpRight();
        }
        while (digitalRead(A0) == 0)
        {
            turnRight();
        }
        while (digitalRead(A2) == 0)
        {
            sharpLeft();
        }
    }
    else if (p == 3)
    {
        while (digitalRead(A4) == 0)
        {
            turnLeft();
        }
        while (digitalRead(A0) == 0)
        {
            turnRight();
        }

        turnLeft();
        delay(200); // 可調動變數
        while (digitalRead(A4) == 0)
        {
            turnLeft();
        }
        turnRight();
        delay(600); // 重要彎道!重要變數!
        while (digitalRead(A2) == 0)
        {
            sharpRight();
        }
        while (digitalRead(A0) == 1)
        {
            nor();
        }
    }
    else if (p == 4)
    {
        turnLeft();
        delay(400); // 重要彎道!重要變數!
        while (digitalRead(A0) == 1 || digitalRead(A2) == 0 || digitalRead(A4) == 1)
        {
            sharpLeft();
        }
    }
    else if (p == 5)
    {
        while (digitalRead(A0) == 0)
        {
            turnRight();
        }
        while (digitalRead(A0) == 1)
        {
            sharpRight();
        }
        while (digitalRead(A4) == 0)
        {
            sharpRight();
        }

        while (digitalRead(A0) == 1 || digitalRead(A4) == 1)
        {
            moveForward();
        }
        while (digitalRead(A0) == 0)
        {
        }
        stopCar();
        delay(4000);
    }
}

// moveForward();
// byte IR1 = digitalRead(A0);
// byte IR2 = digitalRead(A1);
// byte IR3 = digitalRead(A2);
// byte IR4 = digitalRead(A3);
// byte IR5 = digitalRead(A4);

void nor()
{

    if (digitalRead(A2) == 1)
    {
        moveForward();
    }
    else if (digitalRead(A1) == 1)
    {
        turnLeft();
    }
    else if (digitalRead(A3) == 1)
    {
        turnRight();
    }
    else
    {
        moveForward();
    }
}

void nor2()
{

    if (digitalRead(A2) == 1)
    {
        moveForward();
    }
    else if (digitalRead(A1) == 1)
    {
        sharpLeft();
    }
    else if (digitalRead(A3) == 1)
    {
        sharpRight();
    }
    else
    {
        moveForward();
    }
}

void loop()
{

    if (digitalRead(A0) == 1 || digitalRead(A4) == 1)
    {
        plan();
        p = p + 1;
    }
    else
    {
        nor();
    }
}

// 超聲波距離讀取函式
