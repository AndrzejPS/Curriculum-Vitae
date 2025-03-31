#include "Player.h"
#include <iostream>

//private methods
void Player::initVariables()
{
	//player's stats
	this->player_hp = 3;
	this->spaceship_speed = 5.f;
	this->score = 0;
	this->weapon_lvl = 1;

	//font & text
	if (!this->main_font.openFromFile("Fonts/SPACE.ttf"))
	{
		std::cout << "ERROR::PLAYER::INITVARIABLES:Couldn't load the font!";
	}

	this->game_current_stats = new sf::Text(this->main_font);
	this->game_current_stats->setCharacterSize(25);
	this->game_current_stats->setFillColor(sf::Color::Green);
	this->game_current_stats->setOutlineThickness(2);
	this->game_current_stats->setPosition({ 20.f,10.f });
	this->game_current_stats->setString("NONE");

	//sounds
	spaceship_sound_buffers.emplace_back("Sounds/damage_spaceship.mp3"); // OK w SFML 3.0
	spaceship_sound_buffers.emplace_back("Sounds/explosion.mp3"); // OK w SFML 3.0

	this->spaceship_sounds.emplace_back(std::make_unique<sf::Sound>(this->spaceship_sound_buffers.at(0))); // [0]
	this->spaceship_sounds.emplace_back(std::make_unique<sf::Sound>(this->spaceship_sound_buffers.at(1))); // [1]
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
	delete this->game_current_stats;
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

void Player::drawGameCurrentStats(sf::RenderTarget& target)
{
	target.draw(*this->game_current_stats);
}

void Player::drawEndGamePhrase(sf::RenderTarget& target)
{
	//modify text patameters
	this->game_current_stats->setCharacterSize(50);
	this->game_current_stats->setFillColor(sf::Color::Red);
	this->game_current_stats->setOrigin({ this->game_current_stats->getGlobalBounds().size.x / 2.f, this->game_current_stats->getGlobalBounds().size.y / 2.f });
	this->game_current_stats->setPosition({ target.getSize().x / 2.f, target.getSize().y/2.f });

	//draw the final score
	this->game_current_stats->setString("You've lost!\nFinal score: " + std::to_string(this->score));
	target.draw(*this->game_current_stats);
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
			switch (this->weapon_lvl)
			{
			case 3: this->bullets.emplace_back(std::make_unique<Missile>(this->spaceship_sprite->getPosition().x, this->spaceship_sprite->getPosition().y, -45.0));
			case 2: this->bullets.emplace_back(std::make_unique<Missile>(this->spaceship_sprite->getPosition().x, this->spaceship_sprite->getPosition().y, 45.0));
			case 1: this->bullets.emplace_back(std::make_unique<Missile>(this->spaceship_sprite->getPosition().x, this->spaceship_sprite->getPosition().y));
			}
			
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

void Player::updateGameCurrentStats()
{
	this->game_current_stats->setString("Score: " + std::to_string(this->score) +
										"\nHealth: " + std::to_string(this->player_hp));
}

void Player::getHealth()
{
	this->player_hp++;
	
	if (this->weapon_lvl < 3) this->weapon_lvl++;
}

void Player::takeDamage()
{
	if (this->player_hp > 1) this->spaceship_sounds.at(0)->play();

	this->player_hp--;
	this->weapon_lvl = 1;
}

void Player::destroySpaceshipSprite()
{
	if (this->spaceship_sprite == nullptr) return;

	this->spaceship_sounds[1]->play();
	delete this->spaceship_sprite;
	this->spaceship_sprite = nullptr;
}

void Player::getPoint()
{
	this->score++;
}

bool Player::checkCollision(const sf::FloatRect& object)
{
	return this->getSpaceShipGlobalBounds().findIntersection(object) != std::nullopt ? true : false;
}

bool Player::checkShot(const sf::FloatRect& object, const int& object_id)
{
	if (object_id == 0) return false; //no collision with the satelllite

	for (int i = this->bullets.size()-1; i >= 0; i--)
	{
		if (this->bullets[i]->getMissileGlobalBounds().findIntersection(object) != std::nullopt)
		{
			bullets.erase(bullets.begin() + i);
			return true;
		}		
	}
	return false;
}

bool Player::isPlayerAlive()
{
	return this->player_hp > 0;
}

sf::FloatRect Player::getSpaceShipGlobalBounds()
{
	sf::FloatRect spaceship_bounds = this->spaceship_sprite->getGlobalBounds();
	spaceship_bounds.size.x *= 0.65f;
	return spaceship_bounds;
}
