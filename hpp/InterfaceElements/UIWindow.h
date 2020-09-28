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
protected:
    sf::RectangleShape background;
};


#endif /* UIWindow_h */
