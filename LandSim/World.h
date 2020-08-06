#pragma once
#include <SFML/Graphics.hpp>
#include "Terrain.h"

class Simulator;
class World
{
public:
	static const int WINDOW_WIDTH = 1000;
	static const int WINDOW_HEIGHT = 1000;

	World();

	void start();

	Terrain* getTerrain() const;
	Simulator* getSimulation() const;
private:
	void update();
	void draw();
	
	sf::RenderWindow* m_window;
	Terrain* m_terrain;
	Simulator* m_simulator;
};

