#ifndef UIButton_h
#define UIButton_h
#include <SFML/Graphics.hpp>

class UIButton : public sf::Drawable, public sf::Transformable
{
public:
    UIButton(int width, int height)
    {
        background.setSize(sf::Vector2f(width,height));
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.blendMode = sf::BlendMultiply;
    }
private:
    sf::RectangleShape background;
};

#endif /* UIButton_h */
