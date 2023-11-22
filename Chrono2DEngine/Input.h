#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

namespace CH {
	class  Input
	{
	public:
		enum class InputType { None, Keyboard, Mouse };

		void SetBind(sf::Keyboard::Key keyboardInput, std::function<void()> func);

		void SetBind(sf::Mouse::Button mouseInput, std::function<void()> func);

		void DoBind();
	protected:
		InputType* _inputType;

		sf::Keyboard::Key* _keyboardInput;
		sf::Mouse::Button* _mouseInput;

		std::function<void()> _localFunction;
	private:
	};
}


