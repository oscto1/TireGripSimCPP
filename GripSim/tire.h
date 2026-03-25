#pragma once
#include <SFML/Graphics.hpp>
#include "TireShape.h"
#include "TireData.h"

class Tire
{
public:
	Tire(TireData &data, sf::Vector2f position);

	TireData data;
	//float radius;
	//float width;
	//float pressure;
	//float baseGrip;
	//float patchEfficiency = 0.85f;

	sf::Vector2f position;

	TireShape           topShape;
	sf::RectangleShape  contactPatch;
};

