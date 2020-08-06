#pragma once
#include "Component.h"
#include <SFML/Graphics/Color.hpp>
#include <string>

class ColorComponent : public Component
{
public:
	ColorComponent(const sf::Color& _color);

	sf::Color getColor() const;
	void setColor(sf::Color _color);
private:
	sf::Color m_color;
};

