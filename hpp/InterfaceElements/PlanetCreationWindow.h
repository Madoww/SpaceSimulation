#ifndef PlanetCreationWindow_h
#define PlanetCreationWindow_h
#include "UIWindow.h"
#include "UIInputField.h"
#include <iostream>

class PlanetCreationWindow : public UIWindow
{
public:
    PlanetCreationWindow()
    :UIWindow(150,150)
    {
        
    }
    
    void draw(sf::RenderWindow& window) override
    {
        canvas.clear(sf::Color::White);
        canvas.draw(input);
        canvas.display();
        input.GatherInput(window);
        
		(canvas.getTexture());
		finalRender.setTexture(canvas.getTexture());
        window.draw(finalRender);
    }
    UIInputField input;
};


#endif /* PlanetCreationWindow_h */
