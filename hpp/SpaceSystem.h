#pragma once
#include <vector>
#include "Planet.h"

class SpaceSystem
{
public:
	SpaceSystem(const SpaceSystem&) = delete;
	SpaceSystem operator=(const SpaceSystem&) = delete;

	inline static SpaceSystem& instance()
	{
		static SpaceSystem instance;
		return instance;
	}

	void create_planet(Planet);

	void draw(sf::RenderWindow&);

    void update(const int updatesToPerform = 1);
private:
	
	SpaceSystem();
	~SpaceSystem() = default;

	std::vector<Planet> planets;
};
