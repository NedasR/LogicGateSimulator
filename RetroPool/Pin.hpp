#pragma once
#include "Gate.hpp"
struct Pin
{
	bool state;

	Pin * nextpin;

	Gate * hookedpin;

	void UpdateState(bool State);
};