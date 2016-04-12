#include “driveControl.h"

DriveControl::DriveControl() {
	shield = Adafruit_MotorShield();
	*motorfl = shield.getMotor(1);
	*motorfr = shield.getMotor(2);
	*motorbl = shield.getMotor(3);
	*motorbr = shield.getMotor(4);
}

DriveControl::DriveControl(int fl, int fr, int bl, int br) {
	shield = Adafruit_MotorShield();
	
	if (fl >= 0 && fl <= 4)
		*motorfl = shield.getMotor(fl);
	
	if (fr >= 0 && fr <= 4)
		*motorfr = shield.getMotor(fr);
	
	if (bl >= 0 && bl <= 4)
		*motorbl = shield.getMotor(bl);
	
	if (br >= 0 && br <= 4)
		*motorbr = shield.getMotor(br);
}

DriveControl::move(int fl, int fr, int bl, int br) {
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
		motorbl->run(FORWARD);
	}
	else {
		motorbl->setSpeed(-bl);
		motorbl->run(BACKWARD);
	}
	
	if(br > 255 || br < -255) {
		motorbr->setSpeed(0);
		motorbr->run(FORWARD);
	}
	else if(br >= 0) {
		motorbr->setSpeed(br);
		motorbr->run(FORWARD);
	}
	else {
		motorbr->setSpeed(-br);
		motorbr->run(BACKWARD);
	}
}