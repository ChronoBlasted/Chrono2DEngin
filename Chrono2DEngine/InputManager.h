#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Input.h"

namespace CH {
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void Init();

		void AddInput(std::string inputName, Input* inputToAdd);
		void RemoveInput(std::string inputName);

		bool GetInput(std::string inputName);

		static InputManager* GetInstance();

		void DoInput();

	protected:
		static InputManager* _instance;

		std::map<std::string, CH::Input*> _allInputs;
	private:
	};
}