#include <SFML/Graphics.hpp>
#include "app.h"

int main()
{
	app& sim = app::instance();
	sim.run();

	return 0;
}