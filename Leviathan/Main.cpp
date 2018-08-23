#include "stdafx.h"

#include "Arena.h"
#include "Audio.h"
#include "Input.h"
#include "Player.h"
#include "GameObject.h"
#include "SaveData.h"

using namespace std;

constexpr chrono::nanoseconds timestep(16ms); //60 ticks per sec

//Enum that keeps track of where in the game you are, because that's an important
enum GameState {

	MENU, GAME

} state;

Arena *arenaObject = new Arena(); //Dynamic arenaObject that can be changed a lot

//GLFW Callbacks
void framebuffer_size_callback(GLFWwindow*, int, int);
void mouse_pos_callback(GLFWwindow*, double, double);

int main() {

	//Init

	ios::sync_with_stdio(false); //Speed up cout (doesn't flush stream)

	#ifdef _DEBUG
		cout << "Running Leviathan: Debug " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_BUILD << " " << VERSION_SUFFIX << "\n\n";
	#else
		cout << "Running Leviathan: Release " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_BUILD << " " << VERSION_SUFFIX << "\n\n";
	#endif

	//Initialize GLFW
	if (!glfwInit()) {

		cout << "[-] GLFW: GLFW failed to initialize";

		return 1;

	} else {



	}



	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //Use OpenGL version 4.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Maximum compatability

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //Make Mac OS happy, won't you?

	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); //Window resizing will distort the image, but screw it

	int windowResX = 0; //Temporary values to set the desired window resoution
	int windowResY = 0;

	const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor()); //Get monitor dimentions in a struct (look up a C tutorial)

	int w = vidmode->width; //Get monitor dimentions in two variables
	int h = vidmode->height;

	//Set dimentions of window to max sandard size for widescreen (I wrote this in Java and then recreated all the variables with the same name before this and copied and pasted. I love simiar programming languages)
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

	Input::setWindow(window);

	//Make sure window exists
	if (!window) {

		cout << "[-] GLFW: Failed to initialize window";

		glfwTerminate();

		return 1;

	}

	glfwMakeContextCurrent(window); //Make GLFW focus arround window

	int frameWidth, frameHeight;
	glfwGetFramebufferSize(window, &frameWidth, &frameHeight); //Gets virtual dimentions of window

	//Set callbacks
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_pos_callback);

	glewExperimental = GL_TRUE; //The magic of GLEW

	//Initialize GLEW
	if (glewInit()) {

		cout << "[-] GLEW: GLEW failed to initialize";

		glfwTerminate();

		return 1;

	}

	glViewport(0, 0, frameWidth, frameHeight); //This will make your life so much easier
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //Callback every frame size change (this will also make your life easier)

	glfwSetCursorPosCallback(window, mouse_pos_callback); //Mouse position callback for mouse positioning

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); //Make textures act like that
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //Make pixelated textures look pixelated
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Make it to where a picture smaller than the texture looks good

	//alutInitWithoutContext(NULL, NULL); //Initialize ALut

	/*if (alGetError() != AL_NO_ERROR) {

		cout << "[-] ALut: ALut failed to initialize";

		return 1;

	}*/

	Player player;

	Input::setup();

	auto startTime = chrono::high_resolution_clock::now(); //Get time right after initialization (initial time before first start time reset later on)

	//Main loop
	while (!glfwWindowShouldClose(window)) {

		auto deltaTime = chrono::high_resolution_clock::now() - startTime; //Calculates delta (time since last frame)

		Input::setDelta((int)(chrono::duration_cast<chrono::nanoseconds>(deltaTime) / timestep));

		//Limit FPS to 60 Hz
		if (chrono::duration_cast<chrono::nanoseconds>(deltaTime) >= timestep) {

			chrono::duration_cast<chrono::microseconds>(deltaTime);

			startTime = chrono::high_resolution_clock::now(); //Reset time every frame (necessary for propper timing)

			glfwPollEvents(); //Checks for events such as glfwWindowShouldClose() or controller input (including callbacks)

			//Update physics

			bool canMove[4]; //This helps keep track of player with walls

			//Can move
			canMove[0] = true;
			canMove[1] = true;
			canMove[2] = true;
			canMove[3] = true;

			//Should player be able to go up
			for (int i = 0; i < arenaObject->arenaUp.size(); i++) {

				if (Rectangle::rectIsColliding(player.hitbox, arenaObject->arenaUp[i])) {

					canMove[0] = false;

					break;

				}

			}

			//Should player be able to go right
			for (int i = 0; i < arenaObject->arenaRight.size(); i++) {

				if (Rectangle::rectIsColliding(player.hitbox, arenaObject->arenaRight[i])) {

					canMove[1] = false;

					break;

				}

			}

			//Should player be able to go down
			for (int i = 0; i < arenaObject->arenaDown.size(); i++) {

				if (Rectangle::rectIsColliding(player.hitbox, arenaObject->arenaDown[i])) {

					canMove[2] = false;

					break;

				}

			}

			//Should player be able to go left
			for (int i = 0; i < arenaObject->arenaLeft.size(); i++) {

				if (Rectangle::rectIsColliding(player.hitbox, arenaObject->arenaDown[i])) {

					canMove[3] = false;

					break;

				}

			}

			player.move(canMove[0], canMove[1], canMove[2], canMove[3]); //Let movement work
			player.update();

			//Update all Game Objects
			Arena::GameObjects *o = arenaObject->first;
			Arena::GameObjects *last = NULL;

			while (o != NULL) {

				if (o->object->update()) {

					if (o == arenaObject->first) {

						arenaObject->first = o->next;

					} else {

						last->next = o->next;

					}
					
					o->object->~GameObject();

				}

				last = o;
				o = o->next;

			}

			//Update graphics

			o = arenaObject->first;

			while (o != NULL) {

				o->object->render();

				o = o->next;

			}

			//player.render(); //Render player

			//Audio::render(); //Render audio

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Black background (like ALttP)

			glClear(GL_COLOR_BUFFER_BIT); //Clears frame so next can render

			glfwSwapBuffers(window); //Important

		}

	}

	//Delete all necessary things (heap objects)
	delete arenaObject; 

	//Destroy all objects
	player.~Player();

	//GLFW
	glfwDestroyWindow(window); //Destroy window

	glfwTerminate(); //Close GLFW

	//OpenAL
	//alutExit(); //Close ALut

	return 0;

}

//GLFW callbacks

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {

	glViewport(0, 0, width, height); //Making your life easier one callback at a time

}

void mouse_pos_callback(GLFWwindow *window, double xpos, double ypos) {

	Input::cursorCallback(xpos, ypos);

}
