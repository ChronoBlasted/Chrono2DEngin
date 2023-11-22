#pragma once
#include <SFML/Graphics.hpp>

namespace CH {
	class FontManager
	{
	public:
		FontManager();
		~FontManager();

		void Init();

		static FontManager* GetInstance();

		sf::Font* GetFont(std::string fontName);
		void LoadFont(std::string fontName);

	protected:
		static FontManager* _instance;

		std::map<std::string, sf::Font*> _allFonts;

	private:
	};
}