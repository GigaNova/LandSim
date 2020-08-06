#include "Trail.h"

Trail::Trail(int _x, int _y, int _maxLifetime) : Particle(_x, _y), m_lifetime(1), m_maxLifetime(_maxLifetime)
{
}

void Trail::update(World* _world)
{
	if(m_isAlive)
	{
		m_lifetime += 1;
		if (m_lifetime > m_maxLifetime)
		{
			m_isAlive = false;
			m_lifetime = m_maxLifetime;
		}
	}
}

sf::Color Trail::getColor() const
{
	return { 255, 255, 255, sf::Uint8(255 - (255 / (m_maxLifetime / m_lifetime))) };
}
