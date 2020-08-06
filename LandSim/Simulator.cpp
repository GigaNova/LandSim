#include "Simulator.h"
#include <random/random.hpp>
#include <SFML/Graphics/Image.hpp>
#include "Explosion.h"
#include "World.h"

using Random = effolkronium::random_static;

Simulator::Simulator(World* _world) : m_world(_world), m_simulatorTick(0), m_territoryImage(new sf::Image()), m_territoryTexture(new sf::Texture()), m_territoryMap(new sf::Sprite())
{
	m_territoryImage->create(World::WINDOW_WIDTH, World::WINDOW_HEIGHT, sf::Color::Transparent);
}

void Simulator::updateSimulation()
{
	if(m_simulatorTick == TICK_THRESHOLD)
	{
		for(int i = 0; i < m_simulatedParticles.size(); ++i)
		{
			Particle* particle = m_simulatedParticles[i];

			if(!particle->isAlive())
			{
				m_simulatedParticles[i]->onDie(m_world);
				delete m_simulatedParticles[i];
				m_simulatedParticles.erase(m_simulatedParticles.begin() + i);
				continue;
			}
			
			particle->update(m_world);
		}
		m_simulatorTick = 0;
	}
	m_simulatorTick++;
}

sf::Sprite* Simulator::getOverlay()
{
	if(m_simulatorTick == TICK_THRESHOLD || !m_overlay)
	{
		delete m_texture;
		delete m_overlay;

		sf::Image image;
		image.create(World::WINDOW_WIDTH, World::WINDOW_HEIGHT, sf::Color::Transparent);

		for (Particle* particle : m_simulatedParticles)
		{
			image.setPixel(particle->getX(), particle->getY(), particle->getColor());
		}

		m_texture = new sf::Texture();
		m_texture->loadFromImage(image);
		m_overlay = new sf::Sprite();
		m_overlay->setTexture(*m_texture, true);
	}
	
	return m_overlay;
}

sf::Sprite* Simulator::getTerritoryMap()
{
	bool countryUpdated = false;
	for(Country* c : m_countries)
	{
		if(c->redrawNeeded())
		{
			for(Territory* t : c->getTerritory())
			{
				m_territoryImage->setPixel(t->getX(), t->getY(), t->getColor());
			}

			countryUpdated = true;
			c->notifyRedrawn();
		}
	}

	if(countryUpdated)
	{
		m_territoryTexture->loadFromImage(*m_territoryImage);
		m_territoryMap->setTexture(*m_territoryTexture, true);
	}
	
	return m_territoryMap;
}

void Simulator::addParticle(Particle* _particle)
{
	m_simulatedParticles.push_back(_particle);
}

Particle* Simulator::getParticleAt(int _x, int _y) const
{
	auto p = std::find_if(std::begin(m_simulatedParticles), std::end(m_simulatedParticles), [&](Particle* p) { return p->getX() == _x && p->getY() == _y; });
	if(p != m_simulatedParticles.end())
	{
		return *p;
	}

	return nullptr;
}

void Simulator::createExplosionAt(float _x, float _y)
{
	int size = Random::get(30, 500);
	m_simulatedParticles.push_back(new Explosion(static_cast<int>(_x), static_cast<int>(_y), size, 2, 35, HIGH));
}

void Simulator::createCountryAt(float _x, float _y)
{
	m_countries.push_back(new Country(m_world, _x, _y));
}