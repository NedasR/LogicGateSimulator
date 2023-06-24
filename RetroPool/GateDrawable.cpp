#include "GateDrawable.hpp"

void GateDrawable::GateText()
{

}

void GateDrawable::Gatesize(float width, float height)
{
	GateShape.setSize(sf::Vector2f(width, height));
}

void GateDrawable::GateColor(sf::Color color)
{
	GateShape.setFillColor(sf::Color(color));
}