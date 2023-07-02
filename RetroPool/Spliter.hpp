#pragma once

#include "Gate.hpp"
#include "Pin.hpp"
#include "GateDrawable.hpp"
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

class Spliter : public Gate
{
	sf::Vector2f Loc;
	GateDrawable shape;
	PinDrawable inputAdraw;
	PinDrawable pinOut;
	PinDrawable pinOut2;
	PinDrawable pinOut3;

public:

	bool state;
	Pin inputA;
	Pin output;
	Pin output2;
	Pin output3;

	Spliter();

	void notifey();

	void drawGate(sf::RenderWindow& window);

	void moveupdate(sf::Vector2f pos);

	void clickupdate(sf::Vector2f pos);

	void lineUpdate();

	void disconnectUpdate(sf::Vector2f pos);

};