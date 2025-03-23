#pragma once 
#include <SFML/Graphics.hpp>
#include "Wallpaper.h"

class Engine
{
	//private variables

	//window
	sf::VideoMode window_size;
	sf::RenderWindow* game_window;

	//wallpaper
	Wallpaper* background;

	//private functions
	void initVariables();
	void initBackground(const sf::RenderTarget& target);
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