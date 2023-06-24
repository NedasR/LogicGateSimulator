#pragma once
#include "Gate.hpp"
#include "Pin.hpp"
#include "GateDrawable.hpp"
#include <SFML/Graphics.hpp>

class Switch : public Gate
{
	GateDrawable shape;

	Pin output;

	

public:
	bool state;

	Switch();

	void Switchclicked();

	void notifey();

	void drawGate(sf::RenderWindow &window);
};