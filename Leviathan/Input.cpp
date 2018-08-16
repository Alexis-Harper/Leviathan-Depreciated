#include "stdafx.h"

#include "Input.h"

namespace Input {

	namespace {

		bool keyPressed[65536]; //Array containing every key's 'is pressed' status

		double cursorPosX; //Mouse cursor position
		double cursorPosY;

		bool isControllerUsed;

	}

	void setup() {

		isControllerUsed = glfwGetJoystickName(GLFW_JOYSTICK_1) != NULL;

	}

	void keyCallback(int key, int action) {

		keyPressed[key] = action != GLFW_RELEASE;

	}

	void cursorCallback(double x, double y) {

		cursorPosX = x;
		cursorPosY = y;

	}

	//Getters and Setters

	bool isKeyPressed(int keycode) {

		return keyPressed[keycode];

	}

	double getCursorX() {

		return cursorPosX;

	}

	double Input::getCursorY() {

		return cursorPosY;

	}

	double* Input::getCursorArray() {

		static double arr[2];

		arr[0] = cursorPosX; //Set array
		arr[1] = cursorPosY;

		return arr;

	}

	int Input::eightDirection(int arr) {

		if (isControllerUsed) {

			int count;
			const float *joyArr = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);

			float x = joyArr[arr];
			float y = joyArr[arr];

			if (pow(x, 2) + pow(y, 2) < 1 / 8) {

				return NONE; //Always returns false in direction calculation if joystick is in middle

			}
			else {

				//Calculate which of the points it's between (this is complex stuff; I literrally had to use paper for this)

				if (acos(x / (sqrt(pow(x, 2) + pow(y, 2)))) >= M_PI / 8) {

					return UP; //Return UP

				}
				else if (acos((x + y) / (1.414213562373095048 * (sqrt(pow(x, 2) + pow(y, 2))))) >= M_PI / 8) {

					return UP_RIGHT;

				}
				else if (acos(y / (sqrt(pow(x, 2) + pow(y, 2)))) >= M_PI / 8) {

					return RIGHT;

				}
				else if (acos((x - y) / (1.414213562373095048 * (sqrt(pow(x, 2) + pow(y, 2))))) >= M_PI / 8) {

					return DOWN_RIGHT;

				}
				else if (acos((0 - x) / (sqrt(pow(x, 2) + pow(y, 2)))) >= M_PI / 8) {

					return DOWN;

				}
				else if (acos(((0 - x) - y) / (1.414213562373095048 * (sqrt(pow(x, 2) + pow(y, 2))))) >= M_PI / 8) {

					return DOWN_LEFT;

				}
				else if (acos((0 - y) / (sqrt(pow(x, 2) + pow(y, 2)))) >= M_PI / 8) {

					return LEFT;

				}
				else {

					return UP_LEFT;

				}

			}

		}
		else {

			return NONE; //Always returns false in direction calculation if joystick isn't connected

		}

	}

}
