#pragma once
#include <string>
#include <map>
#include "AudioClip.h"


namespace CH {
	class AudioManager
	{
	public:
		void PlayMusic(std::string musicName);
		void PlaySound(std::string soundName);

		void Init();

		static AudioManager* GetInstance();

	protected:
		static AudioManager* _instance;


		std::map<std::string, CH::AudioClip*> _allAudioClips;

	private:
	};
}