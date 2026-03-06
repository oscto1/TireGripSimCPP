#pragma once
#include "tire.h"

class TireState
{
public:
	TireState(Tire& tire);

	sf::Vector2f m_carHeading;
	sf::Vector2f m_velocityDir;
	sf::Vector2f m_tireDirection;
	float m_turnAngle = 0.f;
	float m_slipAngle = 0.f;
	


	Tire m_tire;

	void calculateState(sf::Vector2f velocityDir, float turnAngle, float load);

	void setTopView(float turnAngle, sf::Vector2f patchSize);

private:
	float calculateSlipAngle(sf::Vector2f m_velocityDir, float turnAngle);
};

