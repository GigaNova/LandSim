#pragma once
#include "Component.h"
#include <utility>
#include <string>

class PositionComponent : public Component
{
public:
	PositionComponent(float _x, float _y);

	std::pair<float, float> getPosition() const;
	void setPosition(float _x, float _y);

private:
	float m_x;
	float m_y;
};

