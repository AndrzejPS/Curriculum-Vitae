#include "Wallpaper.h"
#include <iostream>

//private methods
void Wallpaper::initVariables(const sf::RenderTarget& target)
{
	//wallpaper texture
	if (!this->wallpaper_texture.loadFromFile("Graphics/cosmos.jpg"))
	{
		std::cout << "\nERROR::WALLPAPER::INITVARIABLES::Couldn't load the wallpaper texture!\n";
	}

	//wallpaper sprite
	this->wallpaper_sprite = new sf::Sprite(wallpaper_texture);
	this->wallpaper_sprite->setOrigin({ this->wallpaper_texture.getSize().x / 2.f,this->wallpaper_texture.getSize().y / 2.f });
	this->wallpaper_sprite->setPosition({target.getSize().x/2.f,target.getSize().y/2.f});
	this->wallpaper_sprite->setScale({ static_cast<float>(target.getSize().x) / this->wallpaper_texture.getSize().x, static_cast<float>(target.getSize().y) / this->wallpaper_texture.getSize().y });

}

//constructor & destructor
Wallpaper::Wallpaper(const sf::RenderTarget& target)
{
	this->initVariables(target);
}

Wallpaper::~Wallpaper()
{
	delete this->wallpaper_sprite;
}

//public methods
void Wallpaper::drawWallpaper(sf::RenderTarget& target)
{
	target.draw(*this->wallpaper_sprite);
}


