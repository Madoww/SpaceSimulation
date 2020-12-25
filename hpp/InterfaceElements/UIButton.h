#ifndef UIButton_h
#define UIButton_h
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include "UIText.h"
#include "Pressable.h"

class UIButton : public sf::Drawable, public sf::Transformable, public Pressable
{
public:
    UIButton(int width, int height, const std::string& buttonText = "")
    :text(buttonText)
    {
        background.setSize(sf::Vector2f(width,height));
        background.setFillColor(sf::Color::Red);
        bounds.setPosition(getPosition());
        bounds.setSize(sf::Vector2f(width, height));
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.blendMode = sf::BlendMultiply;
        target.draw(background);
        target.draw(text);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			execute();
    }

    void OnPress() override
    {
        execute();
    }
    
    void execute() const
    {
        std::cout << "Executing a button call" << std::endl;
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
