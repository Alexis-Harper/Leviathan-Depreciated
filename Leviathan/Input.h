#pragma once

#ifndef INPUT_H
#define INPUT_H

#include "Player.h"

class Input {

public:

	int delta; //Time ratio (delta)

	Input();
	~Input();

	void keyCallback(int, int); //Called on every key callback (transmits main.cpp callback data to inputObject)
	void cursorCallback(double, double);

	bool isKeyPressed(int); //Get bool data of if key is pressed

	double getCursorX(); //Get position stuff
	double getCursorY();
	double* getCursorArray();

	Direction eightDirection(int); //Get all directions

private:

	bool keyPressed[65536]; //Array containing every key's 'is pressed' status

	double cursorPosX; //Mouse cursor position
	double cursorPosY;

	bool isControllerUsed;

} inputObject; //Create object to store data

#endif
