#include "MazeGraphics.h"
#include <iostream>


void MazeGraphics::initTextures(const MazeLogic::chars_legend& key)
{
	std::string file_path = "textures/" + MazeLogic::makeString(key) + ".png";
	std::cout << "\nLoading texture: " << file_path << "\n";

	this->maze_texture[key] = std::make_unique<sf::Texture>();
	
	if (!this->maze_texture[key]->loadFromFile(file_path))
	{
		std::cerr << "Error::MazeGraphics::initTextures: Couldn't load the " + MazeLogic::makeString(key) + " texture!" << std::endl;
	}
}


void MazeGraphics::initSprites(const std::vector< std::vector<MazeLogic::chars_legend>>& maze, const unsigned int& window_par_x, const unsigned int& window_par_y)
{
	this->maze_sprites.resize(maze.size());
	for (size_t i = 0; i < maze.size(); i++)
		this->maze_sprites[i].resize(maze[0].size());

	for (size_t i = 0; i < maze.size(); i++)
	{
		for (size_t j = 0; j < maze[0].size(); j++)
		{
			MazeLogic::chars_legend key = maze[i][j];
			this->maze_sprites[i][j] = { key,std::make_unique<sf::Sprite>(*this->maze_texture[key]) };

			this->maze_sprites[i][j].second->setScale({
														static_cast<float>(window_par_x) / this->maze_texture[key]->getSize().x,
														static_cast<float>(window_par_y) / this->maze_texture[key]->getSize().y,
													 });

			this->maze_sprites[i][j].second->setPosition({
											  this->maze_sprites[i][j].second->getGlobalBounds().size.x * j,
											  this->maze_sprites[i][j].second->getGlobalBounds().size.y * i
														});
			}
	}
	
}


MazeGraphics::MazeGraphics(const std::vector< std::vector<MazeLogic::chars_legend>>& maze, const unsigned int& window_par_x, const unsigned int& window_par_y)
{
	this->initTextures(MazeLogic::chars_legend::edge);
	this->initTextures(MazeLogic::chars_legend::obstacle);
	this->initTextures(MazeLogic::chars_legend::path);
	this->initTextures(MazeLogic::chars_legend::meta);
	this->initTextures(MazeLogic::chars_legend::key);
	this->initTextures(MazeLogic::chars_legend::teleport);
	this->initTextures(MazeLogic::chars_legend::player);
	this->initTextures(MazeLogic::chars_legend::enemy);

	this->initSprites(maze, window_par_x, window_par_y);
}

MazeGraphics::~MazeGraphics()
{
	
}

void MazeGraphics::drawSprites(sf::RenderTarget& target)
{
	for (size_t i = 0; i < maze_sprites.size(); i++)
	{
		for (size_t j = 0; j < maze_sprites[0].size(); j++)
		{
			target.draw(*this->maze_sprites[i][j].second);
		}
	}
	 
}

bool MazeGraphics::checkCollision(const sf::Rect<float>&object) const
{
	for (const auto& tiles : maze_sprites)
	{
		for (const auto& tile : tiles)
		{
			if (tile.first != MazeLogic::chars_legend::obstacle && tile.first != MazeLogic::chars_legend::edge) continue;

			if (tile.second.get()->getGlobalBounds().findIntersection(object)) return true;
		}
	}

	return false;
}

sf::Vector2f MazeGraphics::getPlayerSpawnerPosition() const
{
	for (const auto& tiles : maze_sprites)
		for (const auto& tile : tiles)
			if (tile.first == MazeLogic::chars_legend::player)
				return tile.second.get()->getPosition();
}
