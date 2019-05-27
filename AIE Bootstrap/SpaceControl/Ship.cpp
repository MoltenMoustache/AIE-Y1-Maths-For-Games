#include "Ship.h"
#include <iostream>

Ship::Ship(aie::Input* a_input, const char* a_textureDirectory, const float a_shipBoundsX, const float a_shipBoundsY) : m_input(a_input), m_shipBounds(a_shipBoundsX, a_shipBoundsY)
{
	m_shipTexture = new aie::Texture(a_textureDirectory);
	m_velocity = 0.0f;
	m_acceleration = 0.0f;
	m_globalTransform.zAxis.x += 640, m_globalTransform.zAxis.y += 360;

}


Ship::~Ship()
{

}

void Ship::update(float deltaTime)
{

	// get input, change acceleration
	if (m_input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		m_acceleration = 100.0f;
	}
	else if (m_input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_RIGHT))
	{
		m_acceleration = -100.0f;
	}
	else
	{
		m_acceleration = 0.0f;
	}

	if (m_input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_rotationSpeed = 6.3f;
	}
	else if (m_input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_rotationSpeed = -6.3f;
	}
	else
	{
		m_rotationSpeed = 0.0f;
	}

	// rotation
	Matrix3 rotationMatrix;
	rotationMatrix.setRotateZ(m_rotationSpeed);

	m_globalTransform = m_globalTransform * rotationMatrix;

	// velocity calc
	m_velocity += m_acceleration * deltaTime;

	// change pos
	if (m_velocity > 0.0f)
	{
		m_globalTransform.zAxis += m_globalTransform.yAxis * m_velocity * deltaTime;
	}
	else
	{
		m_globalTransform.zAxis += m_globalTransform.yAxis * deltaTime;
	}


}

void Ship::draw(aie::Renderer2D* a_renderer)
{
	a_renderer->drawSpriteTransformed3x3(m_shipTexture, m_globalTransform, m_shipBounds.x, m_shipBounds.y);
	a_renderer->setCameraPos(m_globalTransform.zAxis.x - 640, m_globalTransform.zAxis.y - 360);
}
