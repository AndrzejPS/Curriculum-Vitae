#include "Engine.h"

void Engine::initGameWindow()
{
	this->video_mode_ptr = new sf::VideoMode({ 1000,1000 });
	this->game_window = new sf::RenderWindow(*this->video_mode_ptr, "Rectangles", sf::Style::Close | sf::Style::Titlebar, sf::State::Windowed);
}

void Engine::initVariables(const float& rect_size_x, const float& rect_size_y)
{
	this->rect_size_x = rect_size_x;
	this->rect_size_y = rect_size_y;
}

Engine::~Engine()
{
	delete this->game_window;
	delete this->video_mode_ptr;
}

bool Engine::isGameRunning()
{
	return this->game_window->isOpen();
}

void Engine::makeMap()
{
	for (int i = 0; i < this->columns_num; i++)
	{
		for (int j = 0; j < this->rows_num; j++)
		{
			rects.emplace_back(std::make_unique<Rectangle>(rect_size_x, rect_size_y,sf::Vector2i({i,j})));
		}
	}
}

void Engine::updateGame()
{
	while (const std::optional event = this->game_window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			this->game_window->close();
	}

	for (size_t i = 0; i < rects.size(); i++)
	{
		this->rects.at(i)->isWatched(*this->game_window);
	}
}

void Engine::renderMap()
{
	for (int i = 0; i < this->rects.size(); i++)
	{
		this->rects.at(i)->drawRectangle(*this->game_window);
	}
}

void Engine::renderGame()
{
	this->updateGame();

	this->game_window->clear();

	this->renderMap();

	this->game_window->display();
}
