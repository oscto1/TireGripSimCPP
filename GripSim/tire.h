#pragma once
#include <SFML/Graphics.hpp>

class Tire
{
public:
	Tire(float radius, float width);

	void setPosition(const sf::Vector2f& position);
	void setLoad(float load);
	void update();
	void draw(sf::RenderWindow& window);

private:
	float m_radius;
	float m_load;

	sf::ConvexShape m_shape;
};

