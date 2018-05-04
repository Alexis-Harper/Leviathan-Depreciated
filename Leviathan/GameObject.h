#pragma once

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {

public:

	GameObject();
	GameObject(float, float);
	~GameObject();

protected:

	virtual void loadSound() = 0;

	float xPos, yPos;

	ALuint breathSound, hurtSound, deathSound;

};

#endif
