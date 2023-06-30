#pragma once
#include "Gate.hpp"
#include "Pin.hpp"
#include "GateDrawable.hpp"
#include <SFML/Graphics.hpp>

class Switch : public Gate
{
	sf::Vector2f Loc;
	GateDrawable shape;
	PinDrawable pinOut;


public:
	bool state;
    Pin output;


	Switch();

	void Switchclicked(const sf::Event::MouseButtonEvent& mouseEvent);

	void notifey();

	void drawGate(sf::RenderWindow &window);

	void moveupdate(sf::Vector2f pos);

	void clickupdate(sf::Vector2f pos);

	void lineUpdate();
};