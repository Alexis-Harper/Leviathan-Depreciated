#include "stdafx.h"

#include "RenderMatrix.h"

RenderMatrix::RenderMatrix() {

	//Set matrix to identity matrix
	this->matrix[0] = 1; //First row
	this->matrix[1] = 0;
	this->matrix[2] = 0;
	this->matrix[3] = 0;
	this->matrix[4] = 0; //Second row
	this->matrix[5] = 1;
	this->matrix[6] = 0;
	this->matrix[7] = 0;
	this->matrix[8] = 0; //Third row
	this->matrix[9] = 0;
	this->matrix[10] = 1;
	this->matrix[11] = 0;
	this->matrix[12] = 0; //Fourth row
	this->matrix[13] = 0;
	this->matrix[14] = 0;
	this->matrix[15] = 1;

}

RenderMatrix::RenderMatrix(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float a1, float a2, float a3, float a4) {

	this->matrix[0] = x1;
	this->matrix[1] = x2;
	this->matrix[2] = x3;
	this->matrix[3] = x4;
	this->matrix[4] = y1;
	this->matrix[5] = y2;
	this->matrix[6] = y3;
	this->matrix[7] = y4;
	this->matrix[8] = z1;
	this->matrix[9] = z2;
	this->matrix[10] = z3;
	this->matrix[11] = z4;
	this->matrix[12] = a1;
	this->matrix[13] = a2;
	this->matrix[14] = a3;
	this->matrix[15] = a4;

}

RenderMatrix::RenderMatrix(float* matrixPointer) {

	for (int i = 0; i < 16; i++) {

		this->matrix[i] = matrixPointer[i];

	}

}

RenderMatrix::~RenderMatrix() {



}

void RenderMatrix::setIdentity() {

	//Set matrix to identity matrix
	this->matrix[0] = 1; //First row
	this->matrix[1] = 0;
	this->matrix[2] = 0;
	this->matrix[3] = 0;
	this->matrix[4] = 0; //Second row
	this->matrix[5] = 1;
	this->matrix[6] = 0;
	this->matrix[7] = 0;
	this->matrix[8] = 0; //Third row
	this->matrix[9] = 0;
	this->matrix[10] = 1;
	this->matrix[11] = 0;
	this->matrix[12] = 0; //Fourth row
	this->matrix[13] = 0;
	this->matrix[14] = 0;
	this->matrix[15] = 1;

}

RenderMatrix RenderMatrix::getIdentity() {

	RenderMatrix ret;

	//Set matrix to identity matrix
	ret.matrix[0] = 1; //First row
	ret.matrix[1] = 0;
	ret.matrix[2] = 0;
	ret.matrix[3] = 0;
	ret.matrix[4] = 0; //Second row
	ret.matrix[5] = 1;
	ret.matrix[6] = 0;
	ret.matrix[7] = 0;
	ret.matrix[8] = 0; //Third row
	ret.matrix[9] = 0;
	ret.matrix[10] = 1;
	ret.matrix[11] = 0;
	ret.matrix[12] = 0; //Fourth row
	ret.matrix[13] = 0;
	ret.matrix[14] = 0;
	ret.matrix[15] = 1;

	return ret;

}

void RenderMatrix::setNum(int index, float value) {

	if (index <= 15) {

		this->matrix[index] = value;

	}

}

void RenderMatrix::setNum(int indexX, int indexY, float value) {

	int index = indexX * 4 + indexY;


	if (index <= 15) {
	
		this->matrix[index] = value;

	}

}

void RenderMatrix::set_00(float value) {

	this->matrix[0] = value;

}

void RenderMatrix::set_01(float value) {

	this->matrix[1] = value;

}

void RenderMatrix::set_02(float value) {

	this->matrix[2] = value;

}

void RenderMatrix::set_03(float value) {

	this->matrix[3] = value;

}

void RenderMatrix::set_10(float value) {

	this->matrix[4] = value;

}

void RenderMatrix::set_11(float value) {

	this->matrix[5] = value;

}

void RenderMatrix::set_12(float value) {

	this->matrix[6] = value;

}

void RenderMatrix::set_13(float value) {

	this->matrix[7] = value;

}

void RenderMatrix::set_20(float value) {

	this->matrix[8] = value;

}

void RenderMatrix::set_21(float value) {

	this->matrix[9] = value;

}

void RenderMatrix::set_22(float value) {

	this->matrix[10] = value;

}

void RenderMatrix::set_23(float value) {

	this->matrix[11] = value;

}

void RenderMatrix::set_30(float value) {

	this->matrix[12] = value;

}

void RenderMatrix::set_31(float value) {

	this->matrix[13] = value;

}

void RenderMatrix::set_32(float value) {

	this->matrix[14] = value;

}

void RenderMatrix::set_33(float value) {

	this->matrix[15] = value;

}

float RenderMatrix::getNum(int index) {

	return this->matrix[index];

}

float RenderMatrix::getNum(int indexX, int indexY) {

	int index = indexX * 4 + indexY;

	return this->matrix[index];

}

float* RenderMatrix::getMatrix() {

	return this->matrix;

}

float RenderMatrix::get_00() {

	return this->matrix[0];

}

float RenderMatrix::get_01() {

	return this->matrix[1];

}

float RenderMatrix::get_02() {

	return this->matrix[2];

}

float RenderMatrix::get_03() {

	return this->matrix[3];

}

float RenderMatrix::get_10() {

	return this->matrix[4];

}

float RenderMatrix::get_11() {

	return this->matrix[5];

}

float RenderMatrix::get_12() {

	return this->matrix[6];

}

float RenderMatrix::get_13() {

	return this->matrix[7];

}

float RenderMatrix::get_20() {

	return this->matrix[8];

}

float RenderMatrix::get_21() {

	return this->matrix[9];

}

float RenderMatrix::get_22() {

	return this->matrix[10];

}

float RenderMatrix::get_23() {

	return this->matrix[11];

}

float RenderMatrix::get_30() {

	return this->matrix[12];

}

float RenderMatrix::get_31() {

	return this->matrix[13];

}

float RenderMatrix::get_32() {

	return this->matrix[14];

}

float RenderMatrix::get_33() {

	return this->matrix[15];

}

void RenderMatrix::transposeMatrix(float x, float y, float z) {

	this->matrix[0] += x;
	this->matrix[5] += y;
	this->matrix[10] += z;

}

void RenderMatrix::scaleMatrix(float a, float b, float c) {

	this->matrix[3] *= a;
	this->matrix[7] *= b;
	this->matrix[11] *= c;

}

void RenderMatrix::setLocation(float x, float y, float z) {

	this->matrix[0] = x;
	this->matrix[5] = y;
	this->matrix[10] = z;

}

void RenderMatrix::setScale(float a, float b, float c) {

	this->matrix[3] = a;
	this->matrix[7] = b;
	this->matrix[11] = c;

}

RenderMatrix RenderMatrix::multiply(RenderMatrix product) {

	RenderMatrix ret;

	ret.set_00(this->get_00() * product.get_00() + this->get_01() * product.get_10() + this->get_02() * product.get_20() + this->get_03() * product.get_30());
	ret.set_01(this->get_00() * product.get_01() + this->get_01() * product.get_11() + this->get_02() * product.get_21() + this->get_03() * product.get_31());
	ret.set_02(this->get_00() * product.get_02() + this->get_01() * product.get_12() + this->get_02() * product.get_22() + this->get_03() * product.get_32());
	ret.set_03(this->get_00() * product.get_03() + this->get_01() * product.get_13() + this->get_02() * product.get_23() + this->get_03() * product.get_33());
	ret.set_10(this->get_10() * product.get_00() + this->get_11() * product.get_10() + this->get_12() * product.get_20() + this->get_13() * product.get_30());
	ret.set_11(this->get_10() * product.get_01() + this->get_11() * product.get_11() + this->get_12() * product.get_21() + this->get_13() * product.get_31());
	ret.set_12(this->get_10() * product.get_02() + this->get_11() * product.get_12() + this->get_12() * product.get_22() + this->get_13() * product.get_32());
	ret.set_13(this->get_10() * product.get_03() + this->get_11() * product.get_13() + this->get_12() * product.get_23() + this->get_13() * product.get_33());
	ret.set_20(this->get_20() * product.get_00() + this->get_21() * product.get_10() + this->get_22() * product.get_20() + this->get_23() * product.get_30());
	ret.set_21(this->get_20() * product.get_01() + this->get_21() * product.get_11() + this->get_22() * product.get_21() + this->get_23() * product.get_31());
	ret.set_22(this->get_20() * product.get_02() + this->get_21() * product.get_12() + this->get_22() * product.get_22() + this->get_23() * product.get_32());
	ret.set_23(this->get_20() * product.get_03() + this->get_21() * product.get_13() + this->get_22() * product.get_23() + this->get_23() * product.get_33());
	ret.set_30(this->get_30() * product.get_00() + this->get_31() * product.get_10() + this->get_32() * product.get_20() + this->get_33() * product.get_30());
	ret.set_31(this->get_30() * product.get_01() + this->get_31() * product.get_11() + this->get_32() * product.get_21() + this->get_33() * product.get_31());
	ret.set_32(this->get_30() * product.get_02() + this->get_31() * product.get_12() + this->get_32() * product.get_22() + this->get_33() * product.get_32());
	ret.set_33(this->get_30() * product.get_03() + this->get_31() * product.get_13() + this->get_32() * product.get_23() + this->get_33() * product.get_33());

	return ret;

}
