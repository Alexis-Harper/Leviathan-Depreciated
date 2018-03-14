
#include <iostream>
#include <chrono>

using namespace std;

constexpr std::chrono::nanoseconds timestep(16ms); //60 ticks per sec

int main() {

	//Init

	auto startTime = std::chrono::high_resolution_clock::now(); //Get time

	//Main loop
	while (true) {

		auto deltaTime = std::chrono::high_resolution_clock::now() - startTime; //Calculates delta (time since last frame)

		//Limit FPS to 60 Hz
		if (std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime) >= timestep) {

			startTime = std::chrono::high_resolution_clock::now();

			//Get inputs

			//Update physics

			//Update graphics

		}

	}

	return 0;

}
