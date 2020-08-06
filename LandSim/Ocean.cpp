#include "Ocean.h"

Ocean::Ocean(int _x, int _y) : Particle(_x, _y)
{
}


void Ocean::update(World* _world)
{
}

sf::Color Ocean::getColor() const
{
	return { 23,143,215 };
}
