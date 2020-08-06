#include "World.h"
#include <iostream>
#include "EntityManager.h"
#include <thread>

#include "GameTime.h"
#include "Simulator.h"
#include "WorldGenerator.h"

World::World()
{
	m_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flat Galaxy Society");
}

void World::start()
{
	WorldGenerator generator;
	m_terrain = generator.generateWorld(WINDOW_WIDTH, WINDOW_HEIGHT);
	m_terrain->redrawTerrain();

	m_simulator = new Simulator(this);
	
	float fps;
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;

	GameTime::Init();
	while (m_window->isOpen())
	{
		
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				m_window->close();
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				float mX = sf::Mouse::getPosition(*m_window).x;
				float mY = sf::Mouse::getPosition(*m_window).y;
				m_simulator->createCountryAt(mX, mY);
			}
		}

		update();
		draw();

		GameTime::Update();
	}
}

Terrain* World::getTerrain() const
{
	return m_terrain;
}

Simulator* World::getSimulation() const
{
	return m_simulator;
}

void World::update()
{
	m_simulator->updateSimulation();
	if(m_terrain->needRenderUpdate())
	{
		m_terrain->redrawTerrain();
	}
}

void World::draw()
{
	m_window->clear();
	m_window->draw(*m_terrain->getTerrainMap());
	m_window->draw(*m_simulator->getTerritoryMap());
	m_window->draw(*m_simulator->getOverlay());
	m_window->display();
}
