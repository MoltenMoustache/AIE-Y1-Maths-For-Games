#include "SolarSystemApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

SolarSystemApp::SolarSystemApp() {

}

SolarSystemApp::~SolarSystemApp() {

}

bool SolarSystemApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// Texture initialisation
	m_sunTexture = new aie::Texture("../bin/textures/SolarSystem/sun_icon.png");
	m_mercuryTexture = new aie::Texture("../bin/textures/SolarSystem/mercury.png");
	m_venusTexture = new aie::Texture("../bin/textures/SolarSystem/venus.png");
	m_earthTexture = new aie::Texture("../bin/textures/SolarSystem/earth_icon.png");
	m_moonTexture = new aie::Texture("../bin/textures/SolarSystem/moon_icon.png");
	m_marsTexture = new aie::Texture("../bin/textures/SolarSystem/mars.png");
	m_jupiterTexture = new aie::Texture("../bin/textures/SolarSystem/jupiter.png");

	// Planet initialisation
	m_sun = new Planet(m_sunTexture, 150.0f, "The Sun");
	m_mercury = new Planet(m_mercuryTexture, "Mercury", 10.0f, 0.0f, 80.0f);
	m_venus = new Planet(m_venusTexture, "Venus", 20.0f, 110.0f, 0.0f);
	m_earth = new Planet(m_earthTexture, "Earth", 25.0f, 150.0f);
	m_moon = new Planet(m_moonTexture, "Earth's Moon", 7.0f, 20.0f);
	m_mars = new Planet(m_marsTexture, "Mars", 18.0f, 200.0f);
	m_jupiter = new Planet(m_jupiterTexture, "Jupiter", 55.0f, 200.0f);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/moonhouse.ttf", 32);
	m_titleFont = new aie::Font("../bin/font/moonhouse.ttf", 80);

	return true;
}

void SolarSystemApp::shutdown() {

	delete m_font;
	delete m_titleFont;

	delete m_2dRenderer;
	
	// Planet de-allocation
	delete m_sun;
	delete m_mercury;
	delete m_venus;
	delete m_earth;
	delete m_moon;
	delete m_mars;
	delete m_jupiter;

	// Texture de-allocation
	delete m_sunTexture;
	delete m_mercuryTexture;
	delete m_venusTexture;
	delete m_earthTexture;
	delete m_moonTexture;
	delete m_marsTexture;
	delete m_jupiterTexture;
}

void SolarSystemApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// Planet update
	m_sun->update(deltaTime, 0.25f);
	m_earth->update(deltaTime, 1.0f, m_sun);
	m_mercury->update(deltaTime, 1.0f, m_sun, 0.10f);
	m_venus->update(deltaTime, 1.0f, m_sun);
	m_moon->update(deltaTime, 2.0f, m_earth, 0.5f);
	m_mars->update(deltaTime, 3.0f, m_sun, 0.15f);
	m_jupiter->update(deltaTime, 0.75f, m_sun, 0.15f);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void SolarSystemApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	
	// Planet drawing
	m_sun->draw(m_2dRenderer);
	m_mercury->draw(m_2dRenderer);
	m_venus->draw(m_2dRenderer);
	m_earth->draw(m_2dRenderer);
	m_moon->draw(m_2dRenderer);
	m_mars->draw(m_2dRenderer);
	m_jupiter->draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_titleFont, "ORION", 460, 640);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 5, 5);

	// done drawing sprites
	m_2dRenderer->end();
}