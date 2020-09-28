#include "Physics.h"
#include <iostream>

namespace ps {

	const double G = 6.6740831*pow(10, -11);

    double get_magnitude(Planet& p1, Planet& p2)
    {
        return sqrt(pow((p2.getPosition().x - p1.getPosition().x),2) + pow((p2.getPosition().y - p1.getPosition().y),2));
    }

	double get_gravity(double mass1, double mass2, unsigned long long distance, float posx1, float posx2)
	{
        sf::Vector2f vec1(3,4);
		if (posx1 < posx2)
			return G * ((mass1*mass2) / (distance*distance));
		else
			return -G * ((mass1*mass2) / (distance*distance));
	}
	
	sf::Vector2f get_gravity_v(Planet& p1,Planet& p2)
	{
		//std::cout << sf::Vector2f((p2.getPosition() - p1.getPosition()) * ((G*p2.get_mass()*p1.get_mass()) / pow(get_magnitude(p1, p2), 3))).y << std::endl;
		return (p2.getPosition() - p1.getPosition()) * ((G*p2.get_mass()*p1.get_mass()) / pow(get_magnitude(p1, p2),3));
	}

	double get_acceleration(double gravity, double mass)
	{
		//std::cout << gravity / mass << std::endl;
		return gravity / mass;
	}

	sf::Vector2f get_acceleration_v(const sf::Vector2f& gravity, double mass)
	{
		//std::cout << (gravity / mass).y << std::endl;
		return gravity / mass;
	}
}
