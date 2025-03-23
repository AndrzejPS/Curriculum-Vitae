#pragma once
#include <SFML/Graphics.hpp>

class Wallpaper
{
	//private variables
	sf::Texture wallpaper_texture;
	sf::Sprite wallpaper_sprite{ wallpaper_texture };

	//private methods
	void initVariables();

	public:
		//constructor & destructor
		Wallpaper();
		~Wallpaper();

		//public methods
		void drawWallpaper(sf::RenderTarget* target);


};

