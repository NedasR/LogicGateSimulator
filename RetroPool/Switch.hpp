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


	bool state;

	Pin output;

public:

	Switch();

	void Switchclicked();

	void notifey();

	void drawGate(sf::RenderWindow &window);
};