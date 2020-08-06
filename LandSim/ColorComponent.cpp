#include "ColorComponent.h"

ColorComponent::ColorComponent(const sf::Color& _color) : m_color(_color)
{
}

sf::Color ColorComponent::getColor() const
{
	return  m_color;
}

void ColorComponent::setColor(sf::Color _color)
{
	m_color = _color;
}
