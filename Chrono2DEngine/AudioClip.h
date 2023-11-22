#pragma once
#include <SFML/Audio.hpp>
#include <string>

namespace CH {
	class AudioClip
	{
	public:
		void LoadMusic(std::string musicName);
		void LoadSound(std::string soundName);

		void SetPitch(float newPitch);
		void SetVolume(float newVolume);
		void SetLoop(bool isLooping);

		void PlayMusic();
		void PauseMusic();
		void StopMusic();

		void PlaySound();
		void PauseSound();
		void StopSound();
	protected:
		sf::SoundBuffer* _buffer;
		sf::Sound* _sound;
		sf::Music* _music;
	private:
	};
}