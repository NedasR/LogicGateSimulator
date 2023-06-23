#pragma once
#include <SFML/Graphics.hpp>
class Gate
{
	virtual void notifey() = 0;
	virtual void drawGate(sf::RenderWindow &window) = 0;

};