#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Units.h"

class PlayerGraphics
{
	//private variables
	std::unique_ptr<sf::Texture> player_texture;
	std::unique_ptr<sf::Sprite> player_sprite;

	//private methods
	void initPlayerTexture();
	void initPlayerSprite(const sf::Vector2f& hitbox_position, const sf::Vector2f& unit_size);
	void initPlayerGraphics(const sf::Vector2f& hitbox_position, const sf::Vector2f& unit_size);
public:
	//constructor&destructor
	PlayerGraphics(const sf::Vector2f& hitbox_position, const sf::Vector2f& unit_size);
	~PlayerGraphics();

	void updatePlayerGraphics(const sf::Vector2f& hitbox_position);

	inline sf::Sprite& getSprite() const
	{
		return *this->player_sprite;
	}

};
