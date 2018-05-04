#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include <sstream>

#include "Input.h"
#include "Rectangle.h"

class Player {

public:

	Player();
	~Player();

	void update(); //Run on every tick (physics, motion, etc.)
	void render(); //Run on every render (graphics, image, etc.)

	void damagePhy(int); //Physical attack
	void damageMag(int); //Magic attack

	void move(bool, bool, bool, bool);
	
	Rectangle hitbox;

private:

	bool canMove[4];

	int hp = 100;
	int hpMax = 100;
	int mp = 10;
	int mpMax = 10;
	int attack;
	int magic;
	int range = 1;
	int defence = 1;
	int resistance = 1;
	int speed = 1;

	float xPos = 0, yPos = 0; //Position
	float vX = 0, vY = 0; //Velocity

	Direction direction; //Direction for graphics

	unsigned char *image; //Image pointer

	int width, height, comp; //Image dimentions

	unsigned int texture, VBO, VAO, EBO; //Buffers

	int vertexShader; //Vertex shader pointer
	int fragmentShader; //Fragment shader pointer

	unsigned int shaderProgram; //Dual shader program pointer

	ALuint hurtSoundPhy, hurtSoundMag, deathSound, playerSource;

};

#endif
