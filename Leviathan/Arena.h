#pragma once

#ifndef ARENA_H
#define ARENA_H

#include <fstream>

#include "rapidxml.hpp"

#include "GameObject.h"
#include "Rectangle.h"

using namespace rapidxml;
using namespace std;

class Arena {

public:

	Arena();
	Arena(char*);
	~Arena();

	//Store all walls
	vector<Rectangle> arenaUp;
	vector<Rectangle> arenaRight;
	vector<Rectangle> arenaDown;
	vector<Rectangle> arenaLeft;

	vector<GameObject> gameObjects; //Stores all enemies, bosses, etc.

	string getLocation();

private:

	string location;

};

#endif
