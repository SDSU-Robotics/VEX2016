#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield shield = Adafruit_MotorShield();
Adafruit_DCMotor *motor1 = shield.getMotor(1);
Adafruit_DCMotor *motor2 = shield.getMotor(2);
Adafruit_DCMotor *motor3 = shield.getMotor(3);
Adafruit_DCMotor *motor4 = shield.getMotor(4);

void setup() {
  shield.begin();

  motor1->setSpeed(100);
  motor2->setSpeed(100);
  motor3->setSpeed(100);
  motor4->setSpeed(100);

}

void loop() {
  //Front-Right
  //Front-Left
  //Back-Right
  //Back-Left
  //Wait 3 seconds

  //forward
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
  delay(3000);

  //backward
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
  motor4->run(BACKWARD);
  delay(3000);

  //strafe right
  motor1->run(BACKWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(BACKWARD);
  delay(3000);

  //strafe left
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
  motor4->run(FORWARD);
  delay(3000);

  //turn right
  motor1->run(BACKWARD);
  motor2->run(FORWARD);
  motor3->run(BACKWARD);
  motor4->run(FORWARD);
  delay(3000);

  //turn left
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
  motor3->run(FORWARD);
  motor4->run(BACKWARD);
  delay(3000);
}
