#include "Light.hpp"

Light::Light() 
{
	shape.Gatesize();
	Loc.x = 800;
	Loc.y = 400;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.GateTexture("assets/LightBulb.png", sf::IntRect(64, 0, 64, 64));
	inputAdraw.Pinsize(shape.getGateSize().x / 6.8, shape.getGateSize().y / 6.8);
	inputAdraw.PinPos(Loc.x + (shape.getGateSize().x / 2) - inputAdraw.getPinSize().x / 2, Loc.y + shape.getGateSize().y);
	inputAdraw.PinColor();
	state = false;
	inputA.hookedpin = this;
	inputA.type = Pintype::Input;
}

void Light::notifey()
{
	inputA.UpdateState(state);
}

void Light::drawGate(sf::RenderWindow& window)
{
	window.draw(shape.GateShape);
	window.draw(shape.text);
	window.draw(inputAdraw.Pinshape);
}

void Light::LightPowerd()
{
	if (state) {
		shape.GateTexture("assets/LightBulb.png", sf::IntRect(0, 0, 64, 64));
		state = true;
	}
	else {
		shape.GateTexture("assets/LightBulb.png", sf::IntRect(64, 0, 64, 64));
		state = false;
	}
}

void Light::moveupdate(sf::Vector2f pos)
{
	if (shape.isHeld(pos))
	{
		Loc.x = pos.x - shape.getGateSize().x / 2;
		Loc.y = pos.y - shape.getGateSize().y / 2;
		shape.GatePos(Loc);
		inputAdraw.PinPos(Loc.x + (shape.getGateSize().x / 2) - inputAdraw.getPinSize().x / 2, Loc.y + shape.getGateSize().y);
	}
	
}

void Light::clickupdate(sf::Vector2f pos)
{
	if (inputAdraw.isClicked(pos))
	{
		Pin::onclick(&inputA);
	}
}