#include "FontManager.h"
#include <iostream>
#include "RessourceManager.h"

CH::FontManager* CH::FontManager::_instance = nullptr;

CH::FontManager::FontManager()
{
	_instance = this;
}

CH::FontManager::~FontManager()
{
}

void CH::FontManager::Init()
{
	LoadFont("Poppins");
	LoadFont("Arial");
}

CH::FontManager* CH::FontManager::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new FontManager();
	}

	return _instance;
}

sf::Font* CH::FontManager::GetFont(std::string fontName)
{
	sf::Font* resultFont = nullptr;;

	for (auto& [key, value] : _allFonts) {
		if (key == fontName) {
			resultFont = value;
		}
	}

	return resultFont;
}

void CH::FontManager::LoadFont(std::string fontName)
{
	std::string pathToFont = CH::RessourceManager::GetInstance()->GetPathById(fontName);

	sf::Font* font = new sf::Font();
	if (!font->loadFromFile(pathToFont))
	{
		std::cout << "Error loading " << pathToFont << " font file" << std::endl;
	}
	else
	{
		_allFonts.insert({ fontName, font });
	}
}