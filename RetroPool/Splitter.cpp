#include "Spliter.hpp"

Spliter::Spliter()
{
	state = false;
	inputA.state = false;
	output.type = Pintype::Output;
	output2.type = Pintype::Output;
	output3.type = Pintype::Output;
	inputA.type = Pintype::Input;
	Loc.x = 800;
	Loc.y = 600;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.LoadFont();
	shape.GateText("spliter");
	pinOut.Pinsize(shape.getGateSize().x / 6.8f, shape.getGateSize().y / 6.8f);
	pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y - pinOut.getPinSize().y);
	pinOut.PinColor();
	inputAdraw.PinColor();
	inputAdraw.Pinsize(shape.getGateSize().x / 6.8f, shape.getGateSize().y / 6.8f);
	inputAdraw.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y + shape.getGateSize().y);
	pinOut2.PinColor();
	pinOut3.PinColor();
	pinOut2.Pinsize(shape.getGateSize().x / 6.8, shape.getGateSize().y / 6.8);
	pinOut3.Pinsize(shape.getGateSize().x / 6.8, shape.getGateSize().y / 6.8);
	pinOut2.PinPos(Loc.x + (shape.getGateSize().x / 5) - pinOut2.getPinSize().x / 2, Loc.y - pinOut2.getPinSize().y);
	pinOut3.PinPos(Loc.x + (shape.getGateSize().x / 1.25) - pinOut3.getPinSize().x / 2, Loc.y - pinOut3.getPinSize().y);
}

void Spliter::notifey()
{
	state = (inputA.state);
	output.UpdateState(state);
	output2.UpdateState(state);
	output3.UpdateState(state);
}

void Spliter::drawGate(sf::RenderWindow& window)
{
	window.draw(shape.GateShape);
	window.draw(inputAdraw.Pinshape);
	if (output.type != Pintype::Input && output.nextpin != nullptr)
	{
		pinOut.Line.setFillColor(pinOut.stateLineColor(state));
		window.draw(pinOut.Line);
	}
	if (output2.type != Pintype::Input && output2.nextpin != nullptr)
	{
		pinOut2.Line.setFillColor(pinOut2.stateLineColor(state));
		window.draw(pinOut2.Line);
	}
	if (output3.type != Pintype::Input && output3.nextpin != nullptr)
	{
		pinOut3.Line.setFillColor(pinOut3.stateLineColor(state));
		window.draw(pinOut3.Line);
	}
	window.draw(pinOut.Pinshape);
	window.draw(pinOut2.Pinshape);
	window.draw(pinOut3.Pinshape);
	window.draw(shape.text);
}

void Spliter::moveupdate(sf::Vector2f pos)
{
	if (shape.isHeld(pos)) {
		Loc.x = pos.x - shape.getGateSize().x / 2;
		Loc.y = pos.y - shape.getGateSize().y / 2;
		shape.GatePos(Loc);
		pinOut.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y - pinOut.getPinSize().y);
		inputAdraw.PinPos(Loc.x + (shape.getGateSize().x / 2) - pinOut.getPinSize().x / 2, Loc.y + shape.getGateSize().y);
		pinOut2.PinPos(Loc.x + (shape.getGateSize().x / 5) - pinOut2.getPinSize().x / 2, Loc.y - pinOut2.getPinSize().y);
		pinOut3.PinPos(Loc.x + (shape.getGateSize().x / 1.25) - pinOut3.getPinSize().x / 2, Loc.y - pinOut3.getPinSize().y);
		shape.GateText("spliter");
	}
}

void Spliter::clickupdate(sf::Vector2f pos)
{
	if (pinOut.isClicked(pos))
	{
		Pin::onclick(&output);
	}
	if (pinOut2.isClicked(pos))
	{
		Pin::onclick(&output2);
	}
	if (pinOut3.isClicked(pos))
	{
		Pin::onclick(&output3);
	}
	if (inputAdraw.isClicked(pos))
	{
		Pin::onclick(&inputA);
	}
}

void Spliter::lineUpdate()
{
	inputA.updateLoc(inputAdraw.Pinshape);
	output.updateLoc(pinOut.Pinshape);
	output2.updateLoc(pinOut2.Pinshape);
	output3.updateLoc(pinOut3.Pinshape);
	pinOut.Line.setPosition(output.Loc.x + pinOut.getPinSize().x / 2,
		output.Loc.y + pinOut.getPinSize().x / 2);
	pinOut2.Line.setPosition(output2.Loc.x + pinOut2.getPinSize().x / 2,
		output2.Loc.y + pinOut2.getPinSize().x / 2);
	pinOut3.Line.setPosition(output3.Loc.x + pinOut3.getPinSize().x / 2,
		output3.Loc.y + pinOut3.getPinSize().x / 2);
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
	if (output2.nextpin == nullptr)
	{
	}
	else
	{
		float angle2 = Utils::calculateAngle(output2.Loc, output2.nextpin->Loc);
		float lineLength2 = Utils::calculateLineDist(output2.Loc, output2.nextpin->Loc);
		pinOut2.Line.setRotation(angle2);
		pinOut2.Line.setSize(sf::Vector2f(4, lineLength2 + 2));
		pinOut2.Line.setFillColor(sf::Color::White);
	}
	if (output3.nextpin == nullptr)
	{
	}
	else
	{
		float angle3 = Utils::calculateAngle(output3.Loc, output3.nextpin->Loc);
		float lineLength3 = Utils::calculateLineDist(output3.Loc, output3.nextpin->Loc);
		pinOut3.Line.setRotation(angle3);
		pinOut3.Line.setSize(sf::Vector2f(4, lineLength3 + 2));
		pinOut3.Line.setFillColor(sf::Color::White);
	}
}

void Spliter::disconnectUpdate(sf::Vector2f pos)
{
	if (pinOut.isClicked(pos))
	{
		output.disconnect();
	}
	if (pinOut2.isClicked(pos))
	{
		output2.disconnect();
	}
	if (pinOut3.isClicked(pos))
	{
		output3.disconnect();
	}
}