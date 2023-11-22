#include "Input.h"

void CH::Input::SetBind(sf::Keyboard::Key keyboardInput, std::function<void()> func)
{
	*_inputType = InputType::Keyboard;

	_localFunction = func;
}

void CH::Input::SetBind(sf::Mouse::Button mouseInput, std::function<void()> func)
{
	*_inputType = InputType::Mouse;

	_localFunction = func;
}

void CH::Input::DoBind()
{
	switch (*_inputType)
	{
	case InputType::Keyboard:
		if (sf::Keyboard::isKeyPressed(*_keyboardInput))
		{
			_localFunction();
		}
	case InputType::Mouse:
		if (sf::Mouse::isButtonPressed(*_mouseInput))
		{
			_localFunction();
		}
	}
}
