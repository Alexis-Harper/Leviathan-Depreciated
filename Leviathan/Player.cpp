#include "stdafx.h"

#include "Player.h"

#include "Input.h"

float vertecies[] = {

	//Position		//TextureArray
	-0.25, -0.25,	-1.0, -1.0,
	-0.25, 0.25,	-1.0, 1.0,
	0.25, -0.25,	1.0, -1.0,
	0.25, 0.25,		1.0, 1.0

};

unsigned int indecies[] {

	//Triangles
	0, 1, 3,
	1, 2, 3

};

Player::Player() {

	this->hp = 100;
	this->hpMax = 100;
	this->ammo = 100;
	this->ammoMax = 100;
	this->attack = 1;
	this->range = 1;
	this->defence = 1;
	this->speed = 1;

	this->xPos = 0.0f;
	this->yPos = 0.0f;

	this->vX = 0.0f;
	this->vY = 0.0f;

	/*
	glGenTextures(1, &texture); //Generate OpenGL texture ID
	glBindTexture(GL_TEXTURE_2D, texture); //Bind ID to GL_TEXTURE_2D

	std::ifstream vShaderFile, fShaderFile; //Create a few variables
	std::stringstream vShaderStream, fShaderStream;
	std::string vCode, fCode;

	try {

		vShaderFile.open("Assets/shaders/player_vs.glsl"); //Load shader files
		fShaderFile.open("Assets/shaders/player_fs.glsl");

		vShaderStream << vShaderFile.rdbuf(); //Convert file to string stream
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close(); //Close files
		fShaderFile.close();

		vCode = vShaderStream.str(); //Convert string stream to single string
		fCode = fShaderStream.str();

	} catch (std::ifstream::failure e) {

		std::cout << "[-] ifstream: Player shaders failed to load";

	}

	const char *vChar = vCode.c_str(); //Convert string to char array (C String)
	const char *fChar = fCode.c_str();

	vertexShader = glCreateShader(GL_VERTEX_SHADER); //Create shader ID
	glShaderSource(vertexShader, 1, &vChar, NULL); //Add source
	glCompileShader(vertexShader); //Compile shader

	///* Comment out after testing (test for errors)
	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {

		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "[-] GLSL: Vertex Shader failed to compile\n" << infoLog << "\n";

	} //*/

	/*
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); //Create shader ID
	glShaderSource(fragmentShader, 1, &fChar, NULL); //Add source
	glCompileShader(fragmentShader); //Compile shader

	///* Comment out after testing (test for errors)
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {

		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "[-] GLSL: Vertex Shader failed to compile\n" << infoLog << "\n";

	} //*/

	/*
	shaderProgram = glCreateProgram(); //Create shader program

	glAttachShader(shaderProgram, vertexShader); //Attach two shaders to program
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram); //Link two shaders together

	glGenVertexArrays(1, &VAO); //Generate vertex array ID
	glGenBuffers(1, &VBO); //Generate two buffer ID's (one for vertexes, the other for indecies)
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO); //Bind buffer VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_DYNAMIC_DRAW); //Add vertecies to binded buffer (VBO)

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); //Bind buffer EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecies), indecies, GL_STATIC_DRAW); //Add indecies to binded buffer (EBO)

	//This part is really complecated
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0)); //Position array
	glEnableVertexAttribArray(0); 

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1); 

	image = stbi_load("Assets/images/sprites/player/Player.png", &width, &height, &comp, STBI_rgb_alpha); //Load image

	//Check if image loaded
	if (image == 0) {

		std::cout << "[-] STBI: Player spritesheet failed to load";

	} else {

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image); //Set up texture on GPU
		glGenerateMipmap(GL_TEXTURE_2D); //Generate texture

		stbi_image_free(image); //Clear up space

	} //*/

	/*
	hurtSoundPhy = alutCreateBufferFromFile("assets/sound/effects/player/hurtPhy.wav");
	hurtSoundMag = alutCreateBufferFromFile("assets/sound/effects/player/hurtMag.wav");
	deathSound = alutCreateBufferFromFile("assets/sound/effects/player/death.wav");

	alGenSources(1, &playerSource);
	//*/

}

Player::~Player() {

	/*
	glDeleteShader(vertexShader); //Delete shaders
	glDeleteShader(fragmentShader);

	glDeleteVertexArrays(1, &VAO); //Delete buffers
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	*/

}

void Player::damagePhy(int attack) {

	int health = attack / this->defence; //How much health is taken

	if (health >= hp) {

		//Die

		alSourcei(playerSource, AL_BUFFER, deathSound);
		alSourcePlay(playerSource);

	} else {

		//Take damage

		alSourcei(playerSource, AL_BUFFER, hurtSoundPhy);
		alSourcePlay(playerSource);

		hp -= health;

	}

}

void Player::update() {

	//Get direction; temp layout (saves resources and time)
	bool upKey = Input::isKeyPressed(GLFW_KEY_UP);
	bool rightKey = Input::isKeyPressed(GLFW_KEY_RIGHT);
	bool downKey = Input::isKeyPressed(GLFW_KEY_DOWN);
	bool leftKey = Input::isKeyPressed(GLFW_KEY_LEFT);

	bool run = Input::isKeyPressed(GLFW_KEY_C); //Run button; temp layout

	int eightDirection = Input::eightDirection(0); //Joystick if necessary

	//Tons of movement stuff (if certain moement, change graphics direction and velocity)
	if ((upKey && rightKey && !downKey && !leftKey) || eightDirection == UP_RIGHT) {

		direction = UP_RIGHT;

		this->vX = (float)(1.414213562373095048 + (1.414213562373095048 * run)) * canMove[1] * this->speed;
		this->vY = (float)(1.414213562373095048 + (1.414213562373095048 * run)) * canMove[0] * this->speed;

	} else if ((upKey && !rightKey && !downKey && leftKey) || eightDirection == UP_LEFT) {

		direction = UP_LEFT;

		this->vX = (float)(-1.414213562373095048 - (1.414213562373095048 * run)) * canMove[3] * this->speed;
		this->vY = (float)(1.414213562373095048 + (1.414213562373095048 * run)) * canMove[0] * this->speed;

	} else if ((upKey && !rightKey && !downKey && !leftKey) || eightDirection == UP) {

		direction = UP;

		this->vX = 0.0f;
		this->vY = (1.0f + run) * canMove[0] * this->speed;

	} else if ((!upKey && rightKey && !downKey && !leftKey) || eightDirection == RIGHT) {

		direction = RIGHT;

		this->vX = (1.0f + run) * canMove[1] * this->speed;
		this->vY = 0.0f;

	} else if ((!upKey && rightKey && downKey && !leftKey) || eightDirection == DOWN_RIGHT) {

		direction = DOWN_RIGHT;

		this->vX = (float)(1.41421356237309 + (1.41421356237309 * run)) * canMove[1] * this->speed;
		this->vY = (float)(-1.41421356237309 - (1.41421356237309 * run)) * canMove[2] * this->speed;

	} else if ((!rightKey && !upKey && downKey && !leftKey) || eightDirection == DOWN_LEFT) {

		direction = DOWN_LEFT;

		this->vX = (float)((-1.414213562373095048) - (1.414213562373095048 * run)) * canMove[3] * this->speed;
		this->vY = (float)((-1.414213562373095048) - (1.414213562373095048 * run)) * canMove[2] * this->speed;

	} else if ((!rightKey && !upKey && downKey && !leftKey) || eightDirection == DOWN) {

		direction = DOWN;

		this->vX = 0.0f;
		this->vY = (-1.0f - run) * canMove[2] * this->speed;

	} else if ((!rightKey && !upKey && !downKey && leftKey) || eightDirection == LEFT) {

		direction = LEFT;

		this->vX = (-1.0f - run) * canMove[3] * this->speed;
		this->vY = 0.0f;

	} else {

		this->vX = 0.0f; //If no movement, keep direction facing sprite, but stop movement
		this->vY = 0.0f;

	}

	this->xPos += (float)(vX * Input::delta); //Change position by velocity times delta (the ratio of frames to timeframe)
	this->yPos += (float)(vY * Input::delta);

	this->hitbox.translate(vX, vY); //Translate hitbox

}

void Player::render() {

	glBindTexture(GL_TEXTURE_2D, texture); //Bind texture on render

	glUseProgram(shaderProgram); //Use shader

	glBindVertexArray(VAO); //Bind player buffers

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //Render player

}

void Player::move(bool up, bool right, bool down, bool left) {

	this->canMove[0] = up;
	this->canMove[1] = right;
	this->canMove[2] = down;
	this->canMove[3] = left;

}

//Setters

void Player::setStats(int hp, int hpMax, int ammo, int ammoMax, int attack, int range, int defence, int speed) {

	this->hp = hp;
	this->hpMax = hpMax;
	this->ammo = ammo;
	this->ammoMax = ammoMax;
	this->attack = attack;
	this->range = range;
	this->defence = defence;
	this->speed = speed;

}

void Player::setPosition(float x, float y) {

	this->xPos = x;
	this->yPos = y;

}

//Getters

int Player::getHp() {

	return this->hp;

}

int Player::getHpMax() {

	return this->hpMax;

}

int Player::getAmmo() {

	return this->ammo;

}

int Player::getAmmoMax() {

	return this->ammoMax;

}

int Player::getAttack() {

	return this->attack;

}

int Player::getRange() {

	return this->range;

}

int Player::getDefence() {

	return this->defence;

}

int Player::getSpeed() {

	return this->speed;

}

float Player::getX() {

	return this->xPos;

}

float Player::getY() {

	return this->yPos;

}
