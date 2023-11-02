#include <iostream>
#include <filesystem>
#include "RessourceManager.h"
#include "Application.h"
#include <fstream>
#include <windows.h>


CH::RessourceManager* CH::RessourceManager::_instance = nullptr;

void CH::RessourceManager::Init()
{
	LoadPath();

	data = YAML::LoadFile(finalPath + "/Chrono2DEngine.yaml");
}

std::string CH::RessourceManager::GetPathById(std::string key)
{
	std::string value = data[key].as<std::string>();

	return finalPath + "/" + value;
}

CH::RessourceManager* CH::RessourceManager::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new RessourceManager();
	}

	return _instance;
}

void CH::RessourceManager::LoadPath()
{
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);

	std::filesystem::path filePath = buffer;

	finalPath = filePath.parent_path().string();
}
