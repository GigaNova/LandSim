#pragma once
#include "Component.h"
#include <utility>

class VelocityComponent : public Component
{
public:
	VelocityComponent(float _x, float _y);

	std::pair<float, float> getVelocity() const;
	void setVelocity(float _x, float _y);

private:
	float m_x;
	float m_y;
};

