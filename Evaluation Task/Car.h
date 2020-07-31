//the car controls work as required, but aren't realistic

#pragma once
class Car
{
private:
	float maxSpeed = 160;
	float acceleration = 1.3;
	float deceleration = 0.8;
	bool isEngineOn = false;
	float Accelerate();
	float Decelerate();
	float TurnLeft();
	float TurnRight();
public:
	float curSpeed = 0;
	int curRotation = 0;
	void EngineOn();
	bool isAccelerating = false;
	bool isDecelerating = false;
	bool isTurningLeft = false;
	bool isTurningRight = false;
	void processState();
};

