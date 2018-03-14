#pragma once
class Rectangle {

public:

	Rectangle();
	Rectangle(float, float, float, float);
	~Rectangle();

	static bool rectIsColliding(Rectangle r1, Rectangle r2); 

	float getX();
	float getY();
	float getWidth();
	float getHeight();

	void setPos(float, float);
	void setSize(float, float);

	void translate(float, float);
	void scale(float, float);

private:

	float x;
	float y;

	float width;
	float height;

};

