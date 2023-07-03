#include "Switch.hpp"
#include "Utils.hpp"
Switch::Switch()
{
	Loc.x = 900;
	Loc.y = 600;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.LoadFont();
	shape.GateText("switch");
	pinOut.Pinsize(shape.getGateSize().x / 6.8, shape.getGateSize().y / 6.8);
	pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2 ) - pinOut.getPinSize().x / 2 , Loc.y - pinOut.getPinSize().y);
	pinOut.PinColor();
	state = false;
	output.type = Pintype::Output;
}

void Switch::Switchclicked(const sf::Event::MouseButtonEvent& mouseEvent)
{
	
	sf::Vector2f gate_size = shape.getGateSize();
	/*
	sf::FloatRect gatesize(0, 0, 0, 0);
	if (gatesize.contains(0, 0)) {

	}*/
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
	if (output.type != Pintype::Input && output.nextpin != nullptr)
	{
		pinOut.Line.setFillColor(pinOut.stateLineColor(state));
		window.draw(pinOut.Line);
	}
	window.draw(pinOut.Pinshape);
}

void Switch::moveupdate(sf::Vector2f pos)
{
	if (shape.isHeld(pos)) {
		Loc.x = pos.x - shape.getGateSize().x / 2;
		Loc.y = pos.y - shape.getGateSize().y / 2;
		shape.GatePos(Loc);
		pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y - pinOut.getPinSize().y);
		shape.GateText("switch");
	}
}

void Switch::clickupdate(sf::Vector2f pos)
{
	if (pinOut.isClicked(pos))
	{
		Pin::onclick(&output);
	}
}

void Switch::lineUpdate()
{
	output.updateLoc(pinOut.Pinshape);
	pinOut.Line.setPosition(output.Loc.x + pinOut.getPinSize().x / 2,
							output.Loc.y + pinOut.getPinSize().x / 2);
	if (output.nextpin == nullptr)
	{
	}
	else
	{
		float angle = Utils::calculateAngle(output.Loc, output.nextpin->Loc);
		float lineLength = Utils::calculateLineDist(output.Loc, output.nextpin->Loc);
		pinOut.Line.setRotation(angle);
		pinOut.Line.setSize(sf::Vector2f(4,lineLength));
		pinOut.Line.setFillColor(sf::Color::White);
	}
}

void Switch::disconnectUpdate(sf::Vector2f pos)
{
	if (pinOut.isClicked(pos))
	{
		output.disconnect();
	}
}