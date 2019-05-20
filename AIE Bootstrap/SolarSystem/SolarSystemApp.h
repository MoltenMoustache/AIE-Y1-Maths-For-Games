#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Planet.h"

class SolarSystemApp : public aie::Application {
public:

	SolarSystemApp();
	virtual ~SolarSystemApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	
	aie::Font*			m_font;
	aie::Font*			m_titleFont;

	aie::Texture*		m_sunTexture;
	aie::Texture*		m_earthTexture;
	aie::Texture*		m_moonTexture;
	aie::Texture*		m_redTexture;

	Planet* m_star;
	Planet* m_earth;
	Planet* m_moon;
	Planet* m_red;
};