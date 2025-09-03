#include "Ball.h"

sf::CircleShape ball;

Ball::Ball(float size, sf::Vector2f position, sf::Color color)
{
	ball.setRadius(size);
	ball.setPosition(position);
	ball.setFillColor(color);
};

sf::Vector2f Ball::getPosition()
{
	return ball.getPosition();
}

void Ball::setPosition(sf::Vector2f position)
{
	ball.setPosition(position);
}

void Ball::move(sf::Vector2f offset)
{
	ball.move(offset);
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
