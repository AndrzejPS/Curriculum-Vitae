#include "Obstacles.h"
#include "Engine.h"
#include <iostream>

std::vector<sf::Texture> Obstacles::obstacles_textures(2);

//private methods
void Obstacles::initObstaclesTextures(std::vector<sf::Texture>& container)
{
	//satellite texture
	if (!container.at(0).loadFromFile("Graphics/satellite.png"))
	{
		std::cerr << "/nERROR::OBSTACLES::INITVARIABLES::Couldn't load the satellite texture!/n";
	}

	//meteor texture
	if (!container.at(1).loadFromFile("Graphics/meteor.png"))
	{
		std::cerr << "/nERROR::OBSTACLES::INITVARIABLES::Couldn't load the meteor texture!/n";
	}
}

void Obstacles::initVariables()
{
	if (this->obstacles_textures.empty()) this->initObstaclesTextures(obstacles_textures);
	

	switch (rand_int(1, 10))
	{
		//satellite
		case 1:
		{
			//private variables
			this->rotation_degree = 0.f;
			this->obstacle_id = 0;
			this->obstacle_speed = static_cast<float>(rand_int(1, 5));

			//satellite sprite
			this->obstacle_sprite = new sf::Sprite(this->obstacles_textures[0]);
			break;
		}

		//meteor
		default: 
		{
			//private variables
			this->obstacle_id = 1;
			this->obstacle_hp = static_cast<float>(rand_int(3, 10));
			this->rotation_degree = 180.f / obstacle_hp;
			this->obstacle_speed = 1.f + 10.f / this->obstacle_hp;

			//meteor sprite
			this->obstacle_sprite = new sf::Sprite(this->obstacles_textures[1]);
			this->obstacle_sprite->setScale({ obstacle_hp / 2.f , obstacle_hp / 2.f });
		}
	}
}

//constructor & destructor
Obstacles::Obstacles()
{
	this->initVariables();
}

Obstacles::~Obstacles()
{
	delete this->obstacle_sprite;
}