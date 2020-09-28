#include "app.h"
#include "math.h"

app::app()
	:m_window(sf::VideoMode(1280, 720, 32), "Space Simulation", sf::Style::Close),view(sf::Vector2f(800,400),sf::Vector2f(1600,900))
{
	space.create_planet(Planet("Earth",6371000, 5.972*pow(10,25), sf::Vector2f(800, 450),sf::Vector2f(0,0),sf::Color::Blue));
	space.create_planet(Planet("Moon",1737000, 7.34767309*pow(10,22), sf::Vector2f(400, 450+ 384402000), sf::Vector2f(1023.056, 0)));
		m_window.setView(view);
		view.zoom(999999);
	m_window.setVerticalSyncEnabled(true);
}

void app::run()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta > 0)
					view.zoom(0.99);
				if (event.mouseWheelScroll.delta < 0)
					view.zoom(1.01);
			}
		}

		m_window.setView(view);
		m_window.clear();
		space.draw(m_window);
        SpaceSystem::instance().update(1000);
        m_window.setView(m_window.getDefaultView());
        interface.Draw(m_window);
		m_window.display();
	}
}