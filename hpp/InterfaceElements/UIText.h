#ifndef UIText_h
#define UIText_h
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fonts.h"


class UIText : public sf::Drawable, public sf::Transformable
{
public:
	UIText()
	{
		text.setFont(Fonts::Instance().default_font);
		text.setCharacterSize(40);
		text.setFillColor(sf::Color::Blue);
	}
    UIText(std::string value)
    :value(value)
    {
		UIText();
		setText(value);
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(text,states);
    }

	void setText(const std::string& newValue)
	{
		value = newValue;
		text.setString(value);
	}

	sf::Vector2f getSize()
	{
		return sf::Vector2f(text.getGlobalBounds().width, text.getGlobalBounds().height);
	}

	void append(const char addedValue)
	{
		value += addedValue;
		text.setString(value);
	}

	void erase()
	{
		value.pop_back();
		text.setString(value);
	}
    
	const std::string& getValue() { return value; }
private:
    sf::Text text;
    std::string value;
};

#endif /* UIText_h */
