#pragma once
#include "Vector2.h"
class CircleCollider
{
public:
	CircleCollider();
	~CircleCollider();
	struct {
		Vector2 m_position;
		float m_radius;
	};

	virtual void update(float deltaTime);

protected:

};

