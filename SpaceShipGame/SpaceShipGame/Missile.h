#pragma once
#include <SFML/Graphics.hpp>

class Missile
{
	//private variables
	float missile_speed, rotation_degree;

	//Missile's appearance
	static sf::Texture missile_texture;
	sf::Sprite* missile_sprite;

	//private methods
	void initVariables(const float& degrees);
	void initMissileAppearance(const float& spaceship_origin_x, const float& spaceship_origin_y);

public:
	//constructor & destructor
	Missile(const float& spaceship_origin_x, const float& spaceship_origin_y, const float& degrees = 0);
	~Missile();

	//public methods
	std::pair<float, float> getMissilePosition() const;
	std::pair<float, float> getMissileSize() const;
	float getRotationDegree() const;
	sf::FloatRect getMissileGlobalBounds() const;
	void moveMissle(const float& degrees);
	void drawMissile(sf::RenderTarget& target);
};