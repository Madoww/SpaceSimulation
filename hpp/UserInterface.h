#ifndef UserInterface_h
#define UserInterface_h
#include "PlanetCreationWindow.h"
#include <vector>
#include <algorithm>

class UserInterface
{
public:
    UserInterface();
    UserInterface(const UserInterface&) = delete;
    UserInterface operator=(const UserInterface&) = delete;
    inline static UserInterface& instance()
    {
        static UserInterface temp;
        return temp;
    }
    void Update()
    {
        
    }
    void Draw(sf::RenderWindow& window)
    {
        //window.draw(*windows[0]);
        windows[0]->draw(window);
    }
    
    std::vector<UIWindow*> windows;
};

#endif /* UserInterface_h */
