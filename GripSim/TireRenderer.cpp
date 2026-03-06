#include "TireRenderer.h"

void TireRenderer::drawTireFront(sf::RenderWindow& window, const TireState& state)
{
	//window.draw(state.m_tire.frontShape);
}

void TireRenderer::drawTireTop(sf::RenderWindow& window, const TireState& state)
{
	window.draw(state.m_tire.topShape);
	window.draw(state.m_tire.contactPatch);
}

void TireRenderer::drawTireSide(sf::RenderWindow& window, const TireState& state)
{
	//window.draw(state.m_tire.sideShape);
}