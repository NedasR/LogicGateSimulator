#include "Switch.hpp"
Switch::Switch()
{
	shape.Gatesize();
	Button = false;
}

void Switch::notifey()
{
	output.UpdateState(Button);
}

void Switch::drawGate(sf::RenderWindow &window) 
{
	window.draw(shape.GateShape);
}