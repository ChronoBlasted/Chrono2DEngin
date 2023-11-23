#include "AudioClip.h"
#include <iostream>
#include "RessourceManager.h"

void CH::AudioClip::LoadMusic(std::string musicName)
{
	std::string pathToMusic = CH::RessourceManager::GetInstance()->GetPathById(musicName);

	_music = new sf::Music();

	if (!_music->openFromFile(pathToMusic))
	{
		std::cout << "Error loading " << musicName << " music file name" << std::endl;
	}


	if (_sound != nullptr) {
		delete _sound;
		_sound = nullptr;
	}
}

void CH::AudioClip::LoadSound(std::string soundName)
{
	std::string pathToSound = CH::RessourceManager::GetInstance()->GetPathById(soundName);

	if (!_buffer.loadFromFile(pathToSound)) {
		std::cout << "Error loading " << soundName << " sound file name" << std::endl;
	}

	_sound = new sf::Sound();
	_sound->setBuffer(_buffer);

	if (_music != nullptr) {
		delete _music;
		_music = nullptr;
	}
}

void CH::AudioClip::SetPitch(float newPitch)
{
	if (_music != nullptr) _music->setPitch(newPitch);
	if (_sound != nullptr) _sound->setPitch(newPitch);
}

void CH::AudioClip::SetVolume(float newVolume)
{
	if (_music != nullptr) _music->setVolume(newVolume);
	if (_sound != nullptr) _sound->setVolume(newVolume);
}

void CH::AudioClip::SetLoop(bool isLooping)
{
	if (_music != nullptr) _music->setLoop(isLooping);
	if (_sound != nullptr) _sound->setLoop(isLooping);
}

void CH::AudioClip::Play()
{
	if (_music != nullptr) _music->play();
	if (_sound != nullptr) _sound->play();
}

void CH::AudioClip::Pause()
{
	if (_music != nullptr) _music->pause();
	if (_sound != nullptr) _sound->pause();
}

void CH::AudioClip::Stop()
{
	if (_music != nullptr) _music->stop();
	if (_sound != nullptr) _sound->stop();
}