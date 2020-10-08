#include <SFML/Graphics.hpp>
#include "app.h"

int main()
{
	app& sim = app::instance();

	SpaceSystem& space = SpaceSystem::instance();

	space.create_planet(Planet("Earth", 6371000, 5.972*pow(10, 25), sf::Vector2f(800, 450), sf::Vector2f(0, 0), sf::Color::Blue));
	space.create_planet(Planet("Moon", 1737000, 7.34767309*pow(10, 22), sf::Vector2f(400, 450 + 384402000), sf::Vector2f(1023.056, 0)));

	sim.run();

	return 0;
}