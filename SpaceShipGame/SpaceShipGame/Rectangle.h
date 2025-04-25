#pragma once
#include <SFML/Graphics.hpp>

class Rectangle
{
	sf::RectangleShape rect;

	void initVariables(const float& size_x, const float& size_y, const sf::Vector2i& position);

public:
	Rectangle(const float& size_x = 100, const float& size_y = 100, const sf::Vector2i& position = sf::Vector2i{0,0});
	~Rectangle() {};

	void isWatched(const sf::RenderWindow& target);
	void drawRectangle(sf::RenderTarget& target);
};

