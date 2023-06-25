#include "Switch.hpp"
Switch::Switch()
{
	Loc.x = 400;
	Loc.y = 400;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.GateText("switch");
	pinOut.Pinsize(shape.getGateSize().x / 6.8, shape.getGateSize().y / 6.8);
	pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2 ) - pinOut.getPinSize().x / 2 , Loc.y - pinOut.getPinSize().y);
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