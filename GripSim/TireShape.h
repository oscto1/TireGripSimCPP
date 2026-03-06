#pragma once
#include <SFML/Graphics.hpp>

class TireShape : public sf::Shape
{
private:
	sf::Vector2f m_size;
	float m_cornerRadius;
	int m_cornerPointCount;

public:
	TireShape(sf::Vector2f size, float cornerRadius, int borderPoints);

	virtual std::size_t getPointCount() const override;

	sf::Vector2f getPoint(std::size_t index) const override;

	//void setCornerPointCount(std::size_t count);

};

