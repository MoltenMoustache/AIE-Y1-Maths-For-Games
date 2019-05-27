#pragma once
#include "Vector2.h"

class PlaneCollider
{
public:
	PlaneCollider();
	~PlaneCollider();

	struct {
		Vector2 m_normal;
		float m_distance;
	};

	virtual void update(float deltaTime);

protected:

};

