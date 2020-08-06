#pragma once
#include <vector>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>


#include "Country.h"
#include "Particle.h"

class World;
class Simulator
{
public:
	static const int TICK_THRESHOLD = 25;
	
	Simulator(World* _world);
	
	void updateSimulation();
	sf::Sprite* getOverlay();
	sf::Sprite* getTerritoryMap();

	void addParticle(Particle* _particle);
	Particle* getParticleAt(int _x, int _y) const;
	
	void createExplosionAt(float m_x, float m_y);
	void createCountryAt(float m_x, float m_y);
private:
	World* m_world;
	std::vector<Particle*> m_simulatedParticles;
	sf::Texture* m_texture;
	sf::Sprite* m_overlay;

	sf::Image* m_territoryImage;
	sf::Texture* m_territoryTexture;
	sf::Sprite* m_territoryMap;
	
	int m_simulatorTick;

	std::vector<Country*> m_countries;
};

