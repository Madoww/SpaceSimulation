#include <stdio.h>
#include "UIWindow.h"

UIWindow::UIWindow(float width, float height)
{
    background.setSize(sf::Vector2(width,height));
    /*circle.setRadius(20);
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin(20, 20);
    circle.setPosition(width, height);*/
}

void UIWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.blendMode = sf::BlendMultiply;
    /*target.draw(background);
    target.draw(circle,states);*/
}
