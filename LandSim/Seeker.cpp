#include "Seeker.h"
#include "Ocean.h"
#include "World.h"
#include "Simulator.h"
#include "Trail.h"
#include "random/random.hpp"

using Random = effolkronium::random_static;

Seeker::Seeker(int _x, int _y) : Particle(_x, _y)
{
}

void Seeker::update(World* _world)
{
	int vX = Random::get(-1, 1);
	int vY = Random::get(-1, 1);

	Particle* particleAtLocation = _world->getTerrain()->getParticleAt(m_x + vX, m_y + vY);

	Ocean* isOcean = dynamic_cast<Ocean*>(particleAtLocation);
	if(isOcean)
	{
		return;
	}
	
	_world->getSimulation()->addParticle(new Trail(m_x, m_y, 50));

	m_x += vX;
	m_y += vY;
}

sf::Color Seeker::getColor() const
{
	return { 255, 0, 0 };
}
