#pragma once

#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

#include <chrono>

#include <string>

#include <fstream>
#include <sstream>

// GLEW
#define GLEW_STATIC
#include <GL\glew.h>

// GLFW
#include <GLFW\glfw3.h>

//stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//Global enum (this is necessary)
#ifndef DIRECTION_H
#define DIRECTION_H

//8 direction enum
enum Direction {

	UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN_LEFT, LEFT, UP_LEFT, DOWN

};

#endif

//All Headers
#include "Input.h"
#include "Matrix.h"
#include "Player.h"
#include "Rectangle.h"
#include "Vector.h"

using namespace std;
