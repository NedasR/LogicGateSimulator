#include <SFML/Graphics.hpp>
#include "AllhppFiles.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Coffie's game");
    bool filp, held;
    filp = held = false;
    Switch button;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code == sf::Keyboard::T && !(filp))
            {
                filp = true;
                button.Switchclicked();
                std::cout << button.state << std::endl;
            }
            if (filp&& !held) {
                held = true;
            }
            else {
                filp = false;
                held = false;
            }
            
        }
        
        window.clear();
        button.drawGate(window);
        window.display();
    }

    return 0;
}