#include "Pin.hpp"
#include "GateDrawable.hpp"
Pin* Pin::head;

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

float  Pin::calculateLineDist(sf::Vector2f& origin, sf::Vector2f& target)
{
	float dx = target.x - origin.x;
	float dy = target.y - origin.y;
	return std::sqrt(dx * dx + dy * dy);
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