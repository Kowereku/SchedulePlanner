#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "Menu.h"
#include "TimeTable.h"
#include "sqlite3.h"
#include "DBCal.h"


int main() {
    sqlite3* DBCal;

    createDBCal(dir);
    createTable(dir);
        
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Main Menu", sf::Style::Close);

    State state = State::Menu;

    Menu menu(window.getSize().x, window.getSize().y, state);
    TimeTable timetable(window.getSize().x, window.getSize().y, state);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                switch (state)
                {
                case (State::Menu):
                    menu.handleMouseClick(mousePos); break;
                
                case (State::TimeTable):
                    timetable.handleMouseClick(mousePos); break;
                }

            }
        }
        window.clear();
        switch (state)
        {
        case (State::Menu):
            menu.draw(window); break;
        case (State::TimeTable):
            timetable.draw(window); break;
        }
        window.display();
    }

    return 0;
}
