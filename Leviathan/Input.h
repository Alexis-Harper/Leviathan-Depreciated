#pragma once

#include "stdafx.h"

#ifndef DIRECTION_H
#define DIRECTION_H

//8 direction enum (for graphics)
enum Direction {

	UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN_LEFT, LEFT, UP_LEFT, DOWN

}; //Create direction enum

#endif

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

