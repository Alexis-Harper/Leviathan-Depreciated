#pragma once
#include <vector>

class Matrix {

public:

	Matrix();
	Matrix(int);
	Matrix(std::vector<float>, std::vector<float>);

	~Matrix();

	int getSize();

	std::vector<float> getX();
	std::vector<float> getY();

	void resize(int);

	void setX(int, float);
	void setY(int, float);

	void setX(std::vector<float>);
	void setY(std::vector<float>);
	void setMatrix(std::vector<float>, std::vector<float>);

	Matrix translate(float, float);
	Matrix scalar(float);
	Matrix multiply(float, float, float, float);

private:

	std::vector<float> x;
	std::vector<float> y;

	int size = 0;

};
