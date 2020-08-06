#pragma once
#include "System.h"

class MoveSystem : public System
{
public:
	MoveSystem(EntityManager* _entityManager);

	void update() override;
};

