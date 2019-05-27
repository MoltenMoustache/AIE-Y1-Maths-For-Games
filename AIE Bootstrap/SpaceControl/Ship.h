#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "Planet.h"
#include "Input.h"
#include "Texture.h"

class Ship
{
public:
	Ship(aie::Input* a_input, const char* a_textureDirectory, float a_shipBoundsX, float a_shipBoundsY);
	~Ship();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* a_renderer);

protected:

	aie::Texture* m_shipTexture;
	aie::Input* m_input;
	Vector2 m_shipBounds;

	float m_velocity;
	float m_acceleration;
	float m_rotationSpeed;
	Matrix3 m_globalTransform;
	Matrix3 m_localTransform;

	Planet* m_orbitedPlanet;
};

