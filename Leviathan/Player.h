#pragma once

#include "Universal_Header.h"

class Player {

public:

	Player();
	~Player();

	void render();

private:

	unsigned char *image;

	int width, height, comp;

	unsigned int texture;

};

