#include "TireState.h"
#include "Utils.h"
#include <iostream>

TireState::TireState(Tire& tire) : m_tire(tire)
{
	m_velocityDir = Utils::angleToVector(0.f);;
	m_turnAngle = 0;
	m_carHeading = Utils::angleToVector(0.f);
}

void TireState::calculateState(sf::Vector2f velocityDir, float turnAngle, float load, float gripScale, float speed)
{
	std::cout << m_tire.data.baseGrip << std::endl;
	m_turnAngle = turnAngle;

	m_tireDirection = Utils::angleToVector(m_turnAngle);

	float patchArea = (load / m_tire.data.pressure) * m_tire.data.patchEfficiency;
	
	float patchLength = patchArea / m_tire.data.width;

	m_slipAngle = calculateSlipAngle(turnAngle, speed, gripScale);
	m_velocityDir = Utils::angleToVector( m_turnAngle - m_slipAngle );

	setTopView(turnAngle, {m_tire.data.width * Utils::PIXELS_PER_METER, patchLength * Utils::PIXELS_PER_METER});
}

void TireState::setTopView(float turnAngle, sf::Vector2f patchSize)
{
	m_tire.topShape.setRotation(sf::degrees(turnAngle));
	m_tire.contactPatch.setRotation(sf::degrees(turnAngle));
	m_tire.contactPatch.setSize(patchSize);
	m_tire.contactPatch.setOrigin({ m_tire.contactPatch.getSize().x / 2 , m_tire.contactPatch.getSize().y / 2 });
}

float TireState::calculateSlipAngle(float steerAngle, float speed, float gripScale)
{
	return steerAngle * (speed / (speed + gripScale));
}
