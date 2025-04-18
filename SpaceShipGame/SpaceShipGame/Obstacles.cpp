#include "Obstacles.h"
#include "Engine.h"
#include <iostream>

int Obstacle::obstacles_current_number = 0, Obstacle::obstacles_max_number = 8;
std::vector<sf::Texture> Obstacle::obstacles_textures(2);

sf::SoundBuffer Obstacle::obstacle_sound_buffer;
sf::Sound* Obstacle::obstacle_sound = nullptr;

//private methods
void Obstacle::initObstaclesTextures(std::vector<sf::Texture>& container)
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

void Obstacle::initVariables(const int& window_size_x)
{
	if (this->obstacles_textures[0].getSize().x == 0)
		this->initObstaclesTextures(obstacles_textures);

	switch (rand_int(1, 20))
	{
		//satellite
		case 1:
		{
			//private variables
			this->rotation_degree = 0.f;
			this->obstacle_id = 0;
			this->obstacle_hp = 1;
			this->obstacle_speed = obstacle_hp + rand_int(0, 4);

			//satellite sprite
			this->obstacle_sprite = new sf::Sprite(this->obstacles_textures[0]);
			break;
		}

		//meteor
		default: 
		{
			//private variables
			this->obstacle_id = 1;
			this->obstacle_hp = rand_int(3, 8);
			this->rotation_degree = 30.f / obstacle_hp * rand_int(-1,1);
			this->obstacle_speed = 0.5f + 10.f / this->obstacle_hp;

			//meteor sprite
			this->obstacle_sprite = new sf::Sprite(this->obstacles_textures[1]);
		}
	}

	this->obstacle_sprite->setOrigin({ static_cast<float>(this->obstacles_textures[1].getSize().x) / 2.f, static_cast<float>(this->obstacles_textures[1].getSize().y) / 2.f });
	this->obstacle_sprite->setPosition({ static_cast<float>(rand_int(0, window_size_x)) , 0.f });
	this->obstacle_sprite->setScale({ 0.12f * (obstacle_hp / 2.f) , 0.12f * (obstacle_hp / 2.f) });
	
	//obstacle's sound
	if (obstacle_sound_buffer.getDuration().asSeconds() == 0)
	{
		if (!obstacle_sound_buffer.loadFromFile("Sounds/meteor_destroyed.mp3"))
		{
			std::cerr << "\nERROR::OBSTACLES::INITVARIABLES::COuldn't load the obstacle sound!\n";
		}
	}

	if (obstacle_sound == nullptr)
	{
		obstacle_sound = new sf::Sound(obstacle_sound_buffer);
	}
}

//constructor & destructor
Obstacle::Obstacle(const int& window_size_x)
{
	this->initVariables(window_size_x);
	obstacles_current_number++;
}

Obstacle::~Obstacle()
{
	delete this->obstacle_sprite;
	obstacles_current_number--;
}

bool Obstacle::checkObstaclesLimit()
{
	return obstacles_current_number < obstacles_max_number;
}

int Obstacle::getID() const
{
	return this->obstacle_id;
}

sf::FloatRect Obstacle::getObstacleGlobalBounds() const
{
	sf::FloatRect obstacle_bounds = this->obstacle_sprite->getGlobalBounds();
	obstacle_bounds.size.x *= 0.75;
	obstacle_bounds.size.y *= 0.75;
	return obstacle_bounds;
}

void Obstacle::moveObstacle(const sf::RenderTarget& target)
{
		this->obstacle_sprite->move({ 0.f, this->obstacle_speed });
		this->obstacle_sprite->rotate(sf::degrees(this->rotation_degree));
}

void Obstacle::drawObstacle(sf::RenderTarget& target)
{
	target.draw(*this->obstacle_sprite);
}

void Obstacle::takeDamageByObstacle()
{
	this->obstacle_hp--;
}

void Obstacle::playObstacleCrushSound()
{
	this->obstacle_sound->play();
}

bool Obstacle::checkObstaclePosition(const sf::RenderTarget& target)
{
	return (this->obstacle_sprite->getPosition().y - this->obstacle_sprite->getGlobalBounds().size.y / 2.f < target.getSize().y);
}

bool Obstacle::isObstacleDestroyed() const
{
	return this->obstacle_hp <= 0;
}
