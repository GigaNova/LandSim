#pragma once
#include "Particle.h"

class ScorchedEarth : public Particle
{
public:
	ScorchedEarth(int _x, int _y);

	void update(World* _world) override;
	sf::Color getColor() const override;
};

