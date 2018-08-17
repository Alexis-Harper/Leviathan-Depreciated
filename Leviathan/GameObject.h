#pragma once

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {

public:

	GameObject();
	GameObject(float, float);
	~GameObject();

	//This is good
	virtual bool update() = 0;
	virtual void render() = 0;

	bool damage(int); //Take damage

	virtual void death() = 0; //Abstract death

private:

	//virtual void loadSound() = 0; //Load sound (will vary based off of class)

	float xPos, yPos; 

	//Stats
	int hp;
	int hpMax;
	int attack;
	int speed;

	//ALuint breathSound, hurtSound, deathSound; //Audio buffers

};

#endif
