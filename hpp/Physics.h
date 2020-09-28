#pragma once
#include "Planet.h"
#include <cmath>

namespace ps{
	double get_magnitude(Planet& p1, Planet& p2);
	double get_gravity(double mass1, double mass2, unsigned long long distance, float posx1, float posx2);
	sf::Vector2f get_gravity_v(Planet& p1,Planet& p2);
	double get_acceleration(double gravity, double mass);
	sf::Vector2f get_acceleration_v(const sf::Vector2f& gravity, double mass);
}
