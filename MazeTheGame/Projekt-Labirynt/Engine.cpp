#include "Engine.h"

//private methods
void Engine::initWindow()
{
	this->video_mode = std::make_unique<sf::VideoMode>(sf::Vector2u( this->game_window_x, this->game_window_y ));
	this->game_window = std::make_unique < sf::RenderWindow>(*this->video_mode, "CPP Adventure", sf::Style::Titlebar | sf::Style::Close, sf::State::Fullscreen);
	this->game_window->setFramerateLimit(60);
}

void Engine::initMaze(const unsigned int& maze_height, const unsigned int& maze_width)
{
	this->maze_map = std::make_unique<MazeLogic>(maze_height, maze_width);
}

void Engine::initMazeGraphics()
{
	this->maze_graphics = std::make_unique<MazeGraphics>(this->maze_map->getMaze(), this->tile_size.x, this->tile_size.y);
}

void Engine::updateGame()
{
	while (const std::optional event = this->game_window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			this->game_window->close();
	}

	this->player->updataPlayer(*this->maze_graphics);
	this->player_graphics->updatePlayerGraphics(this->player->getPlayerPosition());
}

void Engine::drawMaze()
{
	this->maze_graphics->drawSprites(*this->game_window);
}

void Engine::drawGame()
{
	this->drawMaze();
	this->player->drawPlayer(*this->game_window);
	this->game_window->draw(this->player_graphics->getSprite());
}

void Engine::renderGame()
{
	this->updateGame();

	this->game_window->clear(sf::Color::Green);

	this->drawGame();
	this->game_window->display();
}

//constructor&destructor
Engine::Engine(const unsigned int& maze_height, const unsigned int& maze_width) : maze_height(maze_height), maze_width(maze_width)
{
	this->initMaze(this->maze_height, this->maze_width);
	this->initWindow();

	this->tile_size.x = game_window_x / maze_height;
	this->tile_size.y = game_window_y / maze_width;

	this->initMazeGraphics();

	this->player = std::make_unique<Player>(
											 sf::Vector2u(this->tile_size.x, this->tile_size.y ),
											 this->maze_map->getPlayerSpawnerCoords(),
											 sf::Vector2f( this->tile_size.x / 2, this->tile_size.y / 2)
										   );

	this->player_graphics = std::make_unique<PlayerGraphics>(this->player->getPlayerPosition(), this->player->getPlayerSize());
}

Engine::~Engine()
{

}

bool Engine::isRunning() const
{
	return this->game_window->isOpen();
}
