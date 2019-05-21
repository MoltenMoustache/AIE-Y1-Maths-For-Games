#include "SolarSystemApp.h"
#include "Vector2.h"
#include <iostream>

int main() {
	
	Vector2 vecTest(5, 10);
	std::cout << vecTest.x << std::endl;

	// allocation
	auto app = new SolarSystemApp();

	// initialise and loop
	app->run("The Solar System", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}