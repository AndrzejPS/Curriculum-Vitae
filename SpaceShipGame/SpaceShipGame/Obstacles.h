#pragma once
#include <SFML/Graphics.hpp>

class Obstacle
{
	//private variables
	float obstacle_speed, rotation_degree, starting_spot;
	int obstacle_hp = 0, obstacle_id;
	static int obstacles_current_number, obstacles_max_number;

	//obstacles' appearance
	static std::vector<sf::Texture> obstacles_textures;
	sf::Sprite* obstacle_sprite;

	//private methods
	void initObstaclesTextures(std::vector<sf::Texture>& container);
	void initVariables(const int& window_size_x);
	
public:
	//constructor & destructor
	Obstacle(const int& window_size_x);
	~Obstacle();

	//public methods
	static bool checkObstaclesLimit();
	void moveObstacle(const sf::RenderTarget& target);
	void drawObstacle(sf::RenderTarget& target);
};

