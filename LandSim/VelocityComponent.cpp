#include "VelocityComponent.h"

VelocityComponent::VelocityComponent(float _x, float _y) : m_x(_x), m_y(_y)
{
}


std::pair<float, float> VelocityComponent::getVelocity() const
{
	return std::make_pair(m_x, m_y);
}

void VelocityComponent::setVelocity(float _x, float _y)
{
	m_x = _x;
	m_y = _y;
}
