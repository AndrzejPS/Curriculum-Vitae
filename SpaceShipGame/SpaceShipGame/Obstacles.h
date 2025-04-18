#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Obstacle
{
	//private variables
	float obstacle_speed, rotation_degree, starting_spot;
	int obstacle_hp, obstacle_id;
	static int obstacles_current_number, obstacles_max_number;

	//obstacles' appearance
	static std::vector<sf::Texture> obstacles_textures;
	sf::Sprite* obstacle_sprite;

	//obstacle's sound
	static sf::SoundBuffer obstacle_sound_buffer;
	static sf::Sound* obstacle_sound;

	//private methods
	void initObstaclesTextures(std::vector<sf::Texture>& container);
	void initVariables(const int& window_size_x);
	
public:
	//constructor & destructor
	Obstacle(const int& window_size_x);
	~Obstacle();

	//public methods
	static bool checkObstaclesLimit();
	int getID()const;
	sf::FloatRect getObstacleGlobalBounds() const;
	void moveObstacle(const sf::RenderTarget& target);
	void drawObstacle(sf::RenderTarget& target);
	void takeDamageByObstacle();
	void playObstacleCrushSound();
	bool checkObstaclePosition(const sf::RenderTarget& target);
	bool isObstacleDestroyed() const;

};

