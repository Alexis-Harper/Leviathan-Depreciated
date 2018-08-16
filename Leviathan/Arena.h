#pragma once

#ifndef ARENA_H
#define ARENA_H

#include <fstream>

#include "rapidxml.hpp"

#include "GameObject.h"
#include "Rectangle.h"

class Arena {

public:

	Arena();
	Arena(char*);
	~Arena();

	//Store all walls
	std::vector<Rectangle> arenaUp;
	std::vector<Rectangle> arenaRight;
	std::vector<Rectangle> arenaDown;
	std::vector<Rectangle> arenaLeft;

	std::string getLocation();

	//Game objects linked list

	struct GameObjects {

		GameObject *object;

		GameObjects *next;

	};

	struct GameObjects *first;

private:

	std::string location;

};

#endif
