#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "Component.h"


namespace CH {
	class  Input
	{
	public:
		Input();
		~Input();

		enum class InputType { None, Keyboard, Mouse };

		void SetBind(sf::Keyboard::Key keyboardInput);
		void SetBind(sf::Mouse::Button mouseInput);

		void DoBind();

		bool IsPressed;
	protected:
		InputType* _inputType;

		sf::Keyboard::Key _keyboardInput;
		sf::Mouse::Button _mouseInput;
	private:
	};
}


