#include "Player.h"
#include <iostream>


//private methods
void Player::initVariables()
{
	//player's stats
	this->health = 3;
	this->spaceship_speed = 5.f;
}

//player's appearance
void Player::initPlayersAppearance(const sf::RenderTarget& target)
{
	//spaceship texture
	if (!this->spaceship_texture.loadFromFile("Graphics/spaceship.png"))
	{
		std::cerr << "\nERROR::PLAYER::INIT_PLAYER_APPEARANCE::Couldn't load the spaceship texture!\n";
	}

	//spaceship sprite
	this->spaceship_sprite = new sf::Sprite(this->spaceship_texture);
	this->spaceship_sprite->setOrigin({ this->spaceship_texture.getSize().x / 2.f,this->spaceship_texture.getSize().y / 2.f });
	this->spaceship_sprite->setScale({ 0.15f,0.15f });

	this->spaceship_sprite_half_x = this->spaceship_sprite->getGlobalBounds().size.x / 2.f;
	this->spaceship_sprite_half_y = this->spaceship_sprite->getGlobalBounds().size.y / 2.f;

	this->spaceship_sprite->setPosition({ target.getSize().x / 2.f, target.getSize().y - this->spaceship_sprite_half_y });
}

//constructor & destructor
Player::Player(const sf::RenderTarget& target)
{
	this->initVariables();
	this->initPlayersAppearance(target);
}

Player::~Player()
{
	delete this->spaceship_sprite;
}

//public methods
void Player::drawSpaceShip(sf::RenderTarget& target)
{
	target.draw(*this->spaceship_sprite);
}

void Player::drawBullets(sf::RenderTarget& target)
{
	for (const std::unique_ptr<Missile>& bullet : this->bullets) bullet->drawMissile(target);
}

void Player::moveSpaceShip(const sf::RenderTarget& target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (this->spaceship_sprite->getPosition().y - this->spaceship_sprite_half_y - spaceship_speed >= 0.f)
			this->spaceship_sprite->move({ 0.f,-spaceship_speed });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (this->spaceship_sprite->getPosition().y + this->spaceship_sprite_half_y + spaceship_speed <= target.getSize().y)
			this->spaceship_sprite->move({ 0.f,spaceship_speed });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (this->spaceship_sprite->getPosition().x - this->spaceship_sprite_half_y - spaceship_speed >= 0.f)
			this->spaceship_sprite->move({ -spaceship_speed,0.f });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (this->spaceship_sprite->getPosition().x + this->spaceship_sprite_half_y + spaceship_speed <= target.getSize().x)
			this->spaceship_sprite->move({ spaceship_speed,0.f });
	}

	static int fire_delay = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		if (fire_delay == 0)
		{
			this->bullets.emplace_back(std::make_unique<Missile>(this->spaceship_sprite->getPosition().x, this->spaceship_sprite->getPosition().y));
			this->bullets.emplace_back(std::make_unique<Missile>(this->spaceship_sprite->getPosition().x, this->spaceship_sprite->getPosition().y, -45.0));
			this->bullets.emplace_back(std::make_unique<Missile>(this->spaceship_sprite->getPosition().x, this->spaceship_sprite->getPosition().y,45.0));
			fire_delay = 20;
		}
		else fire_delay--;
	}
	else if(fire_delay != 0) fire_delay--;
	
}

void Player::updateBullets(const sf::RenderTarget& target)
{
	for (int i = bullets.size() - 1; i >= 0; i--)
	{
		if (bullets[i]->getMissilePosition().second + bullets[i]->getMissileSize().second < 0.f) bullets.erase(bullets.begin() + i);
		else bullets[i]->moveMissle(bullets[i]->getRotationDegree());
	}
}
