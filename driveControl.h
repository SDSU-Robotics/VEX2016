#ifndef driveControl_h
#define driveControl_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

class DriveControl {
private:
	Adafruit_MotorShield shield;
	Adafruit_DCMotor *motorfl;
	Adafruit_DCMotor *motorfr;
	Adafruit_DCMotor *motorbl;
	Adafruit_DCMotor *motorbr;
public:
	DriveControl();
	DriveControl(int fl, int fr, int bl, int br);

	move(int fl, int fr, int bl, int br);
};



#endif /* driveControl_h */