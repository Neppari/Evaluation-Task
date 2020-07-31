#include "Input.h"

void Input::getInput() {
	for (int i = 0; i < 5; i++) {
		//if a key is pressed, store character into array cInput[]
		if (_kbhit())
			cInput[i] = _getch();
	}
}

string Input::toString() {
	userInput.clear();

	//stores user input into string userInput
	for (int j = 0; j < 5; j++) {
		userInput = userInput + cInput[j];
	}
	
	//resets cInput[] back to characters with no controls
	for (int i = 0; i < 5; i++) {
		cInput[i] = 'o';
	}

	return userInput;
}

bool Input::EngineOn() {
	if ((userInput.find('q') != string::npos) || (userInput.find('Q') != string::npos))
		return true;
	else
		return false;
}

bool Input::Accelerate() {
	if ((userInput.find('w') != string::npos) || (userInput.find('W') != string::npos))
		return true;
	else
		return false;
}

bool Input::Decelerate() {
	if ((userInput.find('s') != string::npos) || (userInput.find('S') != string::npos))
		return true;
	else
		return false;
}

bool Input::TurnLeft() {
	if ((userInput.find('a') != string::npos) || (userInput.find('A') != string::npos))
		return true;
	else
		return false;
}

bool Input::TurnRight() {
	if ((userInput.find('d') != string::npos) || (userInput.find('D') != string::npos))
		return true;
	else
		return false;
}