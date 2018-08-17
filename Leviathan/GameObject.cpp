#include "stdafx.h"

#include "GameObject.h"

GameObject::GameObject() {

	xPos = 0;
	yPos = 0;

	//this->loadSound();

}

GameObject::GameObject(float x, float y) {

	xPos = x;
	yPos = y;

	//this->loadSound();

}

GameObject::~GameObject() {



}

bool GameObject::damage(int attack) {

	if (attack >= this->hp) {

		this->death();

		return true;

	} else {

		this->hp -= attack;

		return false;

	}

}
