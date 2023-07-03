#include <SFML/Graphics.hpp>
#include "Gate.hpp"
#include "Pin.hpp"
#include "Switch.hpp"
#include "Light.hpp"
#include "GateDrawable.hpp"
#include "AndGate.hpp"
#include "ORGate.hpp"
#include "NotGate.hpp"
#include "Spliter.hpp"
#include <iostream>
#include <vector>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Coffie's game");
    std::vector<Gate*> gates;
    sf::Text spawntext;
    sf::Font font;
    font.loadFromFile("assets/arial.ttf");
    spawntext.setFont(font);
    spawntext.setCharacterSize(16);
    spawntext.setString("1.Switch,2.Light,3.Spliter,4.NotGate,5.AndGate,6.ORgate");
    spawntext.setPosition(window.getSize().x / 2 - spawntext.getGlobalBounds().width / 2, window.getSize().y - spawntext.getGlobalBounds().height);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Num1)
                {
                    Gate* Switchptr = new Switch();
                    gates.push_back(Switchptr);
                }
                if (event.key.code == sf::Keyboard::Num2)
                {
                    Gate* Lightptr = new Light();
                    gates.push_back(Lightptr);
                }
                if (event.key.code == sf::Keyboard::Num3)
                {
                    Gate* Spliterptr = new Spliter();
                    gates.push_back(Spliterptr);
                }
                if (event.key.code == sf::Keyboard::Num4)
                {
                    Gate* NotGateptr = new NotGate();
                    gates.push_back(NotGateptr);
                }
                if (event.key.code == sf::Keyboard::Num5)
                {
                    Gate* AndGateptr = new AndGate();
                    gates.push_back(AndGateptr);
                }
                if (event.key.code == sf::Keyboard::Num6)
                {
                    Gate* ORGateptr = new ORGate();
                    gates.push_back(ORGateptr);
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
                        
                        Switch* a = dynamic_cast<Switch*>(gate);
                        if (a == nullptr) {
                        }
                        else {
                            a->Switchclicked(event.mouseButton);
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
            }
        }

        window.clear();
        for (Gate* gate : gates) 
        {
            gate->notifey();
            gate->lineUpdate();
            gate->drawGate(window);
        }
        window.draw(spawntext);
        window.display();
    }
    return 0;
}