#include "TireRenderer.h"
#include "Utils.h"
#include <iostream>
//void TireRenderer::drawTireFront(sf::RenderWindow& window, const TireState& state)
//{
//	//window.draw(state.m_tire.frontShape);
//}

void TireRenderer::drawTireTop(sf::RenderWindow& window, const TireState& state)
{
	window.draw(state.m_tire.topShape);
	window.draw(state.m_tire.contactPatch);
	//std::cout << state.m_tire.position.x << " " << state.m_tire.position.y << std::endl;
	drawVector(window, state.m_tire.position, state.m_carHeading, 150.f, sf::Color(250, 250, 250));    // car heading vector
	drawVector(window, state.m_tire.position, state.m_velocityDir, 200.f, sf::Color(200, 20, 20));
	drawVector(window, state.m_tire.position, state.m_tireDirection, 150.f, sf::Color(20, 20, 200)); // tire direction vector
}

//void TireRenderer::drawTireSide(sf::RenderWindow& window, const TireState& state)
//{
//	//window.draw(state.m_tire.sideShape);
//}
void TireRenderer::drawVector(sf::RenderWindow& window, sf::Vector2f origin, sf::Vector2f direction, float length, sf::Color color)
{
	sf::RectangleShape line;

	float stroke = 3.f;

	line.setSize({ stroke, length });
	line.setFillColor(color);
	line.setOrigin({ stroke / 2, length });
	line.setPosition(origin);
	line.setRotation(sf::degrees(Utils::vectorToAngle(direction )));

	window.draw(line);
}