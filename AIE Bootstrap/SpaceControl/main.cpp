#include "SpaceControlApp.h"

int main() {
	
	// allocation
	auto app = new SpaceControlApp();

	// initialise and loop
	app->run("Space Control", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}