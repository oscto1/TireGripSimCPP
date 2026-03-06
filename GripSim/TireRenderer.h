#pragma once
#include "TireState.h"

class TireRenderer
{
public:
	static void drawTireFront(sf::RenderWindow& window, const TireState& state);
	static void drawTireTop(sf::RenderWindow& window, const TireState& state);
	static void drawTireSide(sf::RenderWindow& window, const TireState& state);
	static void drawVector(sf::RenderWindow& window, sf::Vector2f origin, sf::Vector2f direction, float length, sf::Color color);
};

