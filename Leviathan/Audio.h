#pragma once

#ifndef AUDIO_H
#define AUDIO_H

#include "AudioEnum.h"

class Audio {

public:

	Audio();
	~Audio();

	void render();

	void stopMusic();
	void replaceEnding(char*);
	void changeMusic(char*);

	bool getRepeatMusic();
	void setRepeatMusic(bool);
	void toggleRepeatMusic();

private:

	bool repeatMusic = true; //Keep track of weather music repeats

	bool playNext = false;
	char* nextSong = new char[255];

} audioObject;

#endif
