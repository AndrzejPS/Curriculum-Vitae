#pragma once
#include <SFML/Graphics.hpp>
#include "Missile.h"

class Player
{
	//private variables
	std::vector<std::unique_ptr<Missile>> bullets;

	//Player's stats
	int player_hp, score, weapon_lvl;
	float spaceship_speed;

	//Player's appearance
	sf::Texture spaceship_texture;
	sf::Sprite* spaceship_sprite;
	float spaceship_sprite_half_x, spaceship_sprite_half_y;

	//Player's sounds
	std::vector<sf::SoundBuffer> spaceship_sound_buffers;
	std::vector<std::unique_ptr<sf::Sound>> spaceship_sounds;


	//Text and Fonts
	sf::Font main_font;
	sf::Text* game_current_stats;

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
	void drawGameCurrentStats(sf::RenderTarget& target);
	void drawEndGamePhrase(sf::RenderTarget& target);
	void moveSpaceShip(const sf::RenderTarget& target);
	void updateBullets(const sf::RenderTarget& target);
	void updateGameCurrentStats();
	void getHealth();
	void takeDamage();
	void destroySpaceshipSprite();
	void getPoint();
	bool checkCollision(const sf::FloatRect& object);
	bool checkShot(const sf::FloatRect& object, const int& object_id);
	bool isPlayerAlive();
	sf::FloatRect getSpaceShipGlobalBounds();
};