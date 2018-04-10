#pragma once

#include "stdafx.h"

class Player {

	//8 direction enum (for graphics)
	enum Direction {

		UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN_LEFT, LEFT, UP_LEFT, DOWN

	} direction; //Create direction enum

public:

	Player();
	~Player();

	void update(); //Run on every tick (physics, motion, etc.)
	void render(); //Run on every render (graphics, image, etc.)

private:

	Rectangle hitbox; //Hitbox object

	float xPos = 0, yPos = 0; //Position
	float vX = 0, vY = 0; //Velocity

	unsigned char *image; //Image pointer

	int width, height, comp; //Image dimentions

	unsigned int texture, VBO, VAO, EBO; //Buffers

	int vertexShader; //Vertex shader pointer
	int fragmentShader; //Fragment shader pointer

	unsigned int shaderProgram; //Dual shader program pointer

};
