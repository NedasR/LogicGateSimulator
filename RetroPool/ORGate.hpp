#pragma once
#include "Gate.hpp"
#include "Pin.hpp"
#include "GateDrawable.hpp"
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

class ORGate : public Gate
{
	sf::Vector2f Loc;
	GateDrawable shape;
	PinDrawable inputAdraw;
	PinDrawable inputBdraw;
	PinDrawable pinOut;

public:

	bool state;
	Pin inputA;
	Pin inputB;
	Pin output;

	ORGate();

	void notifey();

	void drawGate(sf::RenderWindow& window);

	void moveupdate(sf::Vector2f pos);

	void clickupdate(sf::Vector2f pos);

	void lineUpdate();
};