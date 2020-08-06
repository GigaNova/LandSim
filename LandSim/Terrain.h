#pragma once
#include <vector>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Particle.h"
#include <tuple>

class Terrain
{
public:
	Terrain(int _width, int _height);

	int getTerrainWidth() const;
	int getTerrainHeight() const;

	void addParticle(int _x, int _y, Particle* _particle);
	Particle* getParticleAt(int _x, int _y) const;

	bool needRenderUpdate() const;
	void redrawTerrain();
	sf::Sprite* getTerrainMap() const;
private:
	const int m_width;
	const int m_height;

	std::vector<std::vector<Particle*>> m_particles;

	sf::Image* m_terrainImage;
	sf::Sprite* m_terrainMap;
	sf::Texture* m_texture;

	std::vector<std::tuple<int, int>> m_updatedLocations;
	
	bool m_needRenderUpdate;
};

