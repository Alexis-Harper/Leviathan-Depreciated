#pragma once

#include <iostream>

//GLEW
#define GLEW_STATIC
#include <gl\glew.h>

//GLFW
#include <GLFW\glfw3.h>

//stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

