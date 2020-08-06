#pragma once
#include <map>
#include <string>
#include <vector>
#include "Component.h"
#include <typeinfo>
#include <algorithm>

struct Entity
{
	int id;
	Component* component;
};

class EntityManager
{
public:
	EntityManager();

	int createEntity(std::vector<Component*> _components);
	void addComponentToEntity(int _entityId, Component* _component);
	void removeEntity(int _entityId);

	template <typename T, typename = typename std::enable_if<std::is_base_of<Component, T>::value>::type>
	void removeComponentFromEntity(int _entityId)
	{
		delete m_components[typeid(T).name()][_entityId];
		m_components[typeid(T).name()][_entityId] = nullptr;
	}

	template <typename T, typename = typename std::enable_if<std::is_base_of<Component, T>::value>::type>
	T* getComponent(int _entityId)
	{
		const auto name = typeid(T).name();
		const auto found = m_components.find(name);

		if(found != m_components.end())
		{
			return dynamic_cast<T*>(m_components[name][_entityId]);
		}
		return nullptr;
	}

	template <typename T, typename = typename std::enable_if<std::is_base_of<Component, T>::value>::type>
	std::vector<Entity> getAllEntities()
	{
		std::vector<Entity> entities;

		auto components = m_components[typeid(T).name()];
		for(auto i = 0; i < components.size(); ++i)
		{
			if(components[i] != nullptr)
			{
				entities.push_back(Entity{
					i,
					components[i]
				});
			}
		}

		return entities;
	}

private:
	int m_highest_id;

	std::map<const char*, std::vector<Component*>> m_components;
	std::vector<int> m_entities;
};

