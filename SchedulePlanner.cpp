#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 600), "Menu glowne", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::MouseButtonPressed:
                cout << "Button " << event.mouseButton.button << " @ "
                    << sf::Mouse::getPosition(window).x << ", "
                    << sf::Mouse::getPosition(window).y << "\n";
                break;
            case sf::Event::Closed:
                window.close();
            }
        }

        window.clear();

        menu.draw(window);
        
        window.display();
    }

}