#include "ScorchedEarth.h"

ScorchedEarth::ScorchedEarth(int _x, int _y) : Particle(_x, _y)
{
}

void ScorchedEarth::update(World* _world)
{
}

sf::Color ScorchedEarth::getColor() const
{
	return { 178, 190, 181 };
}
