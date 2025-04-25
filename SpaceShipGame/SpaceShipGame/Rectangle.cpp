#include "Rectangle.h"

void Rectangle::initVariables(const float& size_x, const float& size_y, const sf::Vector2i& position)
{
	this->rect.setSize({ size_x,size_y });
	this->rect.setPosition({ size_x* position.y, size_y*position.x });
	this->rect.setFillColor(sf::Color::Green);
	this->rect.setOutlineThickness(1);
	this->rect.setOutlineColor(sf::Color::Black);
}

Rectangle::Rectangle(const float& size_x, const float& size_y, const sf::Vector2i& position)
{
	this->initVariables(size_x, size_y,position);
}

void Rectangle::isWatched(const sf::RenderWindow& target)
{
	sf::Vector2f mouse_coords = target.mapPixelToCoords(sf::Mouse::getPosition(target));

	if (this->rect.getGlobalBounds().contains(mouse_coords))
	{
		this->rect.setFillColor(sf::Color::Yellow);
	}
	else
	{
		this->rect.setFillColor(sf::Color::Green);
	}
}

void Rectangle::drawRectangle(sf::RenderTarget& target)
{
	target.draw(this->rect);
}