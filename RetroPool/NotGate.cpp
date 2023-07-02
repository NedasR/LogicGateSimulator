#include "NotGate.hpp"

NotGate::NotGate() {
	state = false;
	inputA.state = false;
	output.type = Pintype::Output;
	inputA.type = Pintype::Input;
	Loc.x = 600;
	Loc.y = 600;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.LoadFont();
	shape.GateText("NOT");
	pinOut.Pinsize(shape.getGateSize().x / 6.8f, shape.getGateSize().y / 6.8f);
	pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y - pinOut.getPinSize().y);
	pinOut.PinColor();
	inputAdraw.PinColor();
	inputAdraw.Pinsize(shape.getGateSize().x / 6.8f, shape.getGateSize().y / 6.8f);
	inputAdraw.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y + shape.getGateSize().y);
}

void NotGate::notifey()
{
	state = (!inputA.state);
	output.UpdateState(state);
}

void NotGate::drawGate(sf::RenderWindow& window)
{
	window.draw(shape.GateShape);

	window.draw(inputAdraw.Pinshape);
	window.draw(pinOut.Pinshape);
	if (output.type != Pintype::Input && output.nextpin != nullptr)
	{
		pinOut.Line.setFillColor(pinOut.stateLineColor(state));
		window.draw(pinOut.Line);
	}
	window.draw(pinOut.Pinshape);
	window.draw(shape.text);
}

void NotGate::moveupdate(sf::Vector2f pos)
{
	if (shape.isHeld(pos)) {
		Loc.x = pos.x - shape.getGateSize().x / 2;
		Loc.y = pos.y - shape.getGateSize().y / 2;
		shape.GatePos(Loc);
		pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y - pinOut.getPinSize().y);
		inputAdraw.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y + shape.getGateSize().y);
		shape.GateText("NOT");
	}
}

void NotGate::clickupdate(sf::Vector2f pos)
{
	if (pinOut.isClicked(pos))
	{
		Pin::onclick(&output);
	}
	if (inputAdraw.isClicked(pos))
	{
		Pin::onclick(&inputA);
	}
}

void NotGate::lineUpdate()
{
	inputA.updateLoc(inputAdraw.Pinshape);
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
		pinOut.Line.setSize(sf::Vector2f(4, lineLength + 2));
		pinOut.Line.setFillColor(sf::Color::White);
	}
}

void NotGate::disconnectUpdate(sf::Vector2f pos)
{
	if (pinOut.isClicked(pos))
	{
		output.disconnect();
	}
}