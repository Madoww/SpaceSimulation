#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

static class PressablesManager;

class Pressable
{
public:
	Pressable();
	bool CheckIfPressed();
	virtual void OnPress() = 0;
protected:
	sf::RectangleShape bounds;
private:
	bool wasCalled = false;
};

static class PressablesManager
{
public:
	static bool CheckIfAnyPressed();
	static std::vector<Pressable*> pressables;
};