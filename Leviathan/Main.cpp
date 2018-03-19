
#include "Universal_Header.h"

constexpr std::chrono::nanoseconds timestep(16ms); //60 ticks per sec

enum GameState {

	MENU, GAME

} state;

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

	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); //Window resizing will distort the image, but screw it

	int windowResX = 0;
	int windowResY = 0;

	const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor()); //Get monitor dimentions in a struct (look up a C tutorial)

	int w = vidmode->width;
	int h = vidmode->height;

	//Set dimentions of window to max sandard size for the 
	if (h < 240 && w < 256) {

		//144p 4:3
		windowResX = 192;
		windowResY = 144;

	} else if (h < 240) {

		//144p 16:9
		windowResX = 256;
		windowResY = 144;

	} else if (h < 360 && w < 426) {

		//240p 4:3
		windowResX = 320;
		windowResY = 240;

	} else if (h < 360) {

		//240p 16:9
		windowResX = 426;
		windowResY = 240;

	} else if (h < 480 && w < 640) {

		//360p 4:3
		windowResX = 480;
		windowResY = 360;

	} else if (h < 480) {

		//360p 16:9
		windowResX = 640;
		windowResY = 360;

	} else if (h < 720 && w < 854) {

		//480p 4:3
		windowResX = 640;
		windowResY = 480;

	} else if (h < 720) {

		//480p 16:9
		windowResX = 854;
		windowResY = 480;

	} else if (h < 1080) {

		//720p 16:9
		windowResX = 1280;
		windowResY = 720;

	} else if (h < 2160) {

		//1080p 16:9
		windowResX = 1920;
		windowResY = 1080;

	} else {

		//4K
		windowResX = 3840;
		windowResY = 2160;

	}

	GLFWwindow *window = glfwCreateWindow(windowResX, windowResY, "Leviathan", NULL, NULL); //Create window

	//Make sure window exists
	if (!window) {

		cout << "[-] GLFW: Failed to initialize window";

		glfwTerminate();

		return 1;

	}

	glfwMakeContextCurrent(window);

	int frameWidth, frameHeight;
	glfwGetFramebufferSize(window, &frameWidth, &frameHeight); //Gets virtual dimentions of window

	glewExperimental = GL_TRUE; //The magic of GLEW

	//Initialize GLEW
	if (glewInit()) {

		cout << "[-] GLEW: GLEW failed to initialize";

		glfwTerminate();

		return 1;

	}

	glViewport(0, 0, frameWidth, frameHeight); //This will make your life so much easier

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); //Make textures act like that
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //Make pixelated textures look pixelated
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Make it to where a picture smaller than the texture looks good

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
