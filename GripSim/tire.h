#pragma once
#include <SFML/Graphics.hpp>

class Tire
{
public:
	Tire(float radius, float width, float pressure);

	float radius;
	float width;
	float pressure;
	//void setPosition(const sf::Vector2f& position);

//private:
//	float m_radius;
//	float m_width;
//	float m_pressure;

	sf::ConvexShape frontShape;
	sf::ConvexShape topShape;
	sf::CircleShape sideShape;
};

