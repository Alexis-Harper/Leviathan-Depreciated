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
