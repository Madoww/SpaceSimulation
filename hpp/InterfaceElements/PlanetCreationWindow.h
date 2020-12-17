#ifndef PlanetCreationWindow_h
#define PlanetCreationWindow_h
#include "UIWindow.h"
#include "UIInputField.h"
#include <iostream>
#include "ProgramData.h"
#include "SpaceSystem.h"
#include <SFML/Graphics.hpp>

class PlanetCreationWindow : public UIWindow
{
public:
    PlanetCreationWindow()
    :UIWindow(400,600, UIWindow::Orientation::top_left), radiusInput(UIInputField::Type::Numerical), weightInput(UIInputField::Type::Numerical),createButton(30,30)
    {
		header.setText("Planet Creation");
		nameHeader.setText("Name:");
		nameHeader.setPosition(0, 100);
		nameInput.setPosition(nameHeader.getPosition().x + nameHeader.getSize().x + 10, nameHeader.getPosition().y);
		nameInput.SetBounds(nameHeader.getPosition(), sf::Vector2f(300, 40));
		

		radiusHeader.setText("Radius:");
		radiusHeader.setPosition(0, 200);
		radiusInput.setPosition(radiusHeader.getPosition().x + radiusHeader.getSize().x + 10, radiusHeader.getPosition().y);
		radiusInput.SetBounds(radiusHeader.getPosition(), sf::Vector2f(300, 40));

		weightHeader.setText("Weight");
		weightHeader.setPosition(0, 300);
		weightInput.setPosition(weightHeader.getPosition().x + weightHeader.getSize().x + 10, weightHeader.getPosition().y);
		weightInput.SetBounds(weightHeader.getPosition(), sf::Vector2f(300, 40));



		header.setPosition(10, 0);
		createButton.addVoidListener([&]() {SpaceSystem::instance().create_planet(Planet(nameInput.getValueAsString(), radiusInput.getValueAsDouble(), weightInput.getValueAsDouble(), sf::Vector2f(0, 0), sf::Vector2f(800, 400))); });
    }
    
    void draw(sf::RenderWindow& window) override
    {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			InputFieldsManager::Reset();
		}
        canvas.clear(sf::Color::White);
		canvas.draw(nameHeader);
        canvas.draw(nameInput);
		canvas.draw(radiusHeader);
		canvas.draw(radiusInput);
		canvas.draw(weightHeader);
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
