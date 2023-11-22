#include "AudioClip.h"
#include <iostream>
#include "RessourceManager.h"

void CH::AudioClip::LoadMusic(std::string musicName)
{
	std::string pathToMusic = CH::RessourceManager::GetInstance()->GetPathById(musicName);

	if (!_music->openFromFile(pathToMusic))
	{
		std::cout << "Error loading " << musicName << " music file name" << std::endl;
	}
}

void CH::AudioClip::LoadSound(std::string soundName)
{
	std::string pathToSound = CH::RessourceManager::GetInstance()->GetPathById(soundName);

	if (!_buffer->loadFromFile(pathToSound)) {
		std::cout << "Error loading " << soundName << " sound file name" << std::endl;
	}

	_sound->setBuffer(*_buffer);
}

void CH::AudioClip::SetPitch(float newPitch)
{
	_sound->setPitch(newPitch);
	_music->setPitch(newPitch);
}

void CH::AudioClip::SetVolume(float newVolume)
{
	_sound->setVolume(newVolume);
	_music->setVolume(newVolume);
}

void CH::AudioClip::SetLoop(bool isLooping)
{
	_sound->setLoop(isLooping);
	_music->setLoop(isLooping);
}



void CH::AudioClip::PlayMusic()
{
	_music->play();
}

void CH::AudioClip::PauseMusic()
{
	_music->pause();
}

void CH::AudioClip::StopMusic()
{
	_music->stop();
}

void CH::AudioClip::PlaySound()
{
	_sound->play();
}

void CH::AudioClip::PauseSound()
{
	_sound->pause();
}

void CH::AudioClip::StopSound()
{
	_sound->stop();
}