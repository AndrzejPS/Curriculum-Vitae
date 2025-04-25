#pragma once
#include <SFML/Graphics.hpp>

#include "MazeLogic.h"

using TexturesContainer = std::unordered_map<MazeLogic::chars_legend, std::unique_ptr<sf::Texture>>;
using SpritesContainer = std::vector<std::vector<std::pair<MazeLogic::chars_legend, std::unique_ptr<sf::Sprite>>>>;

class MazeGraphics
{
	//private variables
	TexturesContainer maze_texture;
	SpritesContainer maze_sprites;

	sf::Vector2f player_spawner_position;

	//private methods
	void initTextures(const MazeLogic::chars_legend& key);
	void initSprites(const std::vector< std::vector<MazeLogic::chars_legend>>& maze, const unsigned int& window_par_x, const unsigned int& window_par_y);

public:
	//constructor&destructor
	MazeGraphics(const std::vector< std::vector<MazeLogic::chars_legend>>& maze, const unsigned int& window_par_x, const unsigned int& window_par_y);
	~MazeGraphics();

	//public methods
	void drawSprites(sf::RenderTarget& target);

	bool checkCollision(const sf::Rect<float>& object) const;
	sf::Vector2f getPlayerSpawnerPosition()const ;
};

