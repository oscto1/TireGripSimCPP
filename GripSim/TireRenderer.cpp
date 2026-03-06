#include "TireRenderer.h"
#include "Utils.h"
//void TireRenderer::drawTireFront(sf::RenderWindow& window, const TireState& state)
//{
//	//window.draw(state.m_tire.frontShape);
//}

void TireRenderer::drawTireTop(sf::RenderWindow& window, const TireState& state)
{
	window.draw(state.m_tire.topShape);
	window.draw(state.m_tire.contactPatch);
	drawVector(window, state.m_tire.position, state.m_velocityDir, 150.f, sf::Color(200, 20, 20));
	drawVector(window, state.m_tire.position, state.m_tireDirection, 150.f, sf::Color(200, 20, 20));
}

//void TireRenderer::drawTireSide(sf::RenderWindow& window, const TireState& state)
//{
//	//window.draw(state.m_tire.sideShape);
//}
void TireRenderer::drawVector(sf::RenderWindow& window, sf::Vector2f origin, sf::Vector2f direction, float length, sf::Color color)
{
	//sf::VertexArray line(sf::PrimitiveType::LineStrip, 2);
	sf::RectangleShape line;

	float stroke = 3.f;

	line.setSize({ stroke, length });
	line.setFillColor(color);
	line.setOrigin({ stroke / 2, length });
	line.setPosition(origin);
	line.setRotation(sf::degrees(Utils::vectorToAngle(direction)));

	window.draw(line);
}