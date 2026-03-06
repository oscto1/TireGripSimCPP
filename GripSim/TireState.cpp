#include "TireState.h"
#include "Utils.h"

TireState::TireState(Tire& tire) : m_tire(tire)
{
	m_velocityDir = Utils::angleToVector(0.f);;
	m_turnAngle = 0;
	m_carHeading = Utils::angleToVector(0.f);
}

void TireState::calculateState(sf::Vector2f, float turnAngle, float load)
{
	//tire.frontShape.setPoint(0, { 0.f, 0.f });
	m_turnAngle = turnAngle;

	m_tireDirection = Utils::angleToVector(m_turnAngle);
	/*m_slipAngle = */

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

float TireState::calculateSlipAngle(sf::Vector2f velocityDir, float turnAngle)
{
	return 0;
}
