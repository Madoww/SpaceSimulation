#include <stdio.h>
#include "UIInputField.h"
#include "app.h"

void UIInputField::GatherInput(sf::RenderWindow& window)
{
    if(app::instance().event.type == sf::Event::TextEntered)
    {
        std::cout<<app::instance().event.text.unicode<<std::endl;
    }
}

