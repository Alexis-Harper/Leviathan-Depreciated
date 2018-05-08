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

	void move(bool, bool, bool, bool); //Sets where player can move

	//Setters
	void setStats(int, int, int, int, int, int, int, int);
	void setPosition(float, float);

	//Getters
	int getHp();
	int getHpMax();
	int getAmmo();
	int getAmmoMax();
	int getAttack();
	int getRange();
	int getDefence();
	int getSpeed();
	float getX();
	float getY();
	
	Rectangle hitbox;

private:

	bool canMove[4];

	int hp;
	int hpMax;
	int ammo;
	int ammoMax;
	int attack;
	int range;
	int defence;
	int speed;

	float xPos, yPos; //Position
	float vX, vY; //Velocity

	Direction direction; //Direction for graphics

	unsigned char *image; //Image pointer

	int width, height, comp; //Image dimentions

	unsigned int texture, VBO, VAO, EBO; //Buffers

	int vertexShader; //Vertex shader pointer
	int fragmentShader; //Fragment shader pointer

	unsigned int shaderProgram; //Dual shader program pointer

	ALuint hurtSoundPhy, hurtSoundMag, deathSound, playerSource; //Player sounds

};

#endif
