#pragma once

#include "AudioEnum.h"

#include "Input.h"

class Audio {

public:

	Audio();
	~Audio();

	void render();

	void stopMusic();
	void fadeOut();
	void changeMusic(char*);

private:

	//Fade out
	float p[3] = { 0.0f, 0.0f, 0.0f };
	bool v;

} audioObject;
