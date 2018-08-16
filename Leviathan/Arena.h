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

	std::vector<GameObject> gameObjects; //Stores all enemies, bosses, etc.

	std::string getLocation();

private:

	std::string location;

};

#endif
