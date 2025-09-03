#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
	public:
		sf::RectangleShape paddle;

		Paddle(sf::Vector2f size, sf::Vector2f position, sf::Color color);

		sf::Vector2f getPosition();

		void setPosition(sf::Vector2f position);

		void draw(sf::RenderWindow& window);
};

