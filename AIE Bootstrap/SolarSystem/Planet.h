#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"

class Planet
{
public:
	Planet(aie::Texture* a_planetTexture, float a_size = 100.0f,  const char* a_name = "Planet");
	Planet(aie::Texture* a_planetTexture, const char* a_name = "Planet", float a_size = 100.0f, float a_xOffset = 0.0f, float a_yOffset = 0.0f);
	~Planet();

	virtual void update(float deltaTime, float a_rotationScalar = 25.0f);
	virtual void update(float deltaTime, float a_rotationScalar, Planet* a_pointOfOrbit, float a_orbitSpeed = 0.25f);
	virtual void draw(aie::Renderer2D* a_renderer);

	Matrix3 m_planetMatrix;
	Matrix3 m_planetLocalMatrix;

protected:

	aie::Texture* m_planetTexture;
	aie::Font* m_planetFont;
	float m_planetSize;
	const char* m_name;
};

