#include <SFML/Graphics.hpp>
#include "AllhppFiles.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Coffie's game");
    bool filp, held;
    filp = held = false;
    Switch button;
    Light light;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {

            if (held) {
                held = false;
            }
            else {
                held = true;
            }


            light.LightPowerd(held);

        }

        window.clear();
        button.drawGate(window);
        light.drawGate(window);
        window.display();
    }

    return 0;
}