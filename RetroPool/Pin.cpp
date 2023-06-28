#include "Pin.hpp"

Pin* Pin::head;

void Pin::UpdateState(bool& State)
{
	state = State;
	if (nextpin != nullptr)
	{
		nextpin->UpdateState(State);
	}
}