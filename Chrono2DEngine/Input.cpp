#include "Input.h"
#include <iostream>

CH::Input::Input()
{
	_inputType = new InputType();
}

CH::Input::~Input()
{
}

void CH::Input::SetBind(sf::Keyboard::Key keyboardInput)
{
	_keyboardInput = keyboardInput;

	*_inputType = InputType::Keyboard;
}

void CH::Input::SetBind(sf::Mouse::Button mouseInput)
{
	_mouseInput = mouseInput;

	*_inputType = InputType::Mouse;
}

void CH::Input::DoBind()
{
	IsPressed = false;

	switch (*_inputType)
	{
	case InputType::Keyboard:
		if (sf::Keyboard::isKeyPressed(_keyboardInput))
		{
			IsPressed = true;
		}
		break;
	case InputType::Mouse:
		if (sf::Mouse::isButtonPressed(_mouseInput))
		{
			IsPressed = true;
		}
		break;
	}
}