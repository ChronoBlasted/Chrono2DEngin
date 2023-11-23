#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

namespace CH {
	class SpriteRenderer : public sf::Drawable, public CH::Component
	{
	public:
		void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

		SpriteRenderer();
		~SpriteRenderer();

		void SetTexture(std::string);
		void SetColor(sf::Color);
		void SetSmooth(bool);
		void SetRepeated(bool);

		void UpdateSize(int, int);

		sf::Sprite* GetSprite();
	protected:
		sf::Sprite _sprite;
		sf::Texture _texture;
	private:
	};
}