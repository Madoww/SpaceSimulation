#ifndef UIWindow_h
#define UIWindow_h
#include <SFML/Graphics.hpp>
#include "UIText.h"
#include "UIButton.h"

class UIWindow : public sf::Drawable, public sf::Transformable
{
public:
    UIWindow(float width, float height);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void draw(sf::RenderWindow& window){};
protected:
    sf::RectangleShape background;
    sf::RenderTexture canvas;
	sf::Sprite finalRender;
};


#endif /* UIWindow_h */
