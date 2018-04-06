#pragma once

#include "stdafx.h"

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
