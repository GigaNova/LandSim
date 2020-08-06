#pragma once
#include "Particle.h"

class Sand : public Particle
{
public:
	Sand(int _x, int _y);

	void update(World* _world) override;
	sf::Color getColor() const override;
};

