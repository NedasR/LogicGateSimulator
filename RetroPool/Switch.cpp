#include "Switch.hpp"
Switch::Switch()
{
	Loc.x = 400;
	Loc.y = 400;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.LoadFont();
	shape.GateText("switch");
	pinOut.Pinsize(shape.getGateSize().x / 6.8, shape.getGateSize().y / 6.8);
	pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2 ) - pinOut.getPinSize().x / 2 , Loc.y - pinOut.getPinSize().y);
	pinOut.PinColor();
	state = false;
	output.hookedpin = this;
	output.type = Pintype::Output;
}

void Switch::Switchclicked(const sf::Event::MouseButtonEvent& mouseEvent)
{
	sf::Vector2f gate_size = shape.getGateSize();
	sf::FloatRect gatesize(0, 0, 0, 0);
	if (gatesize.contains(0, 0)) {

	}
	if (Loc.x < mouseEvent.x &&
		Loc.x + gate_size.x > mouseEvent.x &&
		Loc.y < mouseEvent.y &&
		Loc.y + gate_size.x > mouseEvent.y)
	{
		if (state == false)
		{
			state = true;
			output.state = true;

		}
		else {
			state = false;
			output.state = false;
		}
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

void Switch::move(int Px, int Py)
{
	Loc.x = Px;
	Loc.y = Py;
	shape.GatePos(Loc);
	pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y - pinOut.getPinSize().y);
	shape.GateText("switch");
}

void Switch::clickupdate(sf::Vector2f pos)
{
	if (pinOut.isClicked(pos))
	{
		Pin::head = &output;
		std::cout << "head is at now at " << Pin::head << std::endl;
	}
}