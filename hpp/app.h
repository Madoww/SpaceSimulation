#pragma once
#include <SFML/Graphics.hpp>
#include "SpaceSystem.h"
#include "UserInterface.h"
#include <iostream>

class app
{
public:
	app(const app&) = delete;
	app operator=(const app&) = delete;
	inline static app& instance()
	{
		static app instance;
		return instance;
	}
	void run();
    sf::Event event;
    sf::RenderWindow& getWindow(){ return m_window; }
private:
	app();
	~app()=default;
	UserInterface& interface = UserInterface::instance();
	SpaceSystem& space = SpaceSystem::instance();
	sf::RenderWindow m_window;
	sf::View view;
};
