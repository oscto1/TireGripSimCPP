#pragma once
#include "TireState.h"

class TireRenderer
{
public:
	static void drawTireFront(sf::RenderWindow& window, const TireState& state);
	static void drawTireTop(sf::RenderWindow& window, const TireState& state);
	static void drawTireSide(sf::RenderWindow& window, const TireState& state);
};

