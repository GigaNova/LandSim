#pragma once
#include "Particle.h"

class Grass : public Particle
{
public:
	Grass(int _x, int _y);
	
	void update(World* _world) override;
	sf::Color getColor() const override;
};

