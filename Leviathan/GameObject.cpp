#include "stdafx.h"

#include "GameObject.h"

GameObject::GameObject() {

	xPos = 0;
	yPos = 0;

	loadSound();

}

GameObject::GameObject(float x, float y) {

	xPos = x;
	yPos = y;

	loadSound();

}

GameObject::~GameObject() {



}

void GameObject::damage(int attack) {

	if (attack >= this->hp) {

		this->death();

	} else {

		this->hp -= attack;

	}

}
