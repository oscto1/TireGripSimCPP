#include <SFML/Graphics.hpp>
#include "Tire.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Tire Grip Simulator");

	Tire tire(80.f, 45.f);

	float load = 1000.f;

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		tire.setPosition({ (float)window.getSize().x / 2, (float)window.getSize().y / 2});
		tire.update();

		window.clear(sf::Color(30, 30, 30));
		tire.draw(window);
		window.display();
	}
}