#include "Rectangle.h"

Rectangle::Rectangle() {

	this->x = 0; //Initializing variables is important
	this->y = 0;
	this->width = 0;
	this->height = 0;

}

Rectangle::Rectangle(float x, float y, float width, float height) {

	this->x = x; //Set dimentions in necessary objects (efficency)
	this->y = y;
	this->width = width;
	this->height = height;

}

Rectangle::~Rectangle() {

	//Nothing yet

}

bool Rectangle::rectIsColliding(Rectangle r1, Rectangle r2) {

	//Complecated but standard rectangle collision algorithm
	if (r1.x < r2.x + r2.width &&
		r1.x + r1.width > r2.x &&
		r1.y < r2.y + r2.height &&
		r1.height + r1.y > r2.y) {

		return true;

	} else {

		return false;

	}

}

//Getters and setters

float Rectangle::getX() {

	return this->x;

}

float Rectangle::getY() {

	return this->y;

}

float Rectangle::getWidth() {

	return this->width;

}

float Rectangle::getHeight() {

	return this->height;

}

void Rectangle::setX(float x) {

	this->x = x;

}

void Rectangle::setY(float y) {

	this->y = y;

}

void Rectangle::setWidth(float width) {

	this->width = width;

}

void Rectangle::setHeight(float height) {

	this->height = height;

}

void Rectangle::setPos(float x, float y) {

	this->x = x;
	this->y = y;

}

void Rectangle::setSize(float width, float height) {

	this->width = width;
	this->height = height;

}

//Translation methods

void Rectangle::translate(float x, float y) {

	this->x += x; //Move
	this->y += y;

}

void Rectangle::scale(float width, float height) {

	this->width *= width; //Scales the width and height
	this->height *= height;

}

//Rotate hitbox 90* (flip width and height
void Rectangle::flip() {

	float temp = this->width; //Temporary value because width value is about to be replaced
	
	this->width = this->height; //Replace width by height
	this->height = temp; //Replace height by previous width

}
