#include "stdafx.h"

#include "Input.h"

namespace Input {

	namespace {

		double delta; //Time ratio (delta)

		GLFWwindow *window;

		double cursorPosX; //Mouse cursor position
		double cursorPosY;

		bool isControllerUsed;

	}

	void setup() {

		isControllerUsed = glfwJoystickPresent(GLFW_JOYSTICK_1);

	}

	void setDelta(double value) {

		delta = value;

	}

	double getDelta() {

		return delta;

	}

	void setWindow(GLFWwindow *ptr) {

		window = ptr;

	}

	void cursorCallback(double x, double y) {

		cursorPosX = x;
		cursorPosY = y;

	}

	//Getters and Setters

	bool isKeyPressed(int keycode) {

		return glfwGetKey(window, keycode);//keyPressed[keycode];

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

	//0 for left, 2 for right
	int Input::eightDirection(int arr) {

		if (isControllerUsed) {

			int jCount, bCount;
			const float *joyArr = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &jCount);

			float x = joyArr[arr];
			float y = joyArr[arr + 1];

			const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &bCount);

			#ifdef _DEBUG
				std::cout << "Joystick: " << x << " " << y << "\n";
				std::cout << "Buttons: " << (buttons[10] == 1) << (buttons[11] == 1) << (buttons[12] == 1) << (buttons[13] == 1) << "\n";
			#endif //*/

			if ((pow(x, 2) + pow(y, 2) <= M_PI / 8) && !buttons[10] && !buttons[11] && !buttons[12] && !buttons[13]) {
				
				/*#ifdef _DEBUG
					std::cout << "NULL\n";
				#endif //*/

				return NONE; //Always returns false in direction calculation if joystick is in middle

			} else {

				//Calculate which of the points it's between (this is complex stuff; I literrally had to use paper for this)

				if ((acos(x / (sqrt(pow(x, 2) + pow(y, 2)))) >= M_PI / 8) || (buttons[10] && !buttons[11] && !buttons[12] && !buttons[13])) {

					return UP; //Return UP

				} else if ((acos((x + y) / (1.414213562373095048 * (sqrt(pow(x, 2) + pow(y, 2))))) >= M_PI / 8) || (buttons[10] && buttons[11] && !buttons[12] && !buttons[13])) {

					return UP_RIGHT;

				} else if ((acos(y / (sqrt(pow(x, 2) + pow(y, 2)))) >= M_PI / 8) || (!buttons[10] && buttons[11] && !buttons[12] && !buttons[13])) {

					return RIGHT;

				} else if ((acos((x - y) / (1.414213562373095048 * (sqrt(pow(x, 2) + pow(y, 2))))) >= M_PI / 8) || (!buttons[10] && buttons[11] && buttons[12] && !buttons[13])) {

					return DOWN_RIGHT;

				} else if ((acos((0 - x) / (sqrt(pow(x, 2) + pow(y, 2)))) >= M_PI / 8) || (!buttons[10] && !buttons[11] && buttons[12] && !buttons[13])) {

					return DOWN;

				} else if ((acos(((0 - x) - y) / (1.414213562373095048 * (sqrt(pow(x, 2) + pow(y, 2))))) >= M_PI / 8) || (!buttons[10] && !buttons[11] && buttons[12] && buttons[13])) {

					return DOWN_LEFT;

				} else if ((acos((0 - y) / (sqrt(pow(x, 2) + pow(y, 2)))) >= M_PI / 8) || (!buttons[10] && !buttons[11] && !buttons[12] && buttons[13])) {

					return LEFT;

				} else {

					return UP_LEFT;

				}

			}

		} else {

			return NONE; //Always returns false in direction calculation if joystick isn't connected

		}

	}

}
