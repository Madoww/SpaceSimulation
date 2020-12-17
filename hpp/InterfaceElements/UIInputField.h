#ifndef UIInputField_h
#define UIInputField_h
#include "UIText.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>

static class InputFieldsManager;

class UIInputField : public sf::Drawable, public sf::Transformable
{
public:
	enum Type
	{
		Text,
		Numerical
	};

	UIInputField(Type type = Type::Text);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(text, states);
	}

	void SetBounds(const sf::Vector2f& position, const sf::Vector2f& size)
	{
		bounds.setPosition(position);
		bounds.setSize(size);
	}

	void SetActive(bool input)
	{
		is_active = input;
	}

    void GatherInput(sf::RenderWindow& window);

	const std::string& getValueAsString() { return text.getValue(); }
	double getValueAsDouble() { return std::atof(text.getValue().c_str()); }
    private:
	sf::RectangleShape bounds;
    UIText text;
	Type type;
	bool is_active = false;
};

static class InputFieldsManager
{
public:
	static std::vector<UIInputField*> fields;

	static void Reset()
	{
		for (auto field : fields)
		{
			field->SetActive(false);
		}
	}
};



#endif /* UIInputField_h */
