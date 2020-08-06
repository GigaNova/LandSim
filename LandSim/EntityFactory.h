#pragma once
#include <string>
#include <SFML/Graphics/Color.hpp>
#include "EntityManager.h"

class EntityFactory
{
public:
	static const int ASTEROID_RADIUS = 5;

	EntityFactory(EntityManager* _entityManager);

	int createAsteroid(float _x, float _y, float _vx, float _vy);
	int createPlanet(std::string _name, float _x, float _y, float _vx, float _vy, int _radius, sf::Color _color);
private:
	EntityManager* m_entityManager;
};

