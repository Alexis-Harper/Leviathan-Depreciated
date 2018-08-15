#include "stdafx.h"

#include "Audio.h"

//Set up music
ALuint musicBuffer, musicSource;

Audio::Audio() {

	//Set listener data
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alListener3f(AL_VELOCITY, 0.0f, 0.0f, 0.0f);
	alListener3f(AL_ORIENTATION, 0.0f, 0.0f, 0.0f);

	alGetError(); //Clear error buffer

	musicBuffer = alutCreateBufferHelloWorld(); //Hello World to test rest of code (delete once done)

	//musicBuffer = alutCreateBufferFromFile("temp.wav"); //Create a buffer that stores the data of "temp.wav"

	//Check if buffer failed
	if (alutGetError() != ALUT_ERROR_NO_ERROR) {

		std::cout << "[-] ALut: File \"temp.wav\" could not load ";

	}

	//Create and link music buffer to a source
	alGenSources(1, &musicSource);
	alSourcei(musicSource, AL_BUFFER, musicBuffer);

	alSourcei(musicSource, AL_LOOPING, 1); //Turn on looping by default

}

Audio::~Audio() {

	alDeleteBuffers(1, &musicBuffer); //Delete buffers (important for memory)
	alDeleteSources(1, &musicSource);

	delete this->nextSong; //It's dynamic memory. This is 100% neccessary

}

void Audio::render() {

	ALint state; //Stores music state

	alGetSourcei(musicSource, AL_SOURCE_STATE, &state); //Gets music state

	//If song is over and playNext is on
	if (state != AL_PLAYING && this->playNext) {

		this->changeMusic(this->nextSong); //Change to next song

		this->playNext = false; //Turn off playNext

	}

}

void Audio::stopMusic() {

	alSourceStop(musicSource); //Stop the source

	alDeleteBuffers(1, &musicBuffer); //Delete existing buffer

}

void Audio::replaceEnding(char* buf) {

	//Stop looping
	this->repeatMusic = false;
	alSourcei(musicSource, AL_LOOPING, 0);

	this->playNext = true; //Turn on playNext

	int len = (int)(strlen(buf)); //Get length of buffer

	this->nextSong = new char[len]; //Dynamic memory FTW
	this->nextSong = buf; //Put buffer in next song name buffer

}

void Audio::changeMusic(char* file) {

	musicBuffer = alutCreateBufferFromFile(file); //Create new buffer

	alSourcei(musicSource, AL_BUFFER, musicBuffer); //Link buffer

}

bool Audio::getRepeatMusic() {

	return this->repeatMusic;

}

void Audio::setRepeatMusic(bool value) {

	this->repeatMusic = value;

	alSourcei(musicSource, AL_LOOPING, value);

}

void Audio::toggleRepeatMusic() {

	this->repeatMusic = !this->repeatMusic;

	alSourcei(musicSource, AL_LOOPING, this->repeatMusic);

}
