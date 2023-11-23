#include "InputManager.h"
#include <iostream>

CH::InputManager* CH::InputManager::_instance = nullptr;

CH::InputManager::InputManager()
{
	_instance = this;
}

CH::InputManager::~InputManager()
{
}

void CH::InputManager::Init()
{
}

void CH::InputManager::AddInput(std::string inputName, Input* inputToAdd)
{
	_allInputs.insert({ inputName, inputToAdd });
}

void CH::InputManager::RemoveInput(std::string inputName)
{
	_allInputs.erase(inputName);
}

bool CH::InputManager::GetInput(std::string inputName)
{
	for (auto& [key, value] : _allInputs) {
		if (key == inputName) {
			return value->IsPressed;
		}
	}

	return false;
}

CH::InputManager* CH::InputManager::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new InputManager();
	}

	return _instance;
}

void CH::InputManager::DoInput()
{
	for (auto& [key, value] : _allInputs) {
		value->DoBind();
	}
}
