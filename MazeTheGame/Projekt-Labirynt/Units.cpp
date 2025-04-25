#include "Units.h"


//Unit class

void Unit::takeDamage(const int& damage_num)
{
	this->current_hp-= damage_num;
}

void Unit::heal(const int& heal_num)
{
	if (this->current_hp + heal_num < this->max_hp) this->current_hp += heal_num;
	else this->current_hp = this->max_hp;
}

void Unit::moveUnit(const move_directions& direction, const MazeGraphics& maze_graphics)
{
	sf::Vector2f displacement = { 0,0 };

	switch (direction)
	{
	case move_directions::left:  displacement = { -this->speed, 0.f }; break;
	case move_directions::right:  displacement = { this->speed, 0.f }; break;
	case move_directions::up:  displacement = { 0.f, -this->speed };   break;
	case move_directions::down:  displacement = { 0.f,this->speed };   break;
	}

	sf::Rect<float> moved_player = this->unit_hitbox.getGlobalBounds();

	moved_player.position.x += displacement.x;
	moved_player.position.y += displacement.y;

	if (!maze_graphics.checkCollision(moved_player))
	{
		this->unit_hitbox.move(displacement);
		this->unit_position = this->unit_hitbox.getPosition();
	}
}

bool Unit::isMoveCorrect(const sf::Vector2u& window_size, const sf::Vector2f& move_distance) const
{
	sf::Vector2f new_position = this->unit_position + move_distance;

	return new_position.x >= 0.f && new_position.y >= 0.f &&
		   new_position.x + this->unit_size.x <= static_cast<float>(window_size.x) &&
		   new_position.y + this->unit_size.y <= static_cast<float>(window_size.y);
}

bool Unit::isDead()
{
	return this->current_hp<=0;
}

//constructor&destructor
Unit::Unit()
{
}

Unit::~Unit()
{
}

//Player class

void Player::initPlayer()
{
	this->max_hp = 3;
	this->current_hp = this->max_hp;
	this->speed = 10.f;

	this->unit_hitbox.setFillColor(sf::Color::Transparent);
	this->unit_hitbox.setSize({ this->unit_size.x, this->unit_size.y });
	this->unit_hitbox.setPosition({ this->unit_position.x,this->unit_position.y });
}

Player::Player(const sf::Vector2u& tile_size, const std::pair<int,int>& player_spawner_coords, const sf::Vector2f& unit_size)
{
	this->unit_size = unit_size;
	this->unit_position = { static_cast<float>(tile_size.x) * player_spawner_coords.second,
							static_cast<float>(tile_size.y)* player_spawner_coords.first};
	this->initPlayer();
}

//constructor
Player::~Player()
{

}

void Player::attack()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C));//make rectangle that deals melee damage
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X));//make rectangle that deals range damage
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z));//make rectangle that kills enemies and obstacles
}

void Player::movePlayer(const MazeGraphics& maze_graphics)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) this->moveUnit(move_directions::left, maze_graphics);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) this->moveUnit(move_directions::right, maze_graphics);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) this->moveUnit(move_directions::up, maze_graphics);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) this->moveUnit(move_directions::down, maze_graphics);
}

void Player::updataPlayer(const MazeGraphics& maze_graphics)
{
	this->movePlayer(maze_graphics);
	this->attack();
}

void Player::drawPlayer(sf::RenderTarget& target)
{
	target.draw(this->unit_hitbox);
}

