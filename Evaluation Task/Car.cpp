#include "Car.h"
#include <iostream>

void Car::EngineOn() {
	if (isEngineOn == false) {
		isEngineOn = true;
	}
	else if (isEngineOn == true) {
		isEngineOn = false;
	}
}

float Car::Accelerate() {
	if (isEngineOn == true) {
		curSpeed = curSpeed * acceleration;
		if (curSpeed >= maxSpeed)
			curSpeed = maxSpeed;
		if (curSpeed < 1)
			curSpeed = 1 * acceleration;

		return curSpeed;
	}
}

float Car::Decelerate() {
	if (isEngineOn == true) {
		curSpeed = curSpeed * deceleration;
		if (curSpeed < 1)
			curSpeed = 0;

		return curSpeed;
	}
}

float Car::TurnLeft() {
	if (isEngineOn == true) {
		curRotation = curRotation - 1;
		if (curRotation <= -360.0)
			curRotation = 0;

		return curRotation;
	}
}

float Car::TurnRight() {
	if (isEngineOn == true) {
		curRotation = curRotation + 1;
		if (curRotation >= 360.0)
			curRotation = 0;

		return curRotation;
	}
}

void Car::processState() {
	//can we accelerate?
	if (isAccelerating && !isDecelerating)
		Accelerate();

	//can we decelerate?
	if (isDecelerating && !isAccelerating)
		Decelerate();
		
	//can we turn left?
	if (curSpeed > 0 && isTurningLeft && !isTurningRight)
		TurnLeft();

	//can we turn right?
	if (curSpeed > 0 && isTurningRight && !isTurningLeft)
		TurnRight();
}