#include "Light.hpp"

Light::Light() 
{
	shape.Gatesize();
	Loc.x = 450;
	Loc.y = 400;
	shape.GatePos(Loc);
	shape.Gatesize();
	shape.GateColor();
	shape.GateTexture("assets/LightBulb.png", sf::IntRect(64, 0, 64, 64));
	inputAdraw.Pinsize(shape.getGateSize().x / 6.8, shape.getGateSize().y / 6.8);
	inputAdraw.PinPos(Loc.x + (shape.getGateSize().x / 2) - inputAdraw.getPinSize().x / 2, Loc.y + shape.getGateSize().y);
	inputAdraw.PinColor();
	state = false;
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

void Light::LightPowerd(bool& OnOROFF)
{
	if (OnOROFF) {
		shape.GateTexture("assets/LightBulb.png", sf::IntRect(0, 0, 64, 64));
	}
	else {
		shape.GateTexture("assets/LightBulb.png", sf::IntRect(64, 0, 64, 64));
	}
}