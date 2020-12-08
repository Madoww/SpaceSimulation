#ifndef PlanetCreationWindow_h
#define PlanetCreationWindow_h
#include "UIWindow.h"
#include "UIInputField.h"
#include <iostream>
#include "ProgramData.h"
#include "SpaceSystem.h"

class PlanetCreationWindow : public UIWindow
{
public:
    PlanetCreationWindow()
    :UIWindow(400,600, UIWindow::Orientation::top_left), radiusInput(UIInputField::Type::Numerical), weightInput(UIInputField::Type::Numerical),createButton(30,30)
    {
		header.setText("Planet Creation");
		nameHeader.setText("Name:");
		radiusHeader.setText("Radius");
		weightHeader.setText("Weight");
		header.setPosition(10, 0);
		nameInput.setPosition(0, 100);
		createButton.addVoidListener([&]() {SpaceSystem::instance().create_planet(Planet(nameInput.getValueAsString(), radiusInput.getValueAsDouble(), weightInput.getValueAsDouble(), sf::Vector2f(0, 0), sf::Vector2f(800, 400))); });
    }
    
    void draw(sf::RenderWindow& window) override
    {
        canvas.clear(sf::Color::White);
        canvas.draw(nameInput);
		canvas.draw(radiusInput);
		canvas.draw(weightInput);
		canvas.draw(header);
		canvas.draw(createButton);
        canvas.display();
        nameInput.GatherInput(window);
		radiusInput.GatherInput(window);
		weightInput.GatherInput(window);
        
		(canvas.getTexture());
		finalRender.setTexture(canvas.getTexture());
		updateOrientation();
        window.draw(finalRender);
    }
	UIText header;
	UIText nameHeader;
	UIText radiusHeader;
	UIText weightHeader;
	UIButton createButton;
    UIInputField nameInput;
    UIInputField radiusInput;
    UIInputField weightInput;
};


#endif /* PlanetCreationWindow_h */
