#pragma once
#include <SFML/Graphics.hpp>
class GateDrawable
{

public:
	sf::RectangleShape GateShape;

	void GateText();

	void Gatesize(float width = 60.f, float height = 60.f);
};