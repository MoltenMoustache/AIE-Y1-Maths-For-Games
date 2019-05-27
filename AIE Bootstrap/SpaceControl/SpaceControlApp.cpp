#include "SpaceControlApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

SpaceControlApp::SpaceControlApp() {

}

SpaceControlApp::~SpaceControlApp() {

}

bool SpaceControlApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	input = aie::Input::getInstance();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);


	// Main Menu buttons
	m_playButton = new Button("PLAY", 640, 500, 100, 60, 32, "../bin/font/consolas.ttf");


	// Play State initialisation
	m_playerShip = new Ship(input, "../bin/textures/ship.png", 40.0f, 40.0f);
	// plabets

	// Initialises game state
	gameState = GameState::MENU;


	return true;
}

void SpaceControlApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void SpaceControlApp::update(float deltaTime) {

	// input example

	if (gameState == GameState::MENU) {
		
		if (m_playButton->isPressed()) {
			gameState = GameState::PLAY;
		}

	}

	if (gameState == GameState::PLAY) {

		m_playerShip->update(deltaTime);

	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void SpaceControlApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Main Menu
	if (gameState == GameState::MENU)
	{
		m_playButton->draw(m_2dRenderer, 1.0f, 1.0f, 1.0f, 4);
	}

	// Gameplay
	if (gameState == GameState::PLAY)
	{
		m_playerShip->draw(m_2dRenderer);
	}

	// Game Over
	if (gameState == GameState::GAMEOVER)
	{

	}
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}