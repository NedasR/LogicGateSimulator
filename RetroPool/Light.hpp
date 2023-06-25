#pragma once
#include "Gate.hpp"
#include "Pin.hpp"
#include "GateDrawable.hpp"
#include <SFML/Graphics.hpp>

class Light : public Gate
{
	sf::Vector2f Loc;
	GateDrawable shape;
	PinDrawable inputAdraw;

	bool state;
	Pin inputA;

public:

	Light();

	void notifey();

	void drawGate(sf::RenderWindow& window);

	void LightPowerd(bool &OnOROFF);
};