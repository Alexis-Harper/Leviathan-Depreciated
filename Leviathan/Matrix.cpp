#include "stdafx.h"

#include "Matrix.h"

std::vector<float> x; //Dynamic 2xY matrix size
std::vector<float> y;

Matrix::Matrix() {

	size = 2; //Default size of 2x2

	x.resize(2);
	y.resize(2);

}

Matrix::Matrix(int num) {

	size = num; //Set size

	x.resize(num);
	y.resize(num);

}

Matrix::Matrix(std::vector<float> x, std::vector<float> y) {

	int xSize = x.size();
	int ySize = y.size();

	std::vector<float> tempX = x;
	std::vector<float> tempY = y;

	//Check if two vectors are the same size
	if (xSize > ySize) {

		tempY.resize(xSize); //Make sure y is the right size

		for (int i = ySize; i < xSize; i++) {

			tempY[i] = 0;

		}

	} else if (ySize > xSize) {

		xSize = ySize;

		tempX.resize(ySize); //Make sure that x is the right size

		for (int i = xSize; i < ySize; i++) {

			tempX[0] = 0;

		}

	}

	this->size = xSize; //Size it to the correct size

	this->x.resize(this->size); //Resize
	this->y.resize(this->size);

	this->x = tempX; //Set vectors
	this->y = tempY;

}

Matrix::~Matrix() {

	x.clear(); //Clear up space on RAM
	y.clear();

}

//Getters and setters

int Matrix::getSize() {

	return this->size;

}

std::vector<float> Matrix::getX() {

	return x;

}

std::vector<float> Matrix::getY() {

	return y;

}

//Resize matrix
void Matrix::resize(int num) {

	//Only change if the size is different (I don't know if this is necessary, but it probably only adds 2 bytes)
	if (this->size != num) {

		size = num; //Variable to store size for faster running (no method requirement)

		x.resize(num); //Resize
		y.resize(num);

	}

}

void Matrix::setX(int adress, float value) {

	//Make sure it fits in the vector
	if (adress < this->size) {

			this->x[adress] = value;

	}

}

void Matrix::setY(int adress, float value) {

	//Make sure it fits in the vector
	if (adress < this->size) {

		this->y[adress] = value;

	}

}

void Matrix::setX(std::vector<float> x) {

	int xSize = x.size();

	if (xSize == this->size) {

		this->x = x; //If the vector is the same size as before, just add it

	} else {

		this->size = xSize; //Resize vector if necessary to make room or clean (mem adress for faster running)

		this->x.resize(xSize); //Resize
		this->y.resize(xSize);

		this->x = x; //Add it

	}

}

void Matrix::setY(std::vector<float> y) {

	int ySize = y.size();

	if (ySize == this->size) {

		this->y = y; //If the vector is the same size as before, just add it

	} else {

		this->size = ySize; //Resize vector if necessary to make room or clean (mem adress for faster running)

		this->x.resize(ySize); //Resize
		this->y.resize(ySize);

		this->y = y; //Add it

	}

}

void Matrix::setMatrix(std::vector<float> x, std::vector<float> y) {

	int xSize = x.size(); //This prevents errors
	int ySize = y.size();

	std::vector<float> tempX = x;
	std::vector<float> tempY = y;

	//Check if two vectors are the same size
	if (xSize > ySize) {

		tempY.resize(xSize); //Make sure y is the right size

		for (int i = ySize; i < xSize; i++) {

			tempY[i] = 0;

		}

	} else if (ySize > xSize) {

		xSize = ySize;

		tempX.resize(ySize); //Make sure that x is the right size

		for (int i = xSize; i < ySize; i++) {

			tempX[0] = 0;

		}

	}

	if (xSize != this->size) {

		this->size = xSize; //Resize vector if necessary to make room or clean

		this->x.resize(xSize);
		this->y.resize(xSize);

	}

	this->x = x; //Add it
	this->y = y;

}

//Translate matrix
Matrix Matrix::translate(float x, float y) {

	Matrix returnMatrix; //Create a return matrix
	returnMatrix.resize(this->size); //Size return matrix so that it works

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = this->x[i] + x; //Add value to all adresses in the respective row
		returnMatrix.y[i] = this->y[i] + y;

	}

	return returnMatrix; //Return return matrix

}

//Multiply this by a scalar
Matrix Matrix::scalar(float s) {

	Matrix returnMatrix; //Create a return matrix
	returnMatrix.resize(this->size); //Size return matrix so that it works

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = this->x[i] * s; //Multiply all adresses by the scalar
		returnMatrix.y[i] = this->y[i] * s;

	}

	return returnMatrix; //Return return matrix

}

//Multiply 2x2 by a 2xY (this is really complicated)
Matrix Matrix::multiply(float x1, float x2, float y1, float y2) {

	Matrix returnMatrix; //Create return matrix
	returnMatrix.resize(this->size); //Size return matrix so that it works

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = (this->x[i] * x1) + (this->y[i] * x2); //I'm not even going to bother
		returnMatrix.y[i] = (this->x[i] * y1) + (this->y[i] * y2);

	}

	return returnMatrix; //Return return matrix

}
