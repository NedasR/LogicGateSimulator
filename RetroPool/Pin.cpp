#include "Pin.hpp"
#include <iostream>
Pin* Pin::head;

void Pin::UpdateState(bool& State)
{
	state = State;
	if (nextpin != nullptr)
	{
		nextpin->UpdateState(State);
	}
}

 void Pin::onclick(Pin* pin)
{
	 if (Pin::head == nullptr) 
	 {
		 Pin::head = pin;
		 std::cout << "head is at now at " << Pin::head << std::endl;
	 }
	 else {
		 if (Pin::head->type != pin->type) {
			 std::cout << "making a link between " << Pin::head << " and " << pin << std::endl;
			 head->nextpin = pin;
			 pin->nextpin = head;
		 }
		 else {
			 std::cout << " can't link same type's " << std::endl;
		 }
		 Pin::head = nullptr;
	 }

}