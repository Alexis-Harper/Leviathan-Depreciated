#include "Player.h"

Player::Player() {

	image = stbi_load("assets/textures/Player.png", &width, &height, &comp, STBI_rgb_alpha); //Load image

	//Check if image loaded
	if (image == 0) {

		std::cout << "[-] STBI: Player spritesheet failed to load";

	} else {

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(image);

	}

}

Player::~Player() {

	

}

void Player::render() {



}
