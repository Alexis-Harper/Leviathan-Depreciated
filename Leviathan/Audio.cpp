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

}

Audio::~Audio() {

	alDeleteBuffers(1, &musicBuffer);
	alDeleteSources(1, &musicSource);

}

void Audio::changeMusic(char* file) {

	alDeleteBuffers(1, &musicBuffer); //Delete existing buffer

	musicBuffer = alutCreateBufferFromFile(file); //Create new buffer

	alSourcei(musicSource, AL_BUFFER, musicBuffer); //Link buffer

}
