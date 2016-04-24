#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Shield_PS2.h>

PS2 ps2=PS2();

Adafruit_MotorShield shield = Adafruit_MotorShield();
Adafruit_DCMotor *motorfl = shield.getMotor(3);
Adafruit_DCMotor *motorfr = shield.getMotor(2);
Adafruit_DCMotor *motorbl = shield.getMotor(4);
Adafruit_DCMotor *motorbr = shield.getMotor(1);

const int maxSpeed = 200;
int inner, outer;

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

void getSpeedJoystick(int x, int y, int & out, int & inn) {
  x = 2 * x - 255;
  y = -2 * y + 255;
  int disp = sqrt(x * x + y * y);
  int ang = atan(y / x);
  
  if (x >= 0 && y >= 0) {
    inn = (ang - 3.14 / 4) * 4 / 3.14 * maxSpeed;
    out = 2 * maxSpeed / 255 * disp;
  }
  else if (x < 0 && y >= 0) {
    inn = 2 * maxSpeed / 255 * disp;
    out = (ang + 3.14 / 4) * 4 / 3.14 * maxSpeed;
  }
  else if (x < 0 && y < 0) {
    inn = (ang + 3.14 / 4) * 4 / 3.14 * maxSpeed;
    out = -2 * maxSpeed / 255 * disp;
  }
  else {
    inn = -2 * maxSpeed / 255 * disp;
    out = (ang - 3.14 / 4) * 4 / 3.14 * maxSpeed;
  }
}

void setup() {
  // put your setup code here, to run once:
  ps2.init(9600, 10, 11); // 2, 3); // 0,1);   //initialize the main board to use desired (baudrate, rx, tx)
                           //for Arduino Mega use RX:10, TX: 11 for software serial
                           //for Arduino Leonardo use pin 8, 9, 10, 11 as RX and TX for software serial
  
   //Read from Computer
   Serial.begin(9600); 
   shield.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  if (ps2.getval(p_l1) == 0)
    move(-maxSpeed, maxSpeed, -maxSpeed, maxSpeed);//turn left
  else if (ps2.getval(p_r1) == 0)
    move(maxSpeed, -maxSpeed, maxSpeed, -maxSpeed);//turn right
  else
  {
    getSpeedJoystick(ps2.getval(p_joy_lx), ps2.getval(p_joy_ly), outer, inner);
    move(outer, inner, inner, outer);
  }
  
/*  if (ps2.getval(p_left) == 0 && ps2.getval(p_up) == 0)
    move(0, speed, speed, 0);
  else if (ps2.getval(p_right) == 0 && ps2.getval(p_up) == 0)
    move(speed, 0, 0, speed);
  else if (ps2.getval(p_left) == 0 && ps2.getval(p_down) == 0)
    move(-speed, 0, 0, -speed);
  else if (ps2.getval(p_right) == 0 && ps2.getval(p_down) == 0)
    move(0, -speed, -speed, 0);
  else if (ps2.getval(p_up) == 0)
    move(speed, speed, speed, speed);//forward
  else if (ps2.getval(p_left) == 0)
    move(-speed, speed, speed, -speed);//left
  else if (ps2.getval(p_right) == 0)
    move(speed, -speed, -speed, speed);//right
  else if (ps2.getval(p_down) == 0)
    move(-speed, -speed, -speed, -speed);//backward
  else if (ps2.getval(p_l1) == 0)
    move(-speed, speed, -speed, speed);//turn left
  else if (ps2.getval(p_r1) == 0)
    move(speed, -speed, speed, -speed);//turn right
  else
    move(0, 0, 0, 0);*/
}
