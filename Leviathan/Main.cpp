
#include <iostream>
#include <chrono>

// GLEW
#define GLEW_STATIC
#include "../ExternalResources/glew-2.1.0/include/GL/glew.h"

// GLFW
#include "../ExternalResources/glfw-3.2.1/include/GLFW/glfw3.h"

using namespace std;

constexpr std::chrono::nanoseconds timestep(16ms); //60 ticks per sec

int main() {

	//Init

	//Initialize GLFW
	if (!glfwInit()) {

		cout << "[-] GLFW: GLFW failed to initialize";

		return 1;

	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //Use OpenGL version 4.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Maximum compatability

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //Make Mac OS happy, won't you?

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); //Window resizing will distort the image

	GLFWwindow *window = glfwCreateWindow(640, 480, "Leviathan", NULL, NULL); //Create window

	//Make sure window exists
	if (!window) {

		cout << "[-] GLFW: Failed to initialize window";

		glfwTerminate();

		return 1;

	}

	int frameWidth, frameHeight;
	glfwGetFramebufferSize(window, &frameWidth, &frameHeight); //Gets virtual dimentions of window

	glewExperimental = GL_TRUE; //The magic of GLEW

	//Initialize GLEW
	if (glewInit() != GLEW_OK) {

		cout << "[-] GLEW: GLEW failed to initialize";

		glfwTerminate();

		return 1;

	}

	glViewport(0, 0, frameWidth, frameHeight); //This will make your life so much easier

	auto startTime = std::chrono::high_resolution_clock::now(); //Get time

	//Main loop
	while (!glfwWindowShouldClose(window)) {

		auto deltaTime = std::chrono::high_resolution_clock::now() - startTime; //Calculates delta (time since last frame)

		//Limit FPS to 60 Hz
		if (std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime) >= timestep) {

			startTime = std::chrono::high_resolution_clock::now(); //Reset time every frame (necessary for propper timing)

			glfwPollEvents(); //Checks for events such as glfwWindowShouldClose() or controller input

			//Get inputs

			//Update physics

			//Update graphics

			glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Black background

			glClear(GL_COLOR_BUFFER_BIT); //Clears frame so next can render

			glfwSwapBuffers(window); //Important

		}

	}

	glfwTerminate(); 

	return 0;

}
