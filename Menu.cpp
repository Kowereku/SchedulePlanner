#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
    }
    for (int i = 0; i < MENU_ITEMS; ++i) {
        sf::Text text;
        text.setFont(font);
        switch (i)
        {
        case 0:
            text.setString("Otworz planner"); break;
        case 1:
            text.setString("Opcje"); break;
        case 2:
            text.setString("Wyjdz"); break;
        }
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(width / 2 - text.getGlobalBounds().width / 2, height / (MENU_ITEMS + 1) * (i + 1) + 50));
        menuItems.push_back(text);
    }
    header.setFont(font);
    header.setString("Kalendarz");
    header.setCharacterSize(80);
    header.setFillColor(sf::Color::White);
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 10 - 30));
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(header);
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

void Menu::handleMouseClick(sf::Vector2f mousePos) {
    for (const auto& item : menuItems) {
        if (item.getGlobalBounds().contains(mousePos)) {
            if (item.getString() == "Otworz planner") {
                std::cout << "Wcisnieto otworzenie" << std::endl;
            }
            else if (item.getString() == "Opcje") {
                std::cout << "Wcisnieto opcje" << std::endl;
            }
            else if (item.getString() == "Wyjdz") {
                exit(0);
            }
        }
    }
}
