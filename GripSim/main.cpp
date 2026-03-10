#include <SFML/Graphics.hpp>
#include "Tire.h"
#include "TireState.h"
#include "TireRenderer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Tire Grip Simulator");

	Tire tire(0.32f, 0.255f, 210000.f, 0.8f, {(float)window.getSize().x / 2,  (float)window.getSize().y / 2});
	TireState state(tire);

	float load = 7000.f;
	float turnAngle = 0.f;
	float speed = 100.f;
	float gripScale = 10;

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && turnAngle > -35)
		{
			turnAngle -= 0.03f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && turnAngle < 35)
		{
			turnAngle += 0.03f;
		}

		state.calculateState({0.f, 0.f}, turnAngle, load, gripScale, speed);

		

		window.clear(sf::Color(30, 36, 40));
		TireRenderer::drawTireTop(window, state);

		window.display();
	}
}

void handleResize(sf::RenderWindow& window, unsigned width, unsigned height)
{
	float windowRatio = (float)width / height;
	float viewRatio = 1.0f; // 800 / 800

}