#include "Grass.h"

Grass::Grass(int _x, int _y) : Particle(_x, _y)
{
}

void Grass::update(World* _world)
{
}

sf::Color Grass::getColor() const
{
	return { 58, 89, 20 };
}
