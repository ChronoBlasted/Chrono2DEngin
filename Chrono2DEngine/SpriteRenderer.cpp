#include "SpriteRenderer.h"
#include "RessourceManager.h"
#include <iostream>

void CH::SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

CH::SpriteRenderer::SpriteRenderer()
{
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

void CH::SpriteRenderer::SetOrigin(int originX, int originY)
{
	_sprite.setOrigin(sf::Vector2f(originX, originY));
}

void CH::SpriteRenderer::SetSmooth(bool isSmooth)
{
	_texture.setSmooth(isSmooth);
}

void CH::SpriteRenderer::SetRepeated(bool isRepeated)
{
	_texture.setRepeated(isRepeated);
}

void CH::SpriteRenderer::UpdateScale(int scaleX, int scaleY)
{
	_sprite.setScale(scaleX, scaleY);
}

void CH::SpriteRenderer::UpdateSize(int sizeX, int sizeY)
{
	_sprite.setTextureRect(sf::IntRect(0, 0, 18 * sizeX, 18 * sizeY));
}

sf::Sprite* CH::SpriteRenderer::GetSprite()
{
	return &_sprite;
}