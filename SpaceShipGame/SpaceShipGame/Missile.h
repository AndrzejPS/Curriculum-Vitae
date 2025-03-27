#pragma once
#include <SFML/Graphics.hpp>

class Missile
{
	//private variables
	float missile_speed;

	//Player's appearance
	static sf::Texture missile_texture;
	sf::Sprite* missile_sprite;

	//private methods
	void initVariables();
	void initMissileAppearance(const float& spaceship_origin_x, const float& spaceship_origin_y);

public:
	//constructor & destructor
	Missile(const float& spaceship_origin_x, const float& spaceship_origin_y);
	~Missile();

	//public methods
	std::pair<float, float> getMissilePosition();
	std::pair<float, float> getMissileSize();
	void moveMissle();
	void drawMissile(sf::RenderTarget& target);
};