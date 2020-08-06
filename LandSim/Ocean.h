#pragma once
#include "Particle.h"

class Ocean : public Particle
{
public:
	Ocean(int _x, int _y);

	void update(World* _world) override;
	sf::Color getColor() const override;
};

