#include "TextMeshPro.h"
#include "FontManager.h"

CH::TextMeshPro::TextMeshPro()
{
	SetString("New text");

	sf::Font* defaultFont = CH::FontManager::GetInstance()->GetFont("Arial");
	SetFont(*defaultFont);

	SetCharacterSize(36);
}

CH::TextMeshPro::~TextMeshPro()
{
}

void CH::TextMeshPro::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_text, states);
}

void CH::TextMeshPro::SetFont(sf::Font& newFont)
{
	_text.setFont(newFont);
}

void CH::TextMeshPro::SetPosition(float x, float y)
{
	_text.setPosition(x, y);
}

void CH::TextMeshPro::SetString(const char* newString)
{
	_text.setString(newString);
}

void CH::TextMeshPro::SetCharacterSize(int newPixelSize)
{
	_text.setCharacterSize(newPixelSize);
}

void CH::TextMeshPro::SetFillColor(sf::Color& newColor)
{
	_text.setFillColor(newColor);
}

void CH::TextMeshPro::SetTextStyle(sf::Uint32& text)
{
	_text.setStyle(text);
}