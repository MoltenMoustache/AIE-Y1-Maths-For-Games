#pragma once
class CollisionShape
{
public:
	CollisionShape();
	~CollisionShape();

	virtual void draw();
	virtual void update(float deltaTime);

protected:

};

