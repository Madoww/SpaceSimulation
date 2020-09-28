#ifndef PlanetCreationWindow_h
#define PlanetCreationWindow_h
#include "UIWindow.h"

class PlanetCreationWindow : public UIWindow
{
public:
    PlanetCreationWindow()
    :UIWindow(150,150)
    {
        
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        states.blendMode = sf::BlendMultiply;
        target.draw(background);
    }
};


#endif /* PlanetCreationWindow_h */
