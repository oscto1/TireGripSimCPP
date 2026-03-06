#include "Tire.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TireShape.h"
#include "Utils.h"

Tire::Tire(float radius, float width, float pressure, sf::Vector2f position) : radius(radius), width(width), pressure(pressure), position(position), topShape({width * Utils::PIXELS_PER_METER, radius * Utils::PIXELS_PER_METER * 2}, 12.f, 8)
{
	/*sf::Texture texture;
	if (!texture.loadFromFile("img/corner.png", false, sf::IntRect({ 0, 0 }, { 12, 12 })))
	{
		std::cout << "Error loading the image" << "\n";
	}*/

	topShape.setOrigin({width * Utils::PIXELS_PER_METER / 2, radius  * Utils::PIXELS_PER_METER });
	topShape.setPosition(position);
	contactPatch.setSize({ width * Utils::PIXELS_PER_METER, 0 });
	contactPatch.setOrigin({ (width * Utils::PIXELS_PER_METER) / 2, radius * Utils::PIXELS_PER_METER });
	contactPatch.setPosition(position);
	contactPatch.setFillColor(sf::Color(0, 0, 0, 60));
}