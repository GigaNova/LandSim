#pragma once
#include "Explosion.h"
#include "Particle.h"

class ExplosionAftermath : public Particle
{
public:
	ExplosionAftermath(int _x, int _y, float _lifetime, ExplosionPower _power);

	void update(World* _world) override;
	sf::Color getColor() const override;
	void onDie(World* _world) override;

private:
	float m_timer;
	float m_lifetime;

	ExplosionPower m_power;
};

