#include "Rectangle.h"

Rectangle::Rectangle() {

	this->x = 0;
	this->y = 0;

}

Rectangle::Rectangle(float x, float y, float width, float height) {

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

}

Rectangle::~Rectangle() {

	

}

bool Rectangle::rectIsColliding(Rectangle r1, Rectangle r2) {

	if (r1.x < r2.x + r2.width &&
		r1.x + r1.width > r2.x &&
		r1.y < r2.y + r2.height &&
		r1.height + r1.y > r2.y) {

		return true;

	} else {

		return false;

	}

}

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

void Rectangle::setPos(float x, float y) {

	this->x = x;
	this->y = y;

}

void Rectangle::setSize(float width, float height) {

	this->width = width;
	this->height = height;

}

void Rectangle::translate(float x, float y) {

	this->x += x;
	this->y += y;

}

void Rectangle::scale(float width, float height) {

	this->width *= width;
	this->height *= height;

}
