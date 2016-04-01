#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield shield = Adafruit_MotorShield();
Adafruit_DCMotor *motor1 = shield.getMotor(1);
Adafruit_DCMotor *motor2 = shield.getMotor(2);

void setup() {
  shield.begin();

  motor1->setSpeed(100);
  motor2->setSpeed(50);

}

void loop() {
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
}
