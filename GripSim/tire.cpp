#include "Tire.h"

Tire::Tire(float radius, float width, float pressure) : radius(radius), width(width), pressure(pressure)
{
	frontShape.setPointCount(4);
	topShape.setPointCount(4);
	sideShape.setRadius(radius);

	topShape.setPoint(0, { 0.f, 0.f });
	topShape.setPoint(1, { width, 0.f });
	topShape.setPoint(2, { width, radius * 2 });
	topShape.setPoint(3, { 0.f, radius * 2 });

	topShape.setOrigin({ width / 2, radius });
	topShape.setPosition({ 200,200 });
}