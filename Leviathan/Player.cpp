#include "Player.h"

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

	glGenTextures(1, &texture); //Generate OpenGL texture ID
	glBindTexture(GL_TEXTURE_2D, texture); //Bind ID to GL_TEXTURE_2D

	std::ifstream vShaderFile, fShaderFile; //Create a few variables
	std::stringstream vShaderStream, fShaderStream;
	std::string vCode, fCode;

	try {

		vShaderFile.open("player_vs.glsl"); //Load shader files
		fShaderFile.open("player_fs.glsl");

		vShaderStream << vShaderFile.rdbuf(); //Convert file to string stream
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close(); //Close files
		fShaderFile.close();

		vCode = vShaderStream.str(); //Convert string stream to single string
		fCode = fShaderStream.str();

	} catch (std::ifstream::failure e) {

		cout << "[-] ifstream: Player shaders failed to load";

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
		std::cout << "[-] GLSL: Vertex Shader failed to compile\n" << infoLog << "\N";

	} //*/

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); //Create shader ID
	glShaderSource(fragmentShader, 1, &fChar, NULL); //Add source
	glCompileShader(fragmentShader); //Compile shader

	///* Comment out after testing (test for errors)
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {

		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "[-] GLSL: Vertex Shader failed to compile\n" << infoLog << "\N";

	} //*/

	shaderProgram = glCreateProgram(); //Create shader program

	glAttachShader(shaderProgram, vertexShader); //Attach two shaders to program
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram); //Link two shaders together

	glGenVertexArrays(1, &VAO); //Generate vertex array ID
	glGenBuffers(1, &VBO); //Generate two buffer ID's (one for vertexes, the other for indecies)
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecies), indecies, GL_STATIC_DRAW);

	//This part is really complecated
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0)); //Position array
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	image = stbi_load("Player.png", &width, &height, &comp, STBI_rgb_alpha); //Load image

	//Check if image loaded
	if (image == 0) {

		cout << "[-] STBI: Player spritesheet failed to load";

	} else {

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image); //Set up texture on GPU
		glGenerateMipmap(GL_TEXTURE_2D); //Generate texture

		stbi_image_free(image); //Clear up space

	}
	
}

Player::~Player() {

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

}

void Player::render() {

	glBindTexture(GL_TEXTURE_2D, texture); //Bind texture on render

	glUseProgram(shaderProgram); //Use shader

	glBindVertexArray(VAO); //Bind player buffers

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //Render player

}
