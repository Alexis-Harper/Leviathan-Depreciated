#pragma once

#ifndef STDAFX
#define STDAFX

#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

#include <chrono>

#include <string>

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

	UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN_LEFT, LEFT, UP_LEFT, DOWN, NONE

};

#endif

#endif
