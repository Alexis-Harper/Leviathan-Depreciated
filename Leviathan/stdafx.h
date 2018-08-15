#pragma once

#ifndef STDAFX
#define STDAFX

#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

#include <chrono>

#include <string>

// GLEW
#define GLEW_STATIC
#include <GL\glew.h>

// GLFW
#define GLFW_DLL
#include <GLFW\glfw3.h>

//stb_image
#include "stb_image.h"

//OpenAL
#include <al.h>
#include <alc.h>
#include <alut.h>

#endif
