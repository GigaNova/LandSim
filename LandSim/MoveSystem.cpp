#include "MoveSystem.h"
#include "VelocityComponent.h"
#include "PositionComponent.h"

MoveSystem::MoveSystem(EntityManager* _entityManager) : System(_entityManager)
{
}

void MoveSystem::update()
{
	auto entities = m_entityManager->getAllEntities<VelocityComponent>();
	for (auto entity : entities)
	{
		auto component = dynamic_cast<VelocityComponent*>(entity.component);
		auto position = m_entityManager->getComponent<PositionComponent>(entity.id);
		auto oldPosition = position->getPosition();

		oldPosition.first += component->getVelocity().first;
		oldPosition.second += component->getVelocity().second;

		position->setPosition(oldPosition.first, oldPosition.second);
	}
}
