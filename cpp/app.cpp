#include "app.h"
#include "math.h"
#include "ProgramData.h"

app::app()
	:m_window(sf::VideoMode(1280, 720, 32), "Space Simulation", sf::Style::Close),view(sf::Vector2f(800,400),sf::Vector2f(1600,900))
{
		m_window.setView(view);
		view.zoom(999999);
	m_window.setVerticalSyncEnabled(true);
	ProgramData::window_size = m_window.getSize();
}

void app::run()
{
	while (m_window.isOpen())
	{
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
        SpaceSystem::instance().update(500);
        m_window.setView(m_window.getDefaultView());
		interface.Draw(m_window);
		m_window.display();
        event.type = sf::Event::EventType::SensorChanged;
	}
}
