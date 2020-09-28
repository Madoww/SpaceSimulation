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
        window.draw(*windows[0]);
    }
    
    std::vector<UIWindow*> windows;
    
private:
    PlanetCreationWindow menu;
};

#endif /* UserInterface_h */
