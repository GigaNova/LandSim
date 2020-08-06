#pragma once
#include "Particle.h"

class Seeker : public Particle
{
public:
	Seeker(int _x, int _y);

	void update(World* _world) override;
	sf::Color getColor() const override;
};

