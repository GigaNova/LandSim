#include "WorldGenerator.h"
#include <iostream>
#include "Grass.h"
#include "Ocean.h"
#include "Sand.h"
#include "World.h"
#include "FastNoiseSIMD/FastNoise.h"
#include "FastNoiseSIMD/FastNoise.cpp"

WorldGenerator::WorldGenerator()
{
}

WorldGenerator::~WorldGenerator()
{
}

Terrain* WorldGenerator::generateWorld(int _width, int _height)
{
	FastNoise fastNoise;
	fastNoise.SetSeed(time(nullptr));
	fastNoise.SetNoiseType(FastNoise::SimplexFractal);
	fastNoise.SetFractalOctaves(8);
	
	Terrain* terrain = new Terrain(_width, _height);
	std::vector<std::vector<float>> squareGradient = radGrad(_width, _height);
	
	for (int x = 0; x < World::WINDOW_WIDTH; ++x) {
		for (int y = 0; y < World::WINDOW_HEIGHT; ++y) {

			float noise = (fastNoise.GetNoise(x, y) * 10) - squareGradient[x][y];
			//On land
			if (noise > 0) {

				if(noise < 1.5)
				{
					terrain->addParticle(x, y, new Sand(x, y));
				}
				else
				{
					terrain->addParticle(x, y, new Grass(x, y));
				}
			}
			//Ocean
			else
			{
				terrain->addParticle(x, y, new Ocean(x, y));
			}
		}
	}

	return terrain;
}

std::vector<std::vector<float>> WorldGenerator::radGrad(int _width, int _height) const {
	std::vector<std::vector<float>> grad;
	float cX = _width * 0.5f;
	float cY = _height * 0.5f;
	float maxDist = distance(cX, cY, _width, _height);

	for (int x = 0; x < _width; ++x) {
		grad.emplace_back(_height);
		for (int y = 0; y < _height; ++y) {
			float distFromCenterNormalized = std::min(distance(cX, cY, x, y) / maxDist, 1.f);
			float pixel = fLerp(distFromCenterNormalized, -4, 10);
			grad[x][y] = pixel;
		}
	}

	return grad;
}

float WorldGenerator::fLerp(float _norm, float _min, float _max) const {
	return (_max - _min) * _norm + _min;
}

float WorldGenerator::distance(float _x1, float _y1, float _x2, float _y2) const {
	return static_cast<float>(sqrt(pow(abs(_x1 - _x2), 2) + pow(abs(_y1 - _y2), 2)));
}