#include "Missile.h"
#include <iostream>


void Missile::initVariables(const float& degrees)
{
	this->missile_speed = 6.f;
	this->rotation_degree = degrees;
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
	this->missile_sprite->setOrigin({ this->missile_texture.getSize().x / 2.f, static_cast<float>(this->missile_texture.getSize().y)});
	this->missile_sprite->setScale({ 0.3f,0.3f });
	this->missile_sprite->setPosition({ spaceship_origin_x , spaceship_origin_y });
	this->missile_sprite->rotate(sf::degrees(this->rotation_degree));
}

//constructor & destructor
Missile::Missile(const float& spaceship_origin_x, const float& spaceship_origin_y,const float& degrees)
{
	this->initVariables(degrees);
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

const float& Missile::getRotationDegree()
{
	return this->rotation_degree;
}

void Missile::moveMissle(const float& degrees)
{
	switch (static_cast<int>(degrees))
	{
	case 45: this->missile_sprite->move({ this->missile_speed,-this->missile_speed }); break;
	case -45: this->missile_sprite->move({ -this->missile_speed,-this->missile_speed }); break;
	case 0:
	default: this->missile_sprite->move({ 0.f,-this->missile_speed });
	}
}

void Missile::drawMissile(sf::RenderTarget& target)
{
	if (this->missile_sprite)
	{
		target.draw(*this->missile_sprite);
	}
}