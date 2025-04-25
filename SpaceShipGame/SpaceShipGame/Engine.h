#pragma once
#include "Rectangle.h"
#include <SFML/Graphics.hpp>

class Engine
{
	std::vector<std::unique_ptr<Rectangle>> rects;
	float rect_size_x, rect_size_y;
	int columns_num, rows_num;

	sf::VideoMode* video_mode_ptr;
	sf::RenderWindow* game_window;

	void initGameWindow();
	void initVariables(const float& rect_size_x, const float& rect_size_y);

public:
	Engine(const int& columns_num=10, const int& rows_num=10) : columns_num(columns_num),rows_num(rows_num)
	{
		this->initGameWindow();
		this->initVariables(this->game_window->getSize().x/this->columns_num, this->game_window->getSize().y/this->rows_num);
		this->makeMap();
	}

	~Engine();

	bool isGameRunning();
	void makeMap();
	
	void updateGame();

	void renderMap();
	void renderGame();
};

