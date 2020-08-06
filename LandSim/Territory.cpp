#include "Territory.h"
#include "Country.h"
#include "Ocean.h"
#include "World.h"

Territory::Territory(int _x, int _y, Country* _country) : Particle(_x, _y), m_expendable(true), m_country(_country), m_color(m_country->getColor())
{
}

void Territory::update(World* _world)
{
}

sf::Color Territory::getColor() const
{
	return m_color;
}

void Territory::expandIfPossible(World* _world)
{
	if(m_expendable)
	{
		Particle* particleLeft = _world->getTerrain()->getParticleAt(m_x - 1, m_y);
		Particle* particleRight = _world->getTerrain()->getParticleAt(m_x + 1, m_y);
		Particle* particleTop = _world->getTerrain()->getParticleAt(m_x, m_y - 1);
		Particle* particleBottom = _world->getTerrain()->getParticleAt(m_x, m_y + 1);

		bool expandedLeft = expandAtPositionIfPossible(particleLeft);
		bool expandedRight = expandAtPositionIfPossible(particleRight);
		bool expandedTop = expandAtPositionIfPossible(particleTop);
		bool expandedBottom = expandAtPositionIfPossible(particleBottom);

		m_expendable = false;

		if(expandedLeft || expandedRight || expandedTop || expandedBottom)
		{
			m_color.a = 155;
		}
	}
}

bool Territory::expandAtPositionIfPossible(Particle* _particleAtPosition) const
{
	if (_particleAtPosition && !_particleAtPosition->isClaimed() && !dynamic_cast<Territory*>(_particleAtPosition) && !dynamic_cast<Ocean*>(_particleAtPosition))
	{
		m_country->addTerritory(_particleAtPosition->getX(), _particleAtPosition->getY());
		_particleAtPosition->claim();
		return true;
	}

	return false;
}


