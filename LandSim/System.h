#pragma once
#include "EntityManager.h"

class System
{
public:
	System(EntityManager* _entity_manager);

	virtual void update() = 0;
protected:
	EntityManager* m_entityManager;
};
