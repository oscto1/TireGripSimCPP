#pragma once

class Utils
{
public:
	static constexpr float PIXELS_PER_METER = 200.f;
	static constexpr float DEG2RAD = 3.14159265f / 180.f;

	static sf::Vector2f angleToVector(float angle)
	{
		float rad = (angle - 90.f) * DEG2RAD; //-90 because my model is facing up
		return { std::cos(rad), std::sin(rad) };
	}

	static float vectorToAngle(sf::Vector2f vector)
	{
		float angle = std::atan2(vector.y, vector.x) * 180 / 3.14159265f;
		return angle + 90;
	}
};