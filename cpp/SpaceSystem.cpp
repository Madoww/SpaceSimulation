#include "SpaceSystem.h"
#include <iostream>
#include "Physics.h"
#include "app.h"

SpaceSystem::SpaceSystem()
{

}

void SpaceSystem::create_planet(Planet planet)
{
	planets.emplace_back(planet);
}

void SpaceSystem::update(const int updatesToPerform)
{
    for(int update = 0; update<updatesToPerform; update++)
    {
        for(int i = 0; i<planets.size(); i++)
        {
            for (int j = 0; j < planets.size(); j++)
            {
                if (i != j)
                {
                    planets[i].accelerate(ps::get_acceleration_v(ps::get_gravity_v(planets[i], planets[j]), planets[i].get_mass()));
                }
            }
            planets[i].move();
        }
        //sf::Vector2i pixelPos = sf::Mouse::getPosition(app::instance().getWindow());
        //sf::Vector2f worldPos = app::instance().getWindow().mapPixelToCoords(pixelPos);
        //planets[0].setPosition(worldPos);
    }
}

void SpaceSystem::draw(sf::RenderWindow& window)
{
	for (auto& planet : planets)
	{
		planet.draw(window);
	}
}
