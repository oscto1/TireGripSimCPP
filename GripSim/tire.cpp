#include "tire.h"

Tire::Tire(float radius, float width) : m_radius(radius), m_load(1000.f)
{
	m_shape.setPointCount(4);
	m_shape.setPoint(0, { 0.f,0.f });
	m_shape.setPoint(1, { width ,0.f });
	m_shape.setPoint(2, { width, radius * 2 });
	m_shape.setPoint(3, { 0.f, radius * 2 });

	//m_shape.setSize({width, radius * 2});
	m_shape.setFillColor(sf::Color::White);
	m_shape.setOrigin({ width / 2, radius });
}

void Tire::setPosition(const sf::Vector2f& position)
{
	m_shape.setPosition(position);
}

void Tire::setLoad(float load)
{
	m_load = load;
}

void Tire::update()
{
	// Fake deformation based on load
	float deformation = m_load / 10000.f;

	m_shape.setScale({ 1.f + deformation, 1.f - deformation });
}

void Tire::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}