#include <stdio.h>
#include <cctype>
#include "UIInputField.h"
#include "app.h"

void UIInputField::GatherInput(sf::RenderWindow& window)
{
    if(app::instance().event.type == sf::Event::TextEntered)
    {
		if (app::instance().event.text.unicode == '\b')
		{
			text.erase();
			return;
		}
		if (type == Type::Numerical) 
		{
			if (!isdigit((char)app::instance().event.text.unicode))
			{
				return;
			}
		}
		text.append(app::instance().event.text.unicode);
    }
}

