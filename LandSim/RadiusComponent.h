#pragma once
#include "Component.h"

class RadiusComponent : public Component
{
public:
	RadiusComponent(int _radius);

	int getRadius() const;
	void setRadius(int _radius);

private:
	int m_radius;
};

