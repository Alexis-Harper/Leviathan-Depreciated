#include "Vector.h"

#include <cmath>

Vector::Vector() {

	this->size = 2;

	this->vect.resize(2);

}

Vector::Vector(int num) {

	this->size = num;

	this->vect.resize(num);

}

Vector::~Vector() {



}

float Vector::dotProduct(Vector v1, Vector v2) {

	//Incompatable vectors return NULL
	if (v1.size != v2.size) {

		return NULL;

	}

	float sum = 0;

	for (int i = 0; i < v1.size; i++) {

		sum += v1.vect[i] * v2.vect[i];

	}

	return sum;

}

Vector Vector::crossProduct(Vector v1, Vector v2) {

	//Incompatable vectors return NULL
	if (v1.size != 3 || v2.size != 3) {

		return NULL;

	}

	Vector returnVector = Vector::Vector(3);

	returnVector.vect[0] = (v1.vect[1] * v2.vect[2]) - (v1.vect[2] * v2.vect[1]);
	returnVector.vect[1] = (v1.vect[2] * v2.vect[0]) - (v1.vect[0] * v2.vect[2]);
	returnVector.vect[2] = (v1.vect[0] * v2.vect[1]) - (v1.vect[1] * v2.vect[0]);

	return returnVector;

}

//Get magnitude, duh
float Vector::magnitude(Vector v) {

	float sum = 0; //Pythagorean theorum sum (a^2

	for (int i = 0; i < v.size; i++) {

		sum += pow(v.vect[i], 2); //Add square of all values (a^2 + b^2 + ...)

	}

	return sqrt(sum); //Pythagorean sqrt (c^2)

}

//Getters and setters

int Vector::getSize() {

	return this->size;

}

float Vector::getValue(int adress) {

	if (adress < this->size) {

		return vect[adress];

	} else {

		return NULL;

	}

}

std::vector<float> Vector::getVector() {

	return vect;

}

void Vector::resize(int num) {

	if (this->size != num) {

		this->vect.resize(num);

	}

}

void Vector::setValue(int adress, float value) {

	if (adress < this->size) {

		this->vect[adress] = value;

	}

}

void Vector::setVector(std::vector<float> newVec) {

	if (newVec.size() == this->size) {

		this->vect = newVec;

	} else {

		size = newVec.size();

		this->vect.resize(newVec.size());

		this->vect = newVec;

	}

}

Vector Vector::scalarMultiply(float s) {

	Vector returnVector;
	returnVector.resize(this->size);

	for (int i = 0; i < this->size; i++) {

		returnVector.vect[i] = this->vect[i] * s;

	}

	return returnVector;

}
