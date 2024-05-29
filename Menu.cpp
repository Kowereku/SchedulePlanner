#include "Menu.h"
#include <iostream>

MainMenu::MainMenu(float width, float height) {
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
        text.setPosition(sf::Vector2f(width / 2, height / (MENU_ITEMS + 1) * (i + 1)));
        menuItems.push_back(text);
    }
}

void MainMenu::draw(sf::RenderWindow& window) {
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

void MainMenu::handleMouseClick(sf::Vector2f mousePos) {
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
