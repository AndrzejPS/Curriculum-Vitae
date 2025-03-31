#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include "Wallpaper.h"
#include "Player.h"
#include "Obstacles.h"

class Engine
{
	//private variables

	//window
	sf::VideoMode window_size;
	sf::RenderWindow* game_window;

	//wallpaper
	Wallpaper* background;

	//music
	sf::Music* background_music;

	//Player
	Player* player;

	//Obstacles
	std::vector<std::unique_ptr<Obstacle>> obstacles;

	//private functions
	void initVariables();
	void initBackground(const sf::RenderTarget& target);
	void initPlayer(const sf::RenderTarget& target);
	void initObstacle(const sf::RenderTarget& target);
	void checkEvents();
	void drawObstacles(const std::vector<std::unique_ptr<Obstacle>>& obstacles);
	

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