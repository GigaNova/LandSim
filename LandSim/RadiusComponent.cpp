#include "RadiusComponent.h"

RadiusComponent::RadiusComponent(int _radius) : m_radius(_radius)
{
}

int RadiusComponent::getRadius() const
{
	return m_radius;
}

void RadiusComponent::setRadius(int _radius)
{
	m_radius = _radius;
}
