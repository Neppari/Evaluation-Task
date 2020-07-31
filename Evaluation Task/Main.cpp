#include "Input.h"
#include "Car.h"
#include <stdlib.h> // for clearing the console
#include <chrono> // for timer

using namespace std;

int main() {
	Input input;
	Car car;

	chrono::time_point<chrono::system_clock> end; //endpoint for my timer
	chrono::milliseconds ms(30); //how long the timer is in ms

	while (true) {

		//update timer endpoint to current time
		end = chrono::system_clock::now() + ms;

		while (chrono::system_clock::now() < end) {
			input.getInput();
		}

		input.toString();

		//if proper input is found, car engine gets turned on/off
		if (input.EngineOn()) { car.EngineOn(); }

		car.isAccelerating = input.Accelerate();
		car.isDecelerating = input.Decelerate();
		car.isTurningLeft = input.TurnLeft();
		car.isTurningRight = input.TurnRight();

		car.processState();

		//clear the console, for readability
		system("cls");

		//print instructions
		cout << "Controls: q = engine on/off, wasd movement" << endl;
		//print current speed and rotation
		cout << "Speed: " << car.curSpeed << ", Rotation: " << car.curRotation << endl;
	}
}