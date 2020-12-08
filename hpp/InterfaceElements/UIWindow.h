#ifndef UIWindow_h
#define UIWindow_h
#include <SFML/Graphics.hpp>
#include "UIText.h"
#include "UIButton.h"


class UIWindow : public sf::Drawable, public sf::Transformable
{
public:
	enum Orientation
	{
		top_right,
		center,
		top_left
	};

    UIWindow(float width, float height, Orientation orientation = Orientation::center);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void draw(sf::RenderWindow& window){};
	virtual void updateOrientation();

protected:
	Orientation windowOrientation;
    sf::RectangleShape background;
    sf::RenderTexture canvas;
	sf::Sprite finalRender;
};


#endif /* UIWindow_h */
