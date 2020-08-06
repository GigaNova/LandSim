#include "DrawSystem.h"
#include "ColorComponent.h"
#include "RadiusComponent.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "PositionComponent.h"

DrawSystem::DrawSystem(sf::RenderWindow* _window, EntityManager* _entityManager) : System(_entityManager), m_window(_window)
{

}

void DrawSystem::update()
{
	m_window->clear(sf::Color::White);

	auto entities = m_entityManager->getAllEntities<ColorComponent>();
	for(auto entity : entities)
	{
		auto radius = m_entityManager->getComponent<RadiusComponent>(entity.id);
		auto position = m_entityManager->getComponent<PositionComponent>(entity.id);

		sf::CircleShape shape(radius->getRadius());
		shape.setFillColor(dynamic_cast<ColorComponent*>(entity.component)->getColor());
		shape.setPosition(position->getPosition().first, position->getPosition().second);

		m_window->draw(shape);
	}

	m_window->display();
}
