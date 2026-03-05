#include "TireState.h"

TireState::TireState(Tire& tire) : m_tire(tire)
{
	m_velocity = 0;
	m_turnAngle = 0;
}

void TireState::calculateState(float velocity, float turnAngle)
{
	//tire.frontShape.setPoint(0, { 0.f, 0.f });
	m_turnAngle = turnAngle;
	setTopView(turnAngle);
}

void TireState::setTopView(float turnAngle)
{
	m_tire.topShape.setRotation(sf::degrees(turnAngle));
}

