#pragma once
#include "Gate.hpp"
#include "Pin.hpp"
#include "GateDrawable.hpp"
#include <SFML/Graphics.hpp>

class Switch : public Gate
{
	GateDrawable shape;

	Pin output;

	bool Button;

public:

	Switch();

	void notifey();

	void drawGate(sf::RenderWindow &window);
};