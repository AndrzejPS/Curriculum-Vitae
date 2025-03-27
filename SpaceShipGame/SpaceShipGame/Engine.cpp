#include "Engine.h"
#include <iostream>

//private methods
void Engine::initVariables()
{
	//window 
	this->window_size = sf::VideoMode({ 1280,720 });
	this->game_window = new sf::RenderWindow(window_size, "SpaceShipGame", sf::Style::Default, sf::State::Windowed);
	this->game_window->setFramerateLimit(60);
	//
}

void Engine::initBackground(const sf::RenderTarget& target)
{
	this->background = new Wallpaper(target);
}

void Engine::initPlayer(const sf::RenderTarget& target)
{
	this->player = new Player(target);
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

//constructor & destructor
Engine::Engine()
{
	this->initVariables();
	this->initBackground(*this->game_window);
	this->initPlayer(*this->game_window);
}

Engine::~Engine()
{
	delete this->game_window;
	delete this->background;
	delete this->player;
}

//public methods
bool Engine::checkRunningCondition()
{
	return this->game_window->isOpen();
}

void Engine::updateGame()
{
	this->checkEvents();
	this->player->moveSpaceShip(*this->game_window);
	this->player->updateBullets(*this->game_window);
}

void Engine::renderGame()
{
	this->updateGame();

	//clear
	this->game_window->clear();

	//draw
	this->background->drawWallpaper(*this->game_window);
	this->player->drawSpaceShip(*this->game_window);
	this->player->drawBullets(*this->game_window);

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