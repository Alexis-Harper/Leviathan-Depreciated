#include "Matrix.h"

std::vector<float> x;
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

std::vector<float> Matrix::getX() {

	return x;

}

std::vector<float> Matrix::getY() {

	return y;

}

void Matrix::resize(int num) {

	size = num;

	x.resize(num);
	y.resize(num);

}

void Matrix::setX(int adress, float value) {

	this->x[adress] = value;

}

void Matrix::setY(int adress, float value) {

	this->y[adress] = value;

}

void Matrix::setX(std::vector<float> x) {

	this->x = x;

}

void Matrix::setY(std::vector<float> y) {

	this->y = y;

}

void Matrix::setMatrix(std::vector<float> x, std::vector<float> y) {

	this->x = x;
	this->y = y;

}

Matrix Matrix::transform(float x, float y) {

	Matrix returnMatrix;

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = this->x[i] + x;
		returnMatrix.y[i] = this->y[i] + y;

	}

	return returnMatrix;

}

Matrix Matrix::scalar(float s) {

	Matrix returnMatrix;

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = this->x[i] * s;
		returnMatrix.y[i] = this->y[i] * s;

	}

	return returnMatrix;

}

Matrix Matrix::multiply(float x1, float x2, float y1, float y2) {

	Matrix returnMatrix;

	for (int i = 0; i < this->size; i++) {

		returnMatrix.x[i] = (this->x[i] * x1) + (this->y[i] * x2);
		returnMatrix.y[i] = (this->x[i] * y1) + (this->y[i] * y2);

	}

	return returnMatrix;

}
