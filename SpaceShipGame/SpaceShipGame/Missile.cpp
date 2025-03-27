#include "Missile.h"
#include <iostream>


void Missile::initVariables()
{
	this->missile_speed = 4.f;
}

sf::Texture Missile::missile_texture;

void Missile::initMissileAppearance(const float& spaceship_origin_x, const float& spaceship_origin_y)
{
	static bool textureLoaded = false;
	if (!textureLoaded)
	{
		if (!missile_texture.loadFromFile("Graphics/missile.png"))
		{
			std::cerr << "ERROR: Failed to load missile texture!\n";
		}
		textureLoaded = true;
	}

	this->missile_sprite = new sf::Sprite(this->missile_texture);
	this->missile_sprite->setOrigin({ this->missile_texture.getSize().x / 2.f, this->missile_texture.getSize().x / 2.f });
	this->missile_sprite->setScale({ 0.3f,0.3f });
	this->missile_sprite->setPosition({ spaceship_origin_x , spaceship_origin_y });
}

//constructor & destructor
Missile::Missile(const float& spaceship_origin_x, const float& spaceship_origin_y)
{
	this->initVariables();
	this->initMissileAppearance(spaceship_origin_x, spaceship_origin_y);
}

Missile::~Missile()
{
	delete this->missile_sprite;
}

std::pair<float, float> Missile::getMissilePosition()
{
	//pair(x, y);
	return std::pair<float, float>(this->missile_sprite->getGlobalBounds().position.x, this->missile_sprite->getGlobalBounds().position.y);
}

std::pair<float, float> Missile::getMissileSize()
{
	return std::pair<float, float>(this->missile_sprite->getGlobalBounds().size.x, this->missile_sprite->getGlobalBounds().size.y);
}

void Missile::moveMissle()
{
	this->missile_sprite->move({ 0.f,-this->missile_speed });
}

void Missile::drawMissile(sf::RenderTarget& target)
{
	if (this->missile_sprite)
	{
		target.draw(*this->missile_sprite);
	}
}