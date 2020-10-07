#pragma once
#include <SFML/Graphics.hpp>

class Planet
{
public:
	Planet(const std::string& name, const double radius, const double mass,const sf::Vector2f& position, const sf::Vector2f& initial_speed_v = sf::Vector2f(0,0), const sf::Color color = sf::Color::White);
	void draw(sf::RenderWindow&);
    void setPosition(const sf::Vector2f& position) {sphere.setPosition(position); }
	const double get_mass() const { return mass; }
	const double get_radius() const { return radius; }
	const sf::Vector2f getPosition() { return sphere.getPosition(); }
	const sf::Vector2f getSpeed() { return speed; }
	const sf::FloatRect& getGlobalBounds() { return sphere.getGlobalBounds(); }
    
	void accelerate(const sf::Vector2f& acceleration);
	void move()
	{
		sphere.move(speed);
	}
private:
	sf::CircleShape sphere;
	sf::Vector2f speed;
    
    std::string name;

	double radius;
	double mass;
};
