#include "Country.h"
#include <random/random.hpp>

#include "World.h"

using Random = effolkronium::random_static;

Country::Country(World* _world, int _originX, int _originY) : m_world(_world), m_redrawNeeded(true)
{
	generateColor();
	generateCountryCenter(_originX, _originY);
}

void Country::generateColor()
{
	m_countryColor.r = Random::get(50, 255);
	m_countryColor.g = Random::get(50, 255);
	m_countryColor.b = Random::get(50, 255);
}

void Country::generateCountryCenter(int _x, int _y)
{
	addTerritory(_x, _y);

	for (int i = 0; i < STANDARD_EXPANSION_ITERATION; ++i)
	{
		expandTerritory();
	}
}

sf::Color Country::getColor() const
{
	return m_countryColor;
}

void Country::addTerritory(int _x, int _y)
{
	m_territory.push_back(new Territory(_x, _y, this));
}

const std::vector<Territory*>& Country::getTerritory() const
{
	return m_territory;
}

bool Country::redrawNeeded() const
{
	return m_redrawNeeded;
}

void Country::notifyRedrawn()
{
	m_redrawNeeded = false;
}

void Country::expandTerritory()
{
	int size = m_territory.size();
	for(int i = 0; i < size; ++i)
	{
		Territory* t = m_territory[i];
		t->expandIfPossible(m_world);
	}
}

