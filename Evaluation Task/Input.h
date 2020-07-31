#pragma once

#include <iostream>
#include <string>
#include <conio.h> // for _getch and _kbhit
using namespace std;

class Input
{
private:
	string userInput;
	char cInput[5] = { 'o', 'o', 'o', 'o', 'o' };
public:
	void getInput();
	bool EngineOn();
	bool Accelerate();
	bool Decelerate();
	bool TurnLeft();
	bool TurnRight();
	string toString();
};