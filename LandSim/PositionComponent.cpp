#include "PositionComponent.h"

PositionComponent::PositionComponent(float _x, float _y) : m_x(_x), m_y(_y)
{
}

std::pair<float, float> PositionComponent::getPosition() const
{
	return std::make_pair(m_x, m_y);
}

void PositionComponent::setPosition(float _x, float _y)
{
	m_x = _x;
	m_y = _y;
}
