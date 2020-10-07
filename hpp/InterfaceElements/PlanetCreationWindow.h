#ifndef PlanetCreationWindow_h
#define PlanetCreationWindow_h
#include "UIWindow.h"
#include "UIInputField.h"
#include <iostream>

class PlanetCreationWindow : public UIWindow
{
public:
    PlanetCreationWindow()
    :UIWindow(150,150), button(20,20)
    {
        
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();
        states.blendMode = sf::BlendMultiply;
        target.draw(background);
        target.draw(button,states);
    }
    
    void draw(sf::RenderWindow& window) override
    {
        canvas.clear(sf::Color::White);
        canvas.draw(button);
        canvas.display();
        input.GatherInput(window);
        
        sf::Sprite sprite(canvas.getTexture());
        window.draw(sprite);
    }
    UIButton button;
    UIInputField input;
};


#endif /* PlanetCreationWindow_h */
