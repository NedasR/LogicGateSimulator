#pragma once
#include "Gate.hpp"
#define PI 3.14
enum class Pintype
{
	Input,
	Output
};

struct Pin
{
	static Pin* head;

	bool state;

	sf::Vector2f Loc;

	Pintype type;

	Pin * nextpin;

	Gate * hookedpin;

	Pin();

	void UpdateState(bool& State);

	void updateLoc(sf::RectangleShape& pinDraw);

	float calculateAngle(sf::Vector2f& origin, sf::Vector2f& target);

	float  calculateLineDist(sf::Vector2f& origin, sf::Vector2f& target);

	static void onclick(Pin* pin);
};

