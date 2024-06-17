#include "Menu.h"

using namespace std;


Menu::Menu(float width, float height, State& state) : currentState(state) {
    if (!font.loadFromFile("charlotte.ttf")) {
        // obsługa wyjątku
    }

    if (!backgroundTexture.loadFromFile("tlokal.jpg")) 
    {
        // obsługa wyjątku
        std::cerr << "Nie można załadować obrazka tła" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);


    for (int i = 1; i < MENU_ITEMS; ++i) {
        sf::Text text;
        text.setFont(font);
        switch (i)
        {
        case 1:
            text.setString("Otworz"); break;
        case 2:
            text.setString("Autorzy"); break;
        case 3:
            text.setString("Wyjdz"); break;
        }
        text.setCharacterSize(40);
        text.setFillColor(sf::Color(63, 63, 63));
        text.setPosition(sf::Vector2f(width / 2 - text.getGlobalBounds().width / 2, height / (MENU_ITEMS + 1) * (0.7*i + 1) + 200));
        menuItems.push_back(text);
    }

    header.setFont(font);
    header.setString("Kalendarz");
    header.setCharacterSize(90);
    header.setFillColor(sf::Color(53, 53, 53));
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 4));
}

void Menu::draw(sf::RenderWindow& window) 
{
    window.draw(backgroundSprite);
    window.draw(header);
    for (const auto& item : menuItems) 
    {
        window.draw(item);
    }
}

void Menu::handleMouseClick(sf::Vector2f mousePos) 
{
    for (const auto& item : menuItems) 
    {
        if (item.getGlobalBounds().contains(mousePos)) 
        {
            if (item.getString() == "Otworz") 
            {
                currentState = State::TimeTable;
            }
            else if (item.getString() == "Autorzy") 
            {
                currentState = State::Authors;
            }
            else if (item.getString() == "Wyjdz") 
            {
                exit(0);
            }
        }
    }
}
