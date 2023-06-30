#pragma once
#include <SFML/Graphics.hpp>
class Gate
{
public:
	virtual void notifey() = 0;
	virtual void drawGate(sf::RenderWindow &window) = 0;
	virtual void moveupdate(sf::Vector2f pos) = 0;
	virtual void clickupdate(sf::Vector2f pos) = 0;
	virtual void lineUpdate() = 0;

};