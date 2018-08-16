#pragma once

#ifndef AUDIO_H
#define AUDIO_H

#include "AudioEnum.h"

namespace Audio {

	void render();

	void stopMusic();
	void replaceEnding(char*);
	void changeMusic(char*);

	bool getRepeatMusic();
	void setRepeatMusic(bool);
	void toggleRepeatMusic();

};

#endif
