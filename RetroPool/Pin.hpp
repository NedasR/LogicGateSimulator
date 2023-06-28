#pragma once
#include "Gate.hpp"
enum class Pintype
{
	Input,
	Output
};

struct Pin
{
	static Pin* head;

	bool state;

	Pintype type;

	Pin * nextpin;

	Gate * hookedpin;

	void UpdateState(bool& State);
};