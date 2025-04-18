#include "Engine.h"
#include <iostream>

//private methods
void Engine::initVariables()
{
	//window 
	this->window_size = sf::VideoMode({ 1280,720 });
	this->game_window = new sf::RenderWindow(window_size, "SpaceShipGame", sf::Style::Default, sf::State::Windowed);
	this->game_window->setFramerateLimit(60);
	
	//music
	this->background_music = new sf::Music("Sounds/space_theme.wav");
	this->background_music->setLoopPoints({ sf::milliseconds(0),sf::seconds(10) });
	this->background_music->setVolume(50);
}

void Engine::initBackground(const sf::RenderTarget& target)
{
	this->background = new Wallpaper(target);
}

void Engine::initPlayer(const sf::RenderTarget& target)
{
	this->player = new Player(target);
}

void Engine::initObstacle(const sf::RenderTarget& target)
{
	this->obstacles.emplace_back(std::make_unique<Obstacle>(target.getSize().x));
	
	//if the obstacle is spawned on another, it is removed instead
	for (int i = obstacles.size() - 2; i >= 0; i--)
	{
		if (this->obstacles.back()->getObstacleGlobalBounds().findIntersection(this->obstacles[i]->getObstacleGlobalBounds()) != std::nullopt)
		{
			this->obstacles.pop_back();
			break;
		}
	}

}

void Engine::checkEvents()
{
	while (const std::optional event = this->game_window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			this->game_window->close();

		}
	}
}

void Engine::drawObstacles(const std::vector<std::unique_ptr<Obstacle>>& obstacles)
{
	for (const std::unique_ptr<Obstacle>& element : this->obstacles)
		element->drawObstacle(*this->game_window);
}

//constructor & destructor
Engine::Engine()
{
	this->initVariables();
	this->initBackground(*this->game_window);
	this->initPlayer(*this->game_window);
	this->background_music->play();
}

Engine::~Engine()
{
	delete this->game_window;
	delete this->background;
	delete this->player;
	delete this->background_music;
}

//public methods
bool Engine::checkRunningCondition()
{
	return this->game_window->isOpen();
}

void Engine::updateGame()
{
	if (!this->player->isPlayerAlive()) return;

	this->checkEvents();
	if (Obstacle::checkObstaclesLimit())
	{
		if(rand_int(0,1) == 1)
		this->initObstacle(*this->game_window);
	}

	this->player->moveSpaceShip(*this->game_window);
	this->player->updateBullets(*this->game_window);
	
	for (int i = obstacles.size()-1;i>=0;i--)
	{
		obstacles[i]->moveObstacle(*this->game_window);

		if (this->player->checkShot(obstacles[i]->getObstacleGlobalBounds(), obstacles[i]->getID()))
		{
			obstacles[i]->takeDamageByObstacle();
			if (obstacles[i]->isObstacleDestroyed())
			{
				this->player->getPoint();
				this->obstacles[i]->playObstacleCrushSound();
				goto removeObstacle;
			}
		}

		if (this->player->checkCollision(obstacles[i]->getObstacleGlobalBounds()))
		{
			switch (obstacles[i]->getID())
			{
				case 0: this->player->getHealth(); break;
				case 1:
				deafault: this->player->takeDamage();
			}
			
			goto removeObstacle;
		}
			
		if(!obstacles[i]->checkObstaclePosition(*this->game_window))
			removeObstacle: obstacles.erase(obstacles.begin() + i);
	}

	this->player->updateGameCurrentStats();
}

void Engine::renderGame()
{
	this->updateGame();

	//clear
	this->game_window->clear();

	//draw
	this->background->drawWallpaper(*this->game_window);
	this->drawObstacles(this->obstacles);
		if (this->player->isPlayerAlive()) this->player->drawSpaceShip(*this->game_window);
	this->player->drawBullets(*this->game_window);

	if (this->player->isPlayerAlive())
		this->player->drawGameCurrentStats(*this->game_window);
	else
	{
		this->player->destroySpaceshipSprite();
		this->player->drawEndGamePhrase(*this->game_window);
	}
		

	//render
	this->game_window->display();
}

int rand_int(int low, int high)
{
	static std::default_random_engine re{ std::random_device{}() };

	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}