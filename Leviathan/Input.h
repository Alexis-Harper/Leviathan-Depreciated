#pragma once

#ifndef INPUT_H
#define INPUT_H

#include "stdafx.h"

#include "Player.h"

class Input {

public:

	int delta; //Time ratio (delta)

	Input();
	~Input();

	void keyCallback(int, int); //Called on every key callback (transmits main.cpp callback data to inputObject)

	bool isKeyPressed(int); //Get bool data of if key is pressed

	Direction eightDirection(int); //Get all directions

private:

	bool keyPressed[65536]; //Array containing every key's 'is pressed' status

	bool isControllerUsed;

} inputObject; //Create object to store data

#endif
