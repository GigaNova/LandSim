#pragma once
#include <map>
#include <vector>
#include "Particle.h"

enum ExplosionPower
{
	MINIMAL,
	NORMAL,
	HIGH,
	NUCLEAR
};

class Explosion : public Particle
{
public:
	Explosion(int _x, int _y, int _maxSize, float _speed, int _aliveTime, ExplosionPower _power);

	void update(World* _world) override;
	sf::Color getColor() const override;

	bool positionCovered(int x, int y) const;
private:
	void tryPlaceExplosionAftermath(int _x, int _y, World* _world);
	
	int m_size;
	int m_maxSize;

	float m_explosionSpeed;

	float m_timer;
	int m_aliveTime;

	bool m_expanded;

	ExplosionPower m_power;
	
	std::map<std::tuple<int, int>, bool> m_positionsCovered;
};

