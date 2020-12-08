#include "Planet.h"
#include <iostream>

Planet::Planet(const std::string& name, const double radius, double mass, const sf::Vector2f& position, const sf::Vector2f& initial_speed_v, const sf::Color color)
	:name(name),radius(radius),mass(mass),speed(initial_speed_v)
{
	sphere.setRadius(radius);
	sphere.setOrigin(radius, radius);
	sphere.setFillColor(color);
	sphere.setPosition(position);
	std::cout << "Planet created: " << name << std::endl;
}

void Planet::draw(sf::RenderWindow& window)
{
	window.draw(sphere);
}

void Planet::accelerate(const sf::Vector2f& acceleration)
{
	speed += acceleration;
}
