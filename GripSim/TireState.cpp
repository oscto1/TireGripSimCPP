#include "TireState.h"
#include "Utils.h"

TireState::TireState(Tire& tire) : m_tire(tire)
{
	m_velocity = 0;
	m_turnAngle = 0;
}

void TireState::calculateState(float velocity, float turnAngle, float load)
{
	//tire.frontShape.setPoint(0, { 0.f, 0.f });
	m_turnAngle = turnAngle;

	float patchArea = (load / m_tire.pressure) * m_tire.patchEfficiency;

	float patchLength = patchArea / m_tire.width;

	setTopView(turnAngle, {m_tire.width * Utils::PIXELS_PER_METER, patchLength * Utils::PIXELS_PER_METER});
}

void TireState::setTopView(float turnAngle, sf::Vector2f patchSize)
{
	m_tire.topShape.setRotation(sf::degrees(turnAngle));
	m_tire.contactPatch.setRotation(sf::degrees(turnAngle));
	m_tire.contactPatch.setSize(patchSize);
	m_tire.contactPatch.setOrigin({ m_tire.contactPatch.getSize().x / 2 , m_tire.contactPatch.getSize().y / 2 });
}

