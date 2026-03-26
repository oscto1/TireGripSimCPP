#include "Tire.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TireShape.h"
#include "Utils.h"

Tire::Tire(TireData &data, sf::Vector2f position) : data(data), position(position), topShape({data.width * Utils::PIXELS_PER_METER, data.radius * Utils::PIXELS_PER_METER * 2}, 12.f, 8)
{
	/*sf::Texture texture;
	if (!texture.loadFromFile("img/corner.png", false, sf::IntRect({ 0, 0 }, { 12, 12 })))
	{
		std::cout << "Error loading the image" << "\n";
	}*/

	topShape.setOrigin({data.width * Utils::PIXELS_PER_METER / 2, data.radius  * Utils::PIXELS_PER_METER });
	topShape.setPosition(position);
	contactPatch.setSize({ data.width * Utils::PIXELS_PER_METER, 0 });
	contactPatch.setOrigin({ (data.width * Utils::PIXELS_PER_METER) / 2, data.radius * Utils::PIXELS_PER_METER });
	contactPatch.setPosition(position);
	contactPatch.setFillColor(sf::Color(0, 0, 0, 60));
}