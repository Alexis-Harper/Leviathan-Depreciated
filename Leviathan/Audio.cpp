#include "stdafx.h"

#include "Audio.h"

namespace Audio {

	/*namespace {

		ALuint musicBuffer, musicSource;

		bool repeatMusic = true; //Keep track of weather music repeats

		bool playNext = false;
		char* nextSong = new char[255];

	}

	void render() {

		ALint state; //Stores music state

		alGetSourcei(musicSource, AL_SOURCE_STATE, &state); //Gets music state

		//If song is over and playNext is on
		if (state != AL_PLAYING && playNext) {

			changeMusic(nextSong); //Change to next song

			playNext = false; //Turn off playNext

		}

	}

	void stopMusic() {

		alSourceStop(musicSource); //Stop the source

		alDeleteBuffers(1, &musicBuffer); //Delete existing buffer

	}

	void Audio::replaceEnding(char* buf) {

		//Stop looping
		repeatMusic = false;
		alSourcei(musicSource, AL_LOOPING, 0);

		playNext = true; //Turn on playNext

		int len = (int)(strlen(buf)); //Get length of buffer

		nextSong = new char[len]; //Dynamic memory FTW
		nextSong = buf; //Put buffer in next song name buffer

	}

	void changeMusic(char* file) {

		musicBuffer = alutCreateBufferFromFile(file); //Create new buffer

		alSourcei(musicSource, AL_BUFFER, musicBuffer); //Link buffer

	}

	bool getRepeatMusic() {

		return repeatMusic;

	}

	void setRepeatMusic(bool value) {

		repeatMusic = value;

		alSourcei(musicSource, AL_LOOPING, value);

	}

	void toggleRepeatMusic() {

		repeatMusic = !repeatMusic;

		alSourcei(musicSource, AL_LOOPING, repeatMusic);

	}*/

}
