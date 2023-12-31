#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define GATE_SIZEs 40.f
#define LINE_WIDTH 4
class GateDrawable
{
	sf::Texture Tex;
	sf::Font Tfont;
	sf::Vector2f Offset;

	bool m_isHeld;
	static bool onHold;
public:
	sf::RectangleShape GateShape;
	sf::Text text;
	
	void GateText(std::string TEXT);

	void Gatesize(float width = GATE_SIZEs, float height = GATE_SIZEs);

	void GateColor(sf::Color color = sf::Color(38, 34, 34));

	void GatePos(sf::Vector2f Position);

	void GatePos(float PositionX,float PositionY);

	void GateTexture(std::string texturepath,sf::IntRect Rect);

	sf::Vector2f getGateSize();

	void LoadFont(std::string Font = "assets/arial.ttf");

	bool isHeld(sf::Vector2f pos);
};

class PinDrawable
{
public:
	sf::RectangleShape Pinshape;
	sf::RectangleShape Line;
	PinDrawable();

	sf::Color stateLineColor(bool state, sf::Color NegitveColor = sf::Color::White, sf::Color PositiveColor = sf::Color(15, 83, 191));

	void Pinsize(float width = 6.f, float height = 6.f);

	void PinColor(sf::Color color = sf::Color(173, 169, 168));

	void PinPos(sf::Vector2f Position);

	void PinPos(float PositionX, float PositionY);

	sf::Vector2f getPinSize();

	bool isClicked(sf::Vector2f pos);

	sf::Vector2f getPinPos() {return Pinshape.getPosition();}

};