#include "Switch.hpp"
Switch::Switch()
{
	shape.Gatesize();
	shape.GateColor();
	state = false;
}

void Switch::Switchclicked()
{
	if (state == false) 
	{
		state = true;
	}
	else {
		state = false;
	}
	
}

void Switch::notifey()
{
	output.UpdateState(state);
}

void Switch::drawGate(sf::RenderWindow &window) 
{
	window.draw(shape.GateShape);
}