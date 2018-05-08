#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy:GameObject {

public:

	Enemy();
	~Enemy();

	virtual int attack() = 0;

protected:

	int level;

};

#endif
