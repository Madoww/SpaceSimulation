#ifndef UIInputField_h
#define UIInputField_h
#include "UIText.h"
#include <SFML/Graphics.hpp>

class UIInputField : public sf::Drawable, public sf::Transformable
{
public:
    UIInputField()
    :text("")
    {
        
    }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(text, states);
	}

    void GatherInput(sf::RenderWindow& window);
    private:
    UIText text;
};


#endif /* UIInputField_h */
