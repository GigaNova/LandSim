#pragma once
#include "Particle.h"

class Country;
class Territory : public Particle
{
public:
	Territory(int _x, int _y, Country* _owner);

	void update(World* _world) override;
	sf::Color getColor() const override;

	void expandIfPossible(World* _world);
private:
	bool expandAtPositionIfPossible(Particle* _particleAtPosition) const;
	
	bool m_expendable;
	Country* m_country;

	sf::Color m_color;
};

