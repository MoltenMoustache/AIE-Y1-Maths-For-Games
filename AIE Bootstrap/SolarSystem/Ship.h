#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Matrix3.h"

class Ship
{
public:
	Ship();
	~Ship();
	Matrix3 m_shipMatrix;
	void draw(aie::Renderer2D* a_renderer);
	
protected:

	aie::Texture*	m_shipTexture;
};

