#pragma once
#include "System.h"
#include <SFML/Graphics/RenderWindow.hpp>

class DrawSystem : public System
{
public:
	DrawSystem(sf::RenderWindow* _window, EntityManager* _entityManager);

	void update() override;
private:
	sf::RenderWindow* m_window;
};

