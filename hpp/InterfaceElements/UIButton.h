#ifndef UIButton_h
#define UIButton_h
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include "UIText.h"

class UIButton : public sf::Drawable, public sf::Transformable
{
public:
    UIButton(int width, int height)
    :text("texttext")
    {
        background.setSize(sf::Vector2f(width,height));
        background.setFillColor(sf::Color::Red);
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.blendMode = sf::BlendMultiply;
        target.draw(background);
        target.draw(text);
    }
    
    void execute() const
    {
        for(auto listener : listeners)
        {
            listener();
        }
    }
    
    void addVoidListener(const std::function<void()>& func)
    {
        listeners.push_back(func);
    }
    
private:
    sf::RectangleShape background;
    UIText text;
    std::vector<std::function<void()>> listeners;
};

#endif /* UIButton_h */
