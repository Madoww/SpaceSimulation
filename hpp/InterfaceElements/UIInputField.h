#ifndef UIInputField_h
#define UIInputField_h
#include "UIText.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class UIInputField : public sf::Drawable, public sf::Transformable
{
public:
	enum Type
	{
		Text,
		Numerical
	};

    UIInputField(Type type = Type::Text)
    {
		this->type = type;
    }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(text, states);
	}

    void GatherInput(sf::RenderWindow& window);

	const std::string& getValueAsString() { return text.getValue(); }
	double getValueAsDouble() { return std::atof(text.getValue().c_str()); }
    private:
    UIText text;
	Type type;
};


#endif /* UIInputField_h */
