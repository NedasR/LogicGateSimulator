#pragma once
#include "Gate.hpp"
#include <iostream>
#include <cmath>
enum class Pintype
{
	Input,
	Output
};

struct Pin
{
	static Pin* s_head;

	bool state;

	sf::Vector2f Loc;

	Pintype type;

	Pin * nextpin;

	Pin();

	void UpdateState(bool& State);

	void updateLoc(sf::RectangleShape& pinDraw);

	static void onclick(Pin* pin);

	void disconnect();
};

