#pragma once 
#include <SFML/Graphics.hpp>
#include <random>
#include "Wallpaper.h"
#include "Player.h"

class Engine
{
	//private variables

	//window
	sf::VideoMode window_size;
	sf::RenderWindow* game_window;

	//wallpaper
	Wallpaper* background;

	//Player
	Player* player;

	//private functions
	void initVariables();
	void initBackground(const sf::RenderTarget& target);
	void initPlayer(const sf::RenderTarget& target);
	void checkEvents();

public:
	//constructor & destructor
	Engine();
	~Engine();

	//public functions
	bool checkRunningCondition();
	void updateGame();
	void renderGame();

};

int rand_int(int low, int high);