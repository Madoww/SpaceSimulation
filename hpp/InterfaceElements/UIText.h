#ifndef UIText_h
#define UIText_h
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class UIText : public sf::Drawable, public sf::Transformable
{
public:
    UIText(std::string value)
    :value(value)
    {
        std::cout<<"String created: "<<value<<std::endl;
        text.setFont(Fonts::Instance().default_font);
        text.setString(value);
        text.setCharacterSize(40);
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(text,states);
    }
    
private:
    sf::Text text;
    std::string value;
};

#endif /* UIText_h */
