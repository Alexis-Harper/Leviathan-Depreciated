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

void Audio::render() {

	if (v) {

		if (p[1] == 30.0f) {

			v = false; //Reset position data
			p[1] = 0.0f;

			stopMusic();
			
		} else {

			p[1] += (float)(1.0f * inputObject.delta);

		}
		
		alGetSourcefv(musicSource, AL_POSITION, p);

	}

}

void Audio::stopMusic() {

	alSourceStop(musicSource); //Stop the source

	alDeleteBuffers(1, &musicBuffer); //Delete existing buffer

}

void Audio::fadeOut() {

	v = true;

}

void Audio::changeMusic(char* file) {

	musicBuffer = alutCreateBufferFromFile(file); //Create new buffer

	alSourcei(musicSource, AL_BUFFER, musicBuffer); //Link buffer

}
