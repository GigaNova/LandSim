#pragma once
#include <vector>
#include <SFML/Graphics/Color.hpp>

#include "Territory.h"

class World;
class Country
{
public:
	static const int STANDARD_EXPANSION_ITERATION = 50;
	
	Country(World* _world, int _originX, int _originY);

	sf::Color getColor() const;

	void addTerritory(int _x, int _y);
	const std::vector<Territory*>& getTerritory() const;

	bool redrawNeeded() const;
	void notifyRedrawn();

private:
	void generateColor();
	void expandTerritory();
	void generateCountryCenter(int _x, int _y);

	World* m_world;
	sf::Color m_countryColor;

	std::vector<Territory*> m_territory;

	bool m_redrawNeeded;
};

