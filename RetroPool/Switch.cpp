#include "Switch.hpp"
Switch::Switch()
{
	Loc.x = 400;
	Loc.y = 400;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.GateText("switch");
	pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2) - 4, Loc.y - 6);
	pinOut.Pinsize();
	pinOut.PinColor();
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
	window.draw(shape.text);
	window.draw(pinOut.Pinshape);
}