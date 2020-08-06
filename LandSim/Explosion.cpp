#include "Explosion.h"
#include <iostream>
#include "ExplosionAftermath.h"
#include "GameTime.h"
#include "Ocean.h"
#include "World.h"
#include "Simulator.h"

Explosion::Explosion(int _x, int _y, int _maxSize, float _speed, int _aliveTime, ExplosionPower _power) : Particle(_x, _y), m_size(1), m_maxSize(_maxSize), m_explosionSpeed(_speed), m_timer(0), m_expanded(false), m_aliveTime(_aliveTime), m_power(_power)
{
}

void Explosion::update(World* _world)
{
	if(m_size < m_maxSize && m_timer >= m_explosionSpeed && m_isAlive){
        int x = m_x;
        int y = m_y;
        int r = m_size;
        float sinus = 0.70710678118;
		
        int range = r / (2 * sinus);
        for (int i = r; i >= range; --i)
        {
            int j = sqrt(r * r - i * i);
            for (int k = -j; k <= j; k++)
            {
                tryPlaceExplosionAftermath(x - k, y + i, _world);
                tryPlaceExplosionAftermath(x - k, y - i, _world);
                tryPlaceExplosionAftermath(x + i, y + k, _world);
                tryPlaceExplosionAftermath(x - i, y - k, _world);
            }
        }
		
        range = r * sinus;
        for (int i = x - range + 1; i < x + range; i++)
        {
            for (int j = y - range + 1; j < y + range; j++)
            {
                tryPlaceExplosionAftermath(i, j, _world);
            }
        }
		
        m_timer = 0;
        ++m_size;
	}
	else if(m_size == m_maxSize)
    {
        m_isAlive = false;
    }
	else
    {
        m_timer += 100 * GameTime::DeltaTime;
    }
}

sf::Color Explosion::getColor() const
{
	return { 0, 0, 0, 0};
}

bool Explosion::positionCovered(int x, int y) const
{
	auto f = m_positionsCovered.find({ x, y });
    return f != m_positionsCovered.end();
}

void Explosion::tryPlaceExplosionAftermath(int _x, int _y, World* _world)
{
    if (!positionCovered(_x, _y))
    {
        _world->getSimulation()->addParticle(new ExplosionAftermath(_x, _y, m_aliveTime, m_power));
        m_positionsCovered.insert_or_assign({ _x, _y }, true);
    }
}
