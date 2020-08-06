#pragma once
#include "Particle.h"
class Trail : public Particle
{
public:
	Trail(int _x, int _y, int _maxLifetime);

	void update(World* _world) override;
	sf::Color getColor() const override;

private:
	int m_lifetime;
	int m_maxLifetime;
};

