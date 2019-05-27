#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"
#include "Ship.h"

class SpaceControlApp : public aie::Application {
public:

	SpaceControlApp();
	virtual ~SpaceControlApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	// Main Menu buttons
	Button* m_playButton;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Input*			input;
	Ship*				m_playerShip;

	enum GameState {
		MENU,
		PLAY,
		PAUSE,
		GAMEOVER,
	};
	GameState gameState;
};
