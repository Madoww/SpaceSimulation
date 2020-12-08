#include <stdio.h>
#include "UIWindow.h"
#include "ProgramData.h"

UIWindow::UIWindow(float width, float height, Orientation orientation)
{
    background.setSize(sf::Vector2(width,height));
    canvas.create(width, height);
	windowOrientation = orientation;

    /*circle.setRadius(20);
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin(20, 20);
    circle.setPosition(width, height);*/
}

void UIWindow::updateOrientation()
{
	finalRender.setOrigin(finalRender.getGlobalBounds().width / 2, finalRender.getGlobalBounds().height / 2);
	if (windowOrientation == Orientation::center)
	{
		finalRender.setPosition(ProgramData::window_size.x / 2, ProgramData::window_size.y / 2);
	}
	if (windowOrientation == Orientation::top_left)
	{
		finalRender.setPosition(background.getSize().x/2,background.getSize().y/2);
	}
	if (windowOrientation == Orientation::top_right)
	{
		finalRender.setPosition(ProgramData::window_size.x-background.getSize().x/2,background.getSize().y/2);
	}
}

void UIWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.blendMode = sf::BlendMultiply;
}
