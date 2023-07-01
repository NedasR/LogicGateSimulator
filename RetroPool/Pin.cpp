#include "Pin.hpp"
#include "GateDrawable.hpp"
Pin* Pin::s_head;

Pin::Pin()
{
	nextpin = nullptr;
}

void Pin::UpdateState(bool& State)
{
	state = State;
	if (nextpin != nullptr)
	{
		nextpin->state = State;
		//nextpin->UpdateState(State);
	}
}

void Pin::updateLoc(sf::RectangleShape& pinDraw)
{
	Loc = pinDraw.getPosition();
}

 void Pin::onclick(Pin* pin)
{
	 if (Pin::s_head == nullptr) 
	 {
		 Pin::s_head = pin;
		 std::cout << "head is at now at " << Pin::s_head << std::endl;
	 }
	 else {
		 if (Pin::s_head->type != pin->type) {
			 std::cout << "making a link between " << Pin::s_head << " and " << pin << std::endl;
			 s_head->nextpin = pin;
			 pin->nextpin = s_head;
		 }
		 else {
			 std::cout << " can't link same type's " << std::endl;
		 }
		 Pin::s_head = nullptr;
	 }

}