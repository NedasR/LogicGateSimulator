#include <SFML/Graphics.hpp>
#include "AllhppFiles.hpp"
#include "AndGate.hpp"
#include "ORGate.hpp"
#include "NotGate.hpp"
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
    Gate* andgate = new AndGate();
    gates.push_back(andgate);
    Gate* ORgate = new ORGate();
    gates.push_back(ORgate);
    Gate* O1Rgate = new ORGate();
    gates.push_back(O1Rgate);
    Gate* N1otgate = new NotGate();
    gates.push_back(N1otgate);
    Gate* Notgate = new NotGate();
    gates.push_back(Notgate);

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
                if (event.mouseButton.button == sf::Mouse::Right)
                    
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
                gate->disconnectUpdate(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
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
////////
disconnects
spliter gate
gate spawner keys from 1 to 6
////////

*/