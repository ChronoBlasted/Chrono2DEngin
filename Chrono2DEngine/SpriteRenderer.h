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

		void SetTexture(std::string textureId);
		void SetColor(sf::Color newColor);
		void SetSmooth(bool isSmooth);
		void SetRepeated(bool isRepeated);

		sf::Sprite* GetSprite();
	protected:
		sf::Sprite _sprite;
		sf::Texture _texture;
	private:
	};
}