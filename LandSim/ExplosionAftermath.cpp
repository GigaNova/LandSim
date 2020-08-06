#include "ExplosionAftermath.h"
#include <random>
#include <random/random.hpp>
#include "GameTime.h"
#include "Grass.h"
#include "Helpers.h"
#include "World.h"
#include "Ocean.h"
#include "Sand.h"
#include "ScorchedEarth.h"

using Random = effolkronium::random_static;

ExplosionAftermath::ExplosionAftermath(int _x, int _y, float _lifetime, ExplosionPower _power) : Particle(_x, _y), m_timer(0), m_lifetime(_lifetime), m_power(_power)
{
	m_lifetime += Random::get(0, static_cast<int>(m_lifetime));
}

void ExplosionAftermath::update(World* _world)
{
	if(m_isAlive)
	{
		if (m_timer >= m_lifetime)
		{
			m_isAlive = false;
		}
		m_timer += 100 * GameTime::DeltaTime;
	}
}

sf::Color ExplosionAftermath::getColor() const
{
	return interpolateColors({ 241, 188, 49 }, { 178, 34, 34 }, m_timer / 25.f);
}

void ExplosionAftermath::onDie(World* _world)
{
	Particle* particleInPlace = _world->getTerrain()->getParticleAt(m_x, m_y);

	switch (m_power) {
	case MINIMAL:
		//Nothing for now.
		break;
	case NORMAL:
		if (dynamic_cast<Grass*>(particleInPlace))
		{
			int chance = Random::get(0, 100);
			chance > 50 ? _world->getTerrain()->addParticle(m_x, m_y, new ScorchedEarth(m_x, m_y)) : _world->getTerrain()->addParticle(m_x, m_y, new Grass(m_x, m_y));
		}
		break;
	case HIGH:
		if (!dynamic_cast<Ocean*>(particleInPlace) && !dynamic_cast<Sand*>(particleInPlace))
		{
			_world->getTerrain()->addParticle(m_x, m_y, new ScorchedEarth(m_x, m_y));
		}
		else
		{
			_world->getTerrain()->addParticle(m_x, m_y, new Ocean(m_x, m_y));
		}
		break;
	case NUCLEAR:
		_world->getTerrain()->addParticle(m_x, m_y, new Ocean(m_x, m_y));
		break;
	}


}
