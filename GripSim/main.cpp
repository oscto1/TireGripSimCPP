#include <SFML/Graphics.hpp>
#include "Tire.h"
#include "TireState.h"
#include "TireRenderer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Tire Grip Simulator");

	Tire tire(0.32f, 0.255f, 210000.f, {(float)window.getSize().x / 2,  (float)window.getSize().y / 2});
	TireState state(tire);

	float load = 1000.f;
	float angle = 0.f;

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && angle > -35)
		{
			angle -= 0.03f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && angle < 35)
		{
			angle += 0.03f;
		}

		state.calculateState(0.f, angle, 4000);

		

		window.clear(sf::Color(30, 36, 40));
		TireRenderer::drawTireTop(window, state);

		window.display();
	}
}