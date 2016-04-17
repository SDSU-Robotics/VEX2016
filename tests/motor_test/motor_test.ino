#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield shield = Adafruit_MotorShield();
Adafruit_DCMotor *motorfl = shield.getMotor(3);
Adafruit_DCMotor *motorfr = shield.getMotor(2);
Adafruit_DCMotor *motorbl = shield.getMotor(4);
Adafruit_DCMotor *motorbr = shield.getMotor(1);

void move(int fl, int fr, int bl, int br) {

  if (fl > 255 || fl < -255) {
    motorfl->setSpeed(0);
    motorfl->run(FORWARD);
  }
  else if(fl >= 0) {
    motorfl->setSpeed(fl);
    motorfl->run(FORWARD);
  }
  else {
    motorfl->setSpeed(-fl);
    motorfl->run(BACKWARD);
  }

  if(fr > 255 || fr < -255) {
   motorfr->setSpeed(0);
   motorfr->run(FORWARD);
  }
  else if(fr >= 0) {
    motorfr->setSpeed(fr);
    motorfr->run(FORWARD);
  }
  else {
    motorfr->setSpeed(-fr);
    motorfr->run(BACKWARD);
  }

    if(bl > 255 || bl < -255) {
   motorbl->setSpeed(0);
   motorbl->run(FORWARD);
  }
  else if(bl >= 0) {
    motorbl->setSpeed(bl);
    motorbl->run(BACKWARD);
  }
  else {
    motorbl->setSpeed(-bl);
    motorbl->run(FORWARD);
  }

    if(br > 255 || br < -255) {
   motorbr->setSpeed(0);
   motorbr->run(FORWARD);
  }
  else if(br >= 0) {
    motorbr->setSpeed(br);
    motorbr->run(BACKWARD);
  }
  else {
    motorbr->setSpeed(-br);
    motorbr->run(FORWARD);
  }
}

void setup() {
  shield.begin();
}

void loop() {
  const int speed = 75;

  move(speed, speed, speed, speed);//forward
  delay(3000);

  move(-speed, -speed, -speed, -speed);//backward
  delay(3000);

  move(speed, -speed, -speed, speed);//right
  delay(3000);

  move(-speed, speed, speed, -speed);//left
  delay(3000);

  move(speed, -speed, speed, -speed);//turn right
  delay(3000);

  move(-speed, speed, -speed, speed);//turn left
  delay(3000);
  

}
