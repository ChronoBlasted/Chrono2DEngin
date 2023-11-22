#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

namespace CH {

	class TextMeshPro : public sf::Drawable, public CH::Component
	{
	public:
		void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

		TextMeshPro();
		~TextMeshPro();

		void SetFont(sf::Font& newFont);
		void SetString(std::string& newString);
		void SetCharacterSize(int newPixelSize);
		void SetFillColor(sf::Color& newColor);
		void SetTextStyle(sf::Uint32& text);
	protected:
		sf::Text* _text;
	private:
	};
}
