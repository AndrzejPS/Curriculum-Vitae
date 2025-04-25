#pragma once
#include "MazeLogic.h"
#include "MazeGraphics.h"
#include "PlayerGraphics.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include<memory.h>

class Engine
{
	//private variables & methods

	//game window
	unsigned int game_window_x = 1920;
	unsigned int game_window_y = 1080;
	std::unique_ptr<sf::VideoMode> video_mode;
	std::unique_ptr<sf::RenderWindow> game_window;

	void initWindow();

	//maze
	const unsigned int& maze_height;
	const unsigned int& maze_width;
	std::unique_ptr<MazeLogic> maze_map;
	void initMaze(const unsigned int& maze_height, const unsigned int& maze_width);

	//maze graphics
	sf::Vector2u tile_size;
	std::unique_ptr<MazeGraphics> maze_graphics;
	void initMazeGraphics();

	//player
	std::unique_ptr<Player> player;

	//player graphics
	std::unique_ptr<PlayerGraphics> player_graphics;

	//private methods
	void updateGame();
	void drawMaze();
	void drawGame();
	
public:
	//constructor&destructor
	Engine(const unsigned int& maze_height, const unsigned int& maze_width);
	~Engine();

	//public methods
	void renderGame();
	bool isRunning()const;
};

