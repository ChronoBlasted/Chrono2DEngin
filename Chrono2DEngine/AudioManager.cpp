#include "AudioManager.h"

CH::AudioManager* CH::AudioManager::_instance = nullptr;

void CH::AudioManager::PlayMusic(std::string musicName)
{
	AudioClip* newAudio = new AudioClip();

	newAudio->LoadMusic(musicName);
	newAudio->Play();

	_allAudioClips.insert({ musicName, newAudio });
}

void CH::AudioManager::PlaySound(std::string soundName)
{
	AudioClip* newAudio = new AudioClip();

	newAudio->LoadSound(soundName);
	newAudio->Play();

	_allAudioClips.insert({ soundName, newAudio });
}

void CH::AudioManager::Init()
{
}

CH::AudioManager* CH::AudioManager::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new AudioManager();
	}

	return _instance;
}
