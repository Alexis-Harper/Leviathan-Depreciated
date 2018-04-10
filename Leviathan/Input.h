#pragma once

#include "stdafx.h"

class Input {

public:

	int delta; //Time ratio (delta)

	Input();
	~Input();

	void keyCallback(int, int); //Called on every key callback (transmits main.cpp callback data to inputObject)

	bool isKeyPressed(int); //Get bool data of if key is pressed

	int eightDirection(); //Get all directions (in same order as player.h enum)

private:

	bool keyPressed[65536]; //Array containing every key's 'is pressed' status

	bool isControllerUsed;

} inputObject; //Create object to store data

