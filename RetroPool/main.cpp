#include <SFML/Graphics.hpp>
#include "AllhppFiles.hpp"
#include <iostream>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Coffie's game");
    bool filp, held;
    filp = held = false;
    int objectcount = 0;
    std::vector<Gate*> gates;
    Gate* light = new Light();
    gates.push_back(light);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::S)
                {
                    Gate* Switchptr = new Switch();
                    //Switchptr->move(std::rand()%1200-40,std::rand()%800-40);
                    gates.push_back(Switchptr);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    
                {
                    sf::Vector2f mouse(event.mouseButton.x, event.mouseButton.y);
                    for (Gate* gate : gates)
                    {
                        gate->clickupdate(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));




                        //Switch* a = (Switch*)gate;
                        Switch* a = dynamic_cast<Switch*>(gate);
                        if (a == nullptr) {
                           //std::cout << "nullptr" << std::endl;
                        }
                        else {
                            a->Switchclicked(event.mouseButton);
                            std::cout << a->state << std::endl;
                            /*
                            
                            Pin::head = &a->output;
                            Pin::head->state = a->state;
                            */
                        }

                    }
                }
            }
        }

        for (Gate* gate : gates)
        {
            if (gate == nullptr)
            {
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                gate->moveupdate(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
                /*
                if (Pin::head != nullptr) {
                    Pin::head->nextpin = &Lights->inputA;
                    Lights->state = Pin::head->nextpin->state;
                }*/
            }
        }
        /*
        if (Pin::head != nullptr) {

            Pin::head->nextpin->state = Pin::head->state;
        }*/

        for (Gate* gate : gates)
        {

            Switch* a = dynamic_cast<Switch*>(gate);
            if (a == nullptr) {
            }
            else {
                
                
            }
        }

        for (Gate* gate : gates)
        {

            Light* a = dynamic_cast<Light*>(gate);
            if (a == nullptr) {
            }
            else {
                a->LightPowerd();
            }
        }
    

        window.clear();
        for (Gate* gate : gates) 
        {
            gate->notifey();
            gate->lineUpdate();
            gate->drawGate(window);
        }
        window.display();
    }
    return 0;
}

/*
TO DO LIST
//////// make functionality where when i connect pins it draw's line from on pin to the next pin
make rectangle in pin drawble which will be the line we will be drawing
--in pindrawable make a method where it returns pin Pos
make a pure fucntion in gate where it will update where the line points to if gate is moved or connected for the first time
make Loc varibale in Pin and make a updateLoc in Pin make an argument of pindawable by reference



////////

*/