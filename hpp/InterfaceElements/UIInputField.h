#ifndef UIInputField_h
#define UIInputField_h
#include "UIText.h"
#include <SFML/Graphics.hpp>

class UIInputField
{
public:
    UIInputField()
    :text("")
    {
        
    }
    void GatherInput(sf::RenderWindow& window);
    private:
    std::string value;
    UIText text;
};


#endif /* UIInputField_h */
