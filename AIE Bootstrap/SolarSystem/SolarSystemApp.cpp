#include "SolarSystemApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Ship.h"
#include <iostream>

SolarSystemApp::SolarSystemApp() {

}

SolarSystemApp::~SolarSystemApp() {

}

bool SolarSystemApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// Texture initialisation
	m_sunTexture = new aie::Texture("../bin/textures/SolarSystem/sun_icon.png");
	m_earthTexture = new aie::Texture("../bin/textures/SolarSystem/earth_icon.png");
	m_moonTexture = new aie::Texture("../bin/textures/SolarSystem/moon_icon.png");
	m_redTexture = new aie::Texture("../bin/textures/SolarSystem/arrowplanet.png");

	// Planet initialisation
	m_star = new Planet(m_sunTexture, 150.0f, 150.0f, "Pheonix Core");
	m_earth = new Planet(m_earthTexture, "Contraxia I", 75.0f, 75.0f, 200.0f);
	m_moon = new Planet(m_moonTexture, "Contrax Moon", 15.0f, 15.0f, 75.0f);
	m_red = new Planet(m_redTexture, "Ashen", 100.0f, 100.0f, 150.0f);

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
	delete m_star;
	delete m_earth;
	delete m_moon;
	delete m_red;

	// Texture de-allocation
	delete m_sunTexture;
	delete m_earthTexture;
	delete m_moonTexture;
	delete m_redTexture;
}

void SolarSystemApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// Planet update
	m_star->update(deltaTime, 0.25f);
	m_earth->update(deltaTime, m_star, 5.0f);
	m_moon->update(deltaTime, m_earth, 500.0f, 35.0f, 35.0f);
	m_red->update(deltaTime, m_star, 20.0f, 0.0f, 100.0f);

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
	m_star->draw(m_2dRenderer);
	m_earth->draw(m_2dRenderer);
	m_moon->draw(m_2dRenderer);
	m_red->draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_titleFont, "ORION", 460, 640);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 5, 5);

	// done drawing sprites
	m_2dRenderer->end();
}