#include "PlayerGraphics.h"
#include <iostream>

void PlayerGraphics::initPlayerTexture()
{
	this->player_texture = std::make_unique<sf::Texture>();

	if (!this->player_texture->loadFromFile("textures/player_skin.png"))
	{
		std::cerr << "Error::PlayerGraphics::initPlayerTexture: Couldn't load the player texture!";
	}
}

void PlayerGraphics::initPlayerSprite(const sf::Vector2f& hitbox_position, const sf::Vector2f& unit_size)
{
	this->player_sprite = std::make_unique<sf::Sprite>(*this->player_texture);

	this->player_sprite->setPosition(hitbox_position);
	this->player_sprite->setScale({
									unit_size.x / this->player_texture->getSize().x,
									unit_size.y / this->player_texture->getSize().y
		                         });

}

//private methods
void PlayerGraphics::initPlayerGraphics(const sf::Vector2f& hitbox_position,const sf::Vector2f& unit_size)
{
	this->initPlayerTexture();
	this->initPlayerSprite(hitbox_position, unit_size);
}

//constructor&destructor
PlayerGraphics::PlayerGraphics(const sf::Vector2f& hitbox_position, const sf::Vector2f& unit_size)
{
	this->initPlayerGraphics(hitbox_position, unit_size);
}

PlayerGraphics::~PlayerGraphics()
{

}

void PlayerGraphics::updatePlayerGraphics(const sf::Vector2f& hitbox_position)
{
	this->player_sprite->setPosition(hitbox_position);
}
