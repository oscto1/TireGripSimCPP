#pragma once
#include <SFML/Graphics.hpp>
#include "TireShape.h"

class Tire
{
public:
	Tire(float radius, float width, float pressure, sf::Vector2f position);

	float radius;
	float width;
	float pressure;

	float patchEfficiency = 0.85f;

	sf::Vector2f position;

	TireShape           topShape;
	sf::RectangleShape  contactPatch;
};

