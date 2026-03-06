#include "TireShape.h"
#include <SFML/Graphics.hpp>

TireShape::TireShape(sf::Vector2f size, float cornerRadius, int borderPoints) : m_size(size), m_cornerRadius(cornerRadius), m_cornerPointCount(borderPoints)
{
	update();
}

std::size_t TireShape::getPointCount() const
{
	return m_cornerPointCount * 4;
}

sf::Vector2f TireShape::getPoint(std::size_t index) const
{
	std::size_t corner = index / m_cornerPointCount;
	float i = index % m_cornerPointCount;

	float angle = (i / (m_cornerPointCount - 1)) * 90.f;

	sf::Vector2f center;

	switch (corner)
	{
		case 0:
			center = { m_size.x - m_cornerRadius, m_cornerRadius };
			angle -= 90.f;
			break;
		case 1:
			center = { m_size.x - m_cornerRadius, m_size.y - m_cornerRadius};
			angle += 0.f;
			break;
		case 2:
			center = { m_cornerRadius, m_size.y - m_cornerRadius };
			angle += 90.f;
			break;
		case 3:
			center = { m_cornerRadius, m_cornerRadius };
			angle += 180.f;
			break;
	}

	float rad = angle * 3.141592654f / 180.f;

	return
	{
		center.x + std::cos(rad) * m_cornerRadius,
		center.y + std::sin(rad) * m_cornerRadius
	};
}