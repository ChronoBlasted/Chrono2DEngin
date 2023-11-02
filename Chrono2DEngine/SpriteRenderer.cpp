#include "SpriteRenderer.h"
#include "RessourceManager.h"


void CH::SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

CH::SpriteRenderer::SpriteRenderer()
{
	_texture.create(256, 256);
	_sprite.setTexture(_texture);
}

CH::SpriteRenderer::~SpriteRenderer()
{
}

void CH::SpriteRenderer::SetTexture(std::string textureId)
{
	std::string pathToImg = CH::RessourceManager::GetInstance()->GetPathById(textureId);

	_texture.loadFromFile(pathToImg);

	_sprite.setTexture(_texture);
}

void CH::SpriteRenderer::SetColor(sf::Color newColor)
{
	_sprite.setColor(newColor);
}

void CH::SpriteRenderer::SetSmooth(bool isSmooth)
{
	_texture.setSmooth(isSmooth);
}

void CH::SpriteRenderer::SetRepeated(bool isRepeated)
{
	_texture.setRepeated(isRepeated);
}

sf::Sprite* CH::SpriteRenderer::GetSprite()
{
	return &_sprite;
}



