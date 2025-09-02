#include <SFML/Graphics.hpp>

double getRandomY()
{
    return ((float)rand() / (RAND_MAX) * 2 - 1);
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "Pong SFML");
    sf::Clock clock;

	sf::RectangleShape left({ 15, 80 });
	left.setPosition({ 20, 210 });
    left.setFillColor(sf::Color::Yellow);

	sf::RectangleShape right({ 15, 80 });
	right.setPosition({ 465, 210 });
	right.setFillColor(sf::Color(95, 20, 150));

	sf::CircleShape ball(10.f);
	ball.setPosition({ 250, 250 });
	ball.setFillColor(sf::Color::White);
    
    sf::Font font("OpenSans.ttf");

    float moveX = 1, moveY = getRandomY();
    float speed = 120;
	int score1 = 0, score2 = 0;
    bool ui = 1;

    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (ui == 1)
        {
            sf::Text text(font);

            text.setString("PONG\nPlayer 1: W, S     Player 2: Up, Down\nFirst to 5 points wins!\nPress Enter to start!");
			text.setCharacterSize(24);
			text.setFillColor(sf::Color::White);
			text.setPosition({ 50, 175 });
            text.setStyle(sf::Text::Bold);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
            {
                ui = 0;
			}

            window.clear();
			window.draw(text);
            window.display();
        }

        else
        {
            sf::Time deltaTime = clock.restart();
            float dT = deltaTime.asSeconds();

            sf::Vector2f lPosition = left.getPosition();
            sf::Vector2f rPosition = right.getPosition();

			sf::Text score1Text(font);
			sf::Text score2Text(font);

			score1Text.setString(std::to_string(score1));
			score1Text.setCharacterSize(35);
			score1Text.setFillColor(sf::Color::White);
			score1Text.setPosition({ 50, 20 });
			score1Text.setStyle(sf::Text::Bold);

			score2Text.setString(std::to_string(score2));
			score2Text.setCharacterSize(35);
			score2Text.setFillColor(sf::Color::White);
			score2Text.setPosition({ 425, 20 });
			score2Text.setStyle(sf::Text::Bold);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                if (rPosition.y > 0) right.setPosition(rPosition + sf::Vector2f(0, -200.f * dT));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                if (rPosition.y < 420) right.setPosition(rPosition + sf::Vector2f(0, 200.f * dT));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                if (lPosition.y > 0) left.setPosition(lPosition + sf::Vector2f(0, -200.f * dT));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                if (lPosition.y < 420) left.setPosition(lPosition + sf::Vector2f(0, 200.f * dT));
            }

            if (ball.getPosition().y < 0 || ball.getPosition().y > 485)
            {
                moveY *= -1;
            }

            if (ball.getPosition().y < right.getPosition().y + 85 && ball.getPosition().y > right.getPosition().y - 5)
            {
                if (ball.getPosition().x > right.getPosition().x - 20 && ball.getPosition().x < right.getPosition().x - 15) moveX *= -1;
            }

            if (ball.getPosition().y < left.getPosition().y + 85 && ball.getPosition().y > left.getPosition().y - 5)
            {
                if (ball.getPosition().x < left.getPosition().x + 15 && ball.getPosition().x > left.getPosition().x + 10) moveX *= -1;
            }

            if (ball.getPosition().x < 0)
            {
                score2++;
                ball.setPosition({ 250, 250 });
                moveX = 1;
                moveY = getRandomY();
                speed = 120;
            }

            else if (ball.getPosition().x > 500)
            {
                score1++;
                ball.setPosition({ 250, 250 });
                moveX = -1;
                moveY = getRandomY();
				speed = 120;
            }

            ball.move({ moveX * speed * dT, moveY * speed * dT });
            speed += 0.00001f;

            window.clear();
            window.draw(left);
            window.draw(right);
            window.draw(ball);
			window.draw(score1Text);
			window.draw(score2Text);
            window.display();
        }
    }
}