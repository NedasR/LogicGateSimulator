#include "Light.hpp"

Light::Light() 
{
	shape.Gatesize();
	Loc.x = 500;
	Loc.y = 600;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.GateTexture("assets/LightBulb.png", sf::IntRect(0, 0, 64, 64));
	inputAdraw.Pinsize(shape.getGateSize().x / 6.8, shape.getGateSize().y / 6.8);
	inputAdraw.PinPos(Loc.x + (shape.getGateSize().x / 2) - inputAdraw.getPinSize().x / 2, Loc.y + shape.getGateSize().y);
	inputAdraw.PinColor();
	state = false;
	inputA.state = false;
	inputA.hookedpin = this;
	inputA.type = Pintype::Input;
}

void Light::notifey()
{
	state = inputA.state;
}

void Light::drawGate(sf::RenderWindow& window)
{
	if (state) {
		shape.GateTexture("assets/LightBulb.png", sf::IntRect(0, 0, 64, 64));
	}
	else {
		shape.GateTexture("assets/LightBulb.png", sf::IntRect(64, 0, 64, 64));
	}
	window.draw(shape.GateShape);
	window.draw(shape.text);
	window.draw(inputAdraw.Pinshape);
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

void Light::lineUpdate()
{
	inputA.updateLoc(inputAdraw.Pinshape);
}

void Light::disconnectUpdate(sf::Vector2f pos)
{

}