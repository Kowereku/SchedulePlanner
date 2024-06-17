#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "Menu.h"
#include "Authors.h"
#include "TimeTable.h"
#include "Adding.h"
#include "Delete.h"
#include "Editing.h"
#include "Changing.h"
#include "sqlite3.h"
#include "DBCal.h"

int main() {
    createDBCal(dir);
    createTable(dir);
        
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Main Menu", sf::Style::Close);

    State state = State::Menu;

    Menu menu(window.getSize().x, window.getSize().y, state);
    Authors authors(window.getSize().x, window.getSize().y, state);
    TimeTable timetable(window.getSize().x, window.getSize().y, state);
    Adding adding(window.getSize().x, window.getSize().y, state);
    Delete Delete(window.getSize().x, window.getSize().y, state);
    Changing changing(window.getSize().x, window.getSize().y, state);
    Editing editing(window.getSize().x, window.getSize().y, state, changing);

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
                case (State::Adding):
                    adding.handleEvent(event); break;
                case (State::Delete):
                    Delete.handleEventDel(mousePos); break;
                case (State::Editing):
                    editing.handleEventEdit(mousePos); break;
                case (State::Changing):
                    changing.handleEvent(event); break;
                case (State::Authors):
                    authors.handleMouseClick(mousePos); break;
                }
                
            }
            else if (event.type == sf::Event::TextEntered)
            {
                switch (state)
                {
                case State::Adding:
                    adding.handleEvent(event); break;
                case State::Changing:
                    changing.handleEvent(event); break;
                }

            }
        }
        window.clear();
        switch (state)
        {
        case (State::Menu):
            menu.draw(window); break;
        case (State::Authors):
            authors.draw(window); break;
        case (State::TimeTable):
            timetable.draw(window); break;
        case (State::Adding):
            adding.draw(window); break;
        case (State::Delete):
            Delete.draw(window); break;
        case (State::Editing):
            editing.draw(window); break;
        case (State::Changing):
            changing.draw(window); break;
        }
        window.display();
    }

    return 0;
}
