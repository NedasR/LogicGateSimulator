#include "Pin.hpp"


void Pin::UpdateState(bool State)
{
	state = State;
	if (nextpin != nullptr)
	{
		nextpin->UpdateState(State);
	}
}