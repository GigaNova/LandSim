#pragma once
#include <vector>
#include "Particle.h"
#include "Terrain.h"

class WorldGenerator
{
public:
	WorldGenerator();
	~WorldGenerator();

	Terrain* generateWorld(int _width, int _height);

private:
	std::vector<std::vector<float>> radGrad(int _width, int _height) const;
	float fLerp(float _norm, float _min, float _max) const;
	float distance(float _x1, float _y1, float _x2, float _y2) const;
};

