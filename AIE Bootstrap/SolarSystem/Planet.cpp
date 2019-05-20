#include "Planet.h"
#include "Texture.h"
#include "Font.h"

// Constructor takes 3 parameters, the texture of the planet and the size of the planet (in X / Y)
Planet::Planet(aie::Texture* a_planetTexture, float a_sizeX, float a_sizeY, const char* a_name) : m_planetTexture(a_planetTexture), m_planetSizeX(a_sizeX), m_planetSizeY(a_sizeY), m_name(a_name)
{
	m_planetFont = new aie::Font("../bin/font/moonhouse.ttf", 32 - ((100 / a_sizeX) + (100 / a_sizeY)));
	m_planetMatrix.zAxis = Vector3(600.0f, 400.0f, 1.0f);
}

Planet::Planet(aie::Texture* a_planetTexture, const char* a_name, float a_sizeX, float a_sizeY, float a_xOffset, float a_yOffset) : m_planetTexture(a_planetTexture), m_planetSizeX(a_sizeX), m_planetSizeY(a_sizeY), m_name(a_name)
{
	m_planetFont = new aie::Font("../bin/font/moonhouse.ttf", 32 - ((100 / a_sizeX) + (100 / a_sizeY)));
	m_planetMatrix.zAxis = Vector3(600.0f, 400.0f, 1.0f);
	m_planetLocalMatrix.zAxis = Vector3(a_xOffset, a_yOffset, 1.0f);

	m_planetMatrix = m_planetMatrix * m_planetLocalMatrix;
}


Planet::~Planet()
{
	delete m_planetFont;
}

void Planet::draw(aie::Renderer2D* a_renderer) {

	// Draws the planet onto the screen
	a_renderer->drawSpriteTransformed3x3(m_planetTexture, m_planetMatrix, m_planetSizeX, m_planetSizeX);
	// draws planet name
	a_renderer->drawText(m_planetFont, m_name, m_planetMatrix.zAxis.x, m_planetMatrix.zAxis.y);

}

// Update function is called every frame
// Takes in delta time, a rotation scalar,
// a true or false for if it is orbiting
// if it is orbiting, it takes the orbited planet and the offset values (x and y)
void Planet::update(float deltaTime, float a_rotationScalar) {

	Matrix3 m_rotationMatrix;
	float orbitSpeed = 3.14159f * 0.5f;

	// Sets the center of the object to the center of the screen

	// Rotates the planet
	m_rotationMatrix.setRotateZ(deltaTime * a_rotationScalar);
	m_planetLocalMatrix = m_planetLocalMatrix * m_rotationMatrix;
}

void Planet::update(float deltaTime, Planet* a_pointOfOrbit, float a_rotationScalar, float a_offsetX, float a_offsetY) {

	Matrix3 m_rotationMatrix;
	float orbitSpeed = 3.14159f * 0.25f;

	// Sets the center of the object to the center of the screen

	// Rotates the planet
	m_rotationMatrix.setRotateZ(deltaTime * a_rotationScalar);
	m_planetLocalMatrix = m_planetLocalMatrix * m_rotationMatrix;


	// Orbit the planet
	m_rotationMatrix.setRotateZ(deltaTime * orbitSpeed);
	m_planetLocalMatrix = m_rotationMatrix * m_planetLocalMatrix;


	// multiplies local matrix by the matrix of the parent planet
	m_planetMatrix = a_pointOfOrbit->m_planetMatrix * m_planetLocalMatrix;
}


