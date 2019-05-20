#include "Ship.h"
#include "SolarSystemApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Ship.h"

Ship::Ship()
{
	m_shipTexture = new aie::Texture("../bin/textures/ship.png");
}


Ship::~Ship()
{
}

void Ship::draw(aie::Renderer2D* a_renderer) {

	a_renderer->drawSpriteTransformed3x3(m_shipTexture, m_shipMatrix, 200.0f, 200.0f);

}
