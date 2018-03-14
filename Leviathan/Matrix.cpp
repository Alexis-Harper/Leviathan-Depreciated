#include "Matrix.h"

std::vector<float> x; //Dynamic 2xY matrix size
std::vector<float> y;

Matrix::Matrix() {

	size = 2;

	x.resize(2);
	y.resize(2);

}

Matrix::Matrix(int num) {

	size = num;

	x.resize(num);
	y.resize(num);

}

Matrix::~Matrix() {

	x.clear();
	y.clear();

}

int Matrix::getSize() {

	return this->size;

}

//Getters and setters

std::vector<float> Matrix::getX() {

	return x;

}

std::vector<float> Matrix::getY() {

	return y;

}

//Resize matrix
void Matrix::resize(int num) {

	if (this->size != num) {

		size = num;

		x.resize(num);
		y.resize(num);

	}

}

void Matrix::setX(int adress, float value) {

	if (adress < this->size) {

			this->x[adress] = value;

	}

}

void Matrix::setY(int adress, float value) {

	if (adress < this->size) {

		this->y[adress] = value;

	}

}

void Matrix::setX(std::vector<float> x) {

	if (x.size() == this->size) {

		this->x = x;

	} else {

		this->size = x.size();

		this->x.resize(x.size());
		this->y.resize(x.size());

		this->x = x;

	}

}

void Matrix::setY(std::vector<float> y) {

	if (x.size() == this->size) {

		this->y = y;

	} else {

		this->size = x.size();

		this->x.resize(x.size());
		this->y.resize(x.size());

		this->y = y;

	}

}

void Matrix::setMatrix(std::vector<float> x, std::vector<float> y) {

	if (x.size() == this->size) {

		this->x = x;
		this->y = y;

	} else {

		this->size = x.size();

		this->x.resize(x.size());
		this->y.resize(x.size());

		this->x = x;
		this->y = y;

	}

}

//Translate matrix
Matrix Matrix::translate(float x, float y) {

	Matrix returnMatrix;
	returnMatrix.resize(this->size);

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = this->x[i] + x;
		returnMatrix.y[i] = this->y[i] + y;

	}

	return returnMatrix;

}

//Multiply this by a scalar
Matrix Matrix::scalar(float s) {

	Matrix returnMatrix;
	returnMatrix.resize(this->size);

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = this->x[i] * s;
		returnMatrix.y[i] = this->y[i] * s;

	}

	return returnMatrix;

}

//Multiply 2x2 by a 2xY
Matrix Matrix::multiply(float x1, float x2, float y1, float y2) {

	Matrix returnMatrix;
	returnMatrix.resize(this->size);

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = (this->x[i] * x1) + (this->y[i] * x2);
		returnMatrix.y[i] = (this->x[i] * y1) + (this->y[i] * y2);

	}

	return returnMatrix;

}
