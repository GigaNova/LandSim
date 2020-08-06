#pragma once
#include <SFML/Graphics/Color.hpp>

static float clamp(float _n, float _lower, float _upper) {
	return std::max(_lower, std::min(_n, _upper));
}

static sf::Color interpolateColors(sf::Color _target, sf::Color _current, float _rate)
{
	_rate = clamp(_rate, 0.f, 1.0f);
	
	sf::Color newColor;
	newColor.r = (_target.r - _current.r) * _rate + _current.r;
	newColor.g = (_target.g - _current.g) * _rate + _current.g;
	newColor.b = (_target.b - _current.b) * _rate + _current.b;
	return newColor;
}
