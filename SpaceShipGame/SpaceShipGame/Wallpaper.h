#pragma once
#include <SFML/Graphics.hpp>

class Wallpaper
{
	//private variables
	sf::Texture wallpaper_texture;
	sf::Sprite* wallpaper_sprite;

	//private methods
	void initVariables(const sf::RenderTarget& target);

	public:
		//constructor & destructor
		Wallpaper(const sf::RenderTarget& target);
		~Wallpaper();

		//public methods
		void drawWallpaper(sf::RenderTarget& target);
};

