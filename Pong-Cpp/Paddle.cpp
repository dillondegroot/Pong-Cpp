#include "Paddle.h"

sf::RectangleShape paddle;

Paddle::Paddle(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	paddle.setSize(size);
	paddle.setPosition(position);
	paddle.setFillColor(color);
}

sf::Vector2f Paddle::getPosition()
{
	return paddle.getPosition();
}

void Paddle::setPosition(sf::Vector2f position)
{
	paddle.setPosition(position);
}

void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(paddle);
}
