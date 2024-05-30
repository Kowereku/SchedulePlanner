#include "Menu.h"


Menu::Menu(float width, float height, State& state) : currentState(state) {
    if (!font.loadFromFile("arial.ttf")) {
        // obsługa wyjątku
    }

    for (int i = 0; i < MENU_ITEMS; ++i) {
        sf::Text text;
        text.setFont(font);
        switch (i)
        {
        case 0:
            text.setString("Otworz"); break;
        case 1:
            text.setString("Opcje"); break;
        case 2:
            text.setString("Autorzy"); break;
        case 3:
            text.setString("Wyjdz"); break;
        }
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(width / 2 - text.getGlobalBounds().width / 2, height / (MENU_ITEMS + 1) * (0.7*i + 1) + 200));
        menuItems.push_back(text);
    }

    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(63, 63, 63)); // Szary kolor tła

    header.setFont(font);
    header.setString("Kalendarz");
    header.setCharacterSize(80);
    header.setFillColor(sf::Color::White);
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 10 - 30));
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(header);
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

void Menu::handleMouseClick(sf::Vector2f mousePos) {
    for (const auto& item : menuItems) {
        if (item.getGlobalBounds().contains(mousePos)) {
            if (item.getString() == "Otworz") {
                currentState = State::TimeTable;
            }
            else if (item.getString() == "Opcje") {
                std::cout << "Wcisnieto opcje" << std::endl;
            }
            else if (item.getString() == "Autorzy") {
                std::cout << "Wcisnieto autorzy" << std::endl;
            }
            else if (item.getString() == "Wyjdz") {
                exit(0);
            }
        }
    }
}
