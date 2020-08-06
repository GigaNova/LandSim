#include "Terrain.h"
#include "World.h"

Terrain::Terrain(int _width, int _height): m_width(_width), m_height(_height), m_texture(new sf::Texture()), m_terrainMap(new sf::Sprite()), m_terrainImage(new sf::Image())
{
	m_terrainImage->create(World::WINDOW_WIDTH, World::WINDOW_HEIGHT, sf::Color::White);
	for(int x = 0; x < _width; ++x)
	{
		m_particles.emplace_back(_height);
	}
}

int Terrain::getTerrainWidth() const
{
	return m_width;
}

int Terrain::getTerrainHeight() const
{
	return m_height;
}

void Terrain::addParticle(int _x, int _y, Particle* _particle)
{
	if (_x >= World::WINDOW_WIDTH || _x < 0 || _y >= World::WINDOW_HEIGHT || _y < 0)
	{
		return;
	}
	
	delete m_particles[_x][_y];
	m_particles[_x][_y] = _particle;

	m_updatedLocations.emplace_back(_x, _y);
	m_needRenderUpdate = true;
}

Particle* Terrain::getParticleAt(int _x, int _y) const
{
	if(_x >= World::WINDOW_WIDTH || _x < 0 || _y >= World::WINDOW_HEIGHT || _y < 0)
	{
		return nullptr;
	}
	return m_particles[_x][_y];
}

bool Terrain::needRenderUpdate() const
{
	return m_needRenderUpdate;
}

void Terrain::redrawTerrain()
{
	for(std::tuple<int, int> location : m_updatedLocations)
	{
		int x = std::get<0>(location);
		int y = std::get<1>(location);
		m_terrainImage->setPixel(x, y, m_particles[x][y]->getColor());
	}
	m_updatedLocations.clear();

	m_texture->loadFromImage(*m_terrainImage);
	m_terrainMap = new sf::Sprite();
	m_terrainMap->setTexture(*m_texture, true);

	m_needRenderUpdate = false;
}

sf::Sprite* Terrain::getTerrainMap() const
{
	return m_terrainMap;
}
