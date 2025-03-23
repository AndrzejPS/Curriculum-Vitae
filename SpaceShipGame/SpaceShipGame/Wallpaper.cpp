#include "Wallpaper.h"

//private methods
void Wallpaper::initVariables()
{
	this->wallpaper_texture.loadFromFile("Graphics\\cosmos.jpg");
	this->wallpaper_sprite.setTexture(wallpaper_texture);
}

//constructor & destructor
Wallpaper::Wallpaper()
{
	this->initVariables();
}

Wallpaper::~Wallpaper()
{

}

//public methods
void Wallpaper::drawWallpaper(sf::RenderTarget* target)
{
	target->draw(this->wallpaper_sprite);
}

