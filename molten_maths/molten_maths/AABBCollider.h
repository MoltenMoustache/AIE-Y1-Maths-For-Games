#pragma once
#include "Vector2.h"

class AABBCollider : CollisionShape
{
public:
	AABBCollider();
	~AABBCollider();
	struct {
		Vector2 m_position;
		Vector2 m_extents;
	};

	virtual void update(float deltaTime);

protected:

};

