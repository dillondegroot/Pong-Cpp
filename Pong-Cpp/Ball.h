#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
	public:
		sf::CircleShape ball;

		Ball(float size, sf::Vector2f position, sf::Color color);

		sf::Vector2f getPosition();

		void setPosition(sf::Vector2f position);

		void move(sf::Vector2f offset);

		void draw(sf::RenderWindow& window);
};