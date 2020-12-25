#include <stdio.h>
#include <cctype>
#include "UIInputField.h"
#include "app.h"

void UIInputField::GatherInput(sf::RenderWindow& window)
{
	if(is_active)
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

void UIInputField::OnPress()
{
	InputFieldsManager::Reset();
	SetActive(true);
}

std::vector<UIInputField*> InputFieldsManager::fields;

UIInputField::UIInputField(Type type)
{
	this->type = type;
	InputFieldsManager::fields.push_back(this);
}
