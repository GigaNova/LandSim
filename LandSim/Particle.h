#pragma once
#include <SFML\Graphics\Color.hpp>

class World;
class Particle {
public:
	Particle(int _x, int _y) : m_x(_x), m_y(_y), m_isAlive(true), m_isClaimed(false) {};
	virtual ~Particle() {};

	int getX() const
	{
		return m_x;
	}

	int getY() const
	{
		return m_y;
	}

	bool isAlive() const
	{
		return m_isAlive;
	}

	void claim()
	{
		m_isClaimed = true;
	}
	
	bool isClaimed() const
	{
		return m_isClaimed;
	}
	
	virtual void update(World* _world) = 0;
	virtual sf::Color getColor() const = 0;

	virtual void onDie(World* _world) {};
protected:
	int m_x;
	int m_y;

	bool m_isAlive;
	bool m_isClaimed;
};