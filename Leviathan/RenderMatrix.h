#pragma once

#ifndef RENDER_MAT_H
#define RENDER_MAT_H

#ifdef _DEBUG
	#include <iostream>
#endif

class RenderMatrix {

public:

	RenderMatrix();
	RenderMatrix(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
	RenderMatrix(float*);
	~RenderMatrix();

	//If in debug mode, create matrix test code that prints the matrix out
	#ifdef _DEBUG
		void printMat() { std::cout << this->matrix[0] << " " << this->matrix[1] << " " << this->matrix[2] << " " << this->matrix[3] << " \n" << this->matrix[4] << " " << this->matrix[5] << " " << this->matrix[6] << " " << this->matrix[7] << " \n" << this->matrix[8] << " " << this->matrix[9] << " " << this->matrix[10] << " " << this->matrix[11] << " \n" << this->matrix[12] << " " << this->matrix[13] << " " << this->matrix[14] << " " << this->matrix[15] << " \n"; }
	#endif

	void setIdentity();
	static RenderMatrix getIdentity();

	void setNum(int, float);
	void setNum(int, int, float);

	void set_00(float);
	void set_01(float);
	void set_02(float);
	void set_03(float);
	void set_10(float);
	void set_11(float);
	void set_12(float);
	void set_13(float);
	void set_20(float);
	void set_21(float);
	void set_22(float);
	void set_23(float);
	void set_30(float);
	void set_31(float);
	void set_32(float);
	void set_33(float);

	float getNum(int);
	float getNum(int, int);
	float* getMatrix();

	float get_00();
	float get_01();
	float get_02();
	float get_03();
	float get_10();
	float get_11();
	float get_12();
	float get_13();
	float get_20();
	float get_21();
	float get_22();
	float get_23();
	float get_30();
	float get_31();
	float get_32();
	float get_33();

	//Change matrix
	void transposeMatrix(float, float, float);
	void scaleMatrix(float, float, float);

	//Set Matrix
	void setLocation(float, float, float);
	void setScale(float, float, float);

	//Multiplication
	RenderMatrix multiply(RenderMatrix);
	void setMultiply(RenderMatrix);

private: 

	float matrix[16];

};

#endif
