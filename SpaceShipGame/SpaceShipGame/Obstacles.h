#pragma once

class Obstacles
{
	//private variables
	float obstacle_speed, rotation_degree;
	int obstacle_hp = 0, obstacle_id;


	//obstacles' appearance
	static std::vector<sf::Texture> obstacles_textures;
	sf::Sprite* obstacle_sprite;

	//private methods
	void initObstaclesTextures(std::vector<sf::Texture>& container);
	void initVariables();
	
public:
	//constructor & destructor
	Obstacles();
	~Obstacles();
};

