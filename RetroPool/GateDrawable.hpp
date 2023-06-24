#pragma once
#include <SFML/Graphics.hpp>
class GateDrawable
{

public:
	sf::RectangleShape GateShape;

	void GateText();

	void Gatesize(float width = 40.f, float height = 40.f);

	void GateColor(sf::Color color = sf::Color(38, 34, 34));
};