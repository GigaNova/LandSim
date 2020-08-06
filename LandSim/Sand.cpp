#include "Sand.h"

Sand::Sand(int _x, int _y) : Particle(_x, _y)
{
}

void Sand::update(World* _world)
{
}

sf::Color Sand::getColor() const
{
	return { 233, 210, 193 };
}
