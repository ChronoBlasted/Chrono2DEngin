#pragma once
#include <yaml-cpp/yaml.h>
#include <string>

namespace CH {
	class RessourceManager
	{
	public:
		RessourceManager();
		~RessourceManager();

		void Init();
		std::string GetPathById(std::string key);

		static RessourceManager* GetInstance();

	protected:
		std::string finalPath;
		YAML::Node data;

		void LoadPath();

		static RessourceManager* _instance;
	private:
	};
}
