#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "Menu.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu", sf::Style::Close);

    MainMenu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                menu.handleMouseClick(mousePos);
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }

    return 0;
}
