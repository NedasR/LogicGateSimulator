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

public:
	
	bool state;
	Pin inputA;

	Light();

	void notifey();

	void drawGate(sf::RenderWindow& window);

	void moveupdate(sf::Vector2f pos);

	void clickupdate(sf::Vector2f pos);

	void lineUpdate();

	void disconnectUpdate(sf::Vector2f pos);
};