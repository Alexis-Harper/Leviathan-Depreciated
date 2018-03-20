#pragma once

#include <iostream>
#include <string>

#include <fstream>
#include <sstream>

//GLEW
#define GLEW_STATIC
#include <gl\glew.h>

//GLFW
#include <GLFW\glfw3.h>

//stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Rectangle.h"

using namespace std;

class Player {

public:

	Player();
	~Player();

	void render();

private:

	Rectangle hitbox;

	unsigned char *image;

	int width, height, comp;

	unsigned int texture, VBO, VAO, EBO;

	int vertexShader;
	int fragmentShader;

	unsigned int shaderProgram;

};

