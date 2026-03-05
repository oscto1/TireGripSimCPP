#pragma once
#include "tire.h"

class TireState
{
public:
	TireState(Tire& tire);

	float m_velocity;
	float m_turnAngle;
	Tire m_tire;

	void calculateState(float velocity, float turnAngle);

	void setTopView(float turnAngle);
};

