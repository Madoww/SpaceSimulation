#include "Pressable.h"
#include "app.h"

Pressable::Pressable()
{
	PressablesManager::pressables.emplace_back(this);
}

bool Pressable::CheckIfPressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (wasCalled)
			return false;
		if (sf::Mouse::getPosition(app::instance().getWindow()).x > bounds.getPosition().x && sf::Mouse::getPosition(app::instance().getWindow()).x < bounds.getPosition().x + bounds.getSize().x)
		{
			if (sf::Mouse::getPosition(app::instance().getWindow()).y > bounds.getPosition().y && sf::Mouse::getPosition(app::instance().getWindow()).y < bounds.getPosition().y + bounds.getSize().y)
			{
				OnPress();
				wasCalled = true;
				return true;
			}
		}
	}
	else if (wasCalled)
	{
		wasCalled = false;
		std::cout << "Was called is now false" << std::endl;
	}
	return false;
}

bool PressablesManager::CheckIfAnyPressed()
{
	for (auto pressable : pressables)
	{
		if (pressable->CheckIfPressed())
		{
			return true;
		}
	}
}

std::vector<Pressable*> PressablesManager::pressables;