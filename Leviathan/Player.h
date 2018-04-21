#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Rectangle.h"

class Player {

public:

	Player();
	~Player();

	void update(); //Run on every tick (physics, motion, etc.)
	void render(); //Run on every render (graphics, image, etc.)

private:

	Rectangle hitbox;

	float xPos = 0, yPos = 0; //Position
	float vX = 0, vY = 0; //Velocity

	Direction direction; //Direction for graphics

	unsigned char *image; //Image pointer

	int width, height, comp; //Image dimentions

	unsigned int texture, VBO, VAO, EBO; //Buffers

	int vertexShader; //Vertex shader pointer
	int fragmentShader; //Fragment shader pointer

	unsigned int shaderProgram; //Dual shader program pointer

};

#endif
