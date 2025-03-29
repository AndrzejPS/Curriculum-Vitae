#pragma once
#include <SFML/Graphics.hpp>
#include "Missile.h"

class Player
{
	//private variables
	std::vector<std::unique_ptr<Missile>> bullets;

	//Player's stats
	int player_hp, score;
	float spaceship_speed;

	//Player's appearance
	sf::Texture spaceship_texture;
	sf::Sprite* spaceship_sprite;
	float spaceship_sprite_half_x, spaceship_sprite_half_y;

	//private methods
	void initVariables();
	void initPlayersAppearance(const sf::RenderTarget& target);

public:
	//constructor & destructor
	Player(const sf::RenderTarget& target);
	~Player();

	//public methods
	void drawSpaceShip(sf::RenderTarget& target);
	void drawBullets(sf::RenderTarget& target);
	void moveSpaceShip(const sf::RenderTarget& target);
	void updateBullets(const sf::RenderTarget& target);
	void getHealth();
	void takeDamage();
	void getPoint();
	bool checkCollision(const sf::FloatRect& object);
	bool checkShot(const sf::FloatRect& object, const int& object_id);
};