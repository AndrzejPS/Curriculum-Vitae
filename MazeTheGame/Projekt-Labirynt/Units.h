#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "MazeGraphics.h"

class Unit
{

	//protected variables
protected:
	enum class move_directions { left = 'L', right = 'R', up = 'U', down = 'D' };

	int current_hp, max_hp;
	float speed;

	sf::RectangleShape unit_hitbox;
	sf::Vector2f unit_size;
	sf::Vector2f unit_position;

	//protected methods
	void takeDamage(const int& damage_num);
	void heal(const int& heal_num);
	void moveUnit(const move_directions& direction, const MazeGraphics& maze_graphics);
	bool isMoveCorrect(const sf::Vector2u& window_size, const sf::Vector2f& move_distance) const;
	bool isDead();

public:
	Unit();
	~Unit();

	virtual void attack() = 0;

};

class Player : public Unit
{
	struct weapon
	{
		bool knife;
		bool gun;
		bool dynamite;
	};

	//private methods
	void initPlayer();
	void movePlayer(const MazeGraphics& maze_graphics);
public:
	//constructor&destructor
	Player(const sf::Vector2u& tile_size, const std::pair<int, int>& player_spawner_coords, const sf::Vector2f& unit_size);
	~Player();

	//public methods

	void attack() override;


	void updataPlayer(const MazeGraphics& maze_graphics);
	void drawPlayer(sf::RenderTarget& target);

	inline sf::Vector2f getPlayerPosition() const
	{
		return this->unit_position;
	}

	inline sf::Vector2f getPlayerSize()const
	{
		return this->unit_size;
	}

};