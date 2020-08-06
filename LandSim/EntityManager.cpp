#include "EntityManager.h"
#include <algorithm>
#include <iostream>

EntityManager::EntityManager() : m_highest_id(-1)
{
}

int EntityManager::createEntity(const std::vector<Component*> _components)
{
	m_entities.push_back(++m_highest_id);

	for(auto c : _components)
	{
		addComponentToEntity(m_highest_id, c);
	}

	return m_highest_id;
}

void EntityManager::addComponentToEntity(int _entityId, Component* _component)
{
	const auto typeName = typeid(*_component).name();
	const auto found = m_components.find(typeName);

	if(found == m_components.end())
	{
		m_components.insert(
			std::make_pair(
				typeName,
				std::vector<Component*>(10000)
			)
		);
	}

	m_components[typeName][_entityId] = _component;
}

void EntityManager::removeEntity(int _entityId)
{
	m_entities.erase(
		std::remove(m_entities.begin(), m_entities.end(), _entityId), 
		m_entities.end()
	);
}
