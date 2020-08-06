#include "EntityFactory.h"
#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "ColorComponent.h"
#include "RadiusComponent.h"

EntityFactory::EntityFactory(EntityManager* _entityManager) : m_entityManager(_entityManager)
{
	
}

int EntityFactory::createAsteroid(float _x, float _y, float _vx, float _vy)
{
	return m_entityManager->createEntity({
			new PositionComponent(_x, _y),
			new VelocityComponent(_vx, _vy),
			new RadiusComponent(ASTEROID_RADIUS),
			new ColorComponent(sf::Color::Black)
		}
	);
}

int EntityFactory::createPlanet(std::string _name, float _x, float _y, float _vx, float _vy, int _radius, sf::Color _color)
{
	return m_entityManager->createEntity({
		new PositionComponent(_x, _y),
		new VelocityComponent(_vx, _vy),
		new RadiusComponent(_radius),
		new ColorComponent(_color)
		}
	);
}
