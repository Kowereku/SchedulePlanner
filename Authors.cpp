#include "Authors.h"

using namespace std;


Authors::Authors(float width, float height, State& state) : currentState(state) 
{
    if (!font.loadFromFile("charlotte.ttf")) 
    {
        // obs³uga wyj¹tku
    }

    if (!backgroundTexture.loadFromFile("tlokal.jpg"))
    {
        // obs³uga wyj¹tku
        std::cerr << "Nie mo¿na za³adowaæ obrazka t³a" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);


    for (int i = 0; i < MENU_ITEMS; ++i) {
        sf::Text text;
        text.setFont(font);
        switch (i)
        {
        case 0:
            text.setString("Wydz"); break;
        }
        text.setCharacterSize(40);
        text.setFillColor(sf::Color(63, 63, 63));
        text.setPosition(sf::Vector2f(width / 2 - text.getGlobalBounds().width / 2, height / (MENU_ITEMS + 1) * (0.7 * i + 1) + 200));
        menuItems.push_back(text);
    }


    header.setFont(font);
    header.setString("Kalendarz");
    header.setCharacterSize(90);
    header.setFillColor(sf::Color(53, 53, 53));
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 6));
}

void Authors::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(header);
    for (const auto& item : menuItems)
    {
        window.draw(item);
    }
}

void Authors::handleMouseClick(sf::Vector2f mousePos)
{
    for (const auto& item : menuItems)
    {
        if (item.getGlobalBounds().contains(mousePos))
        {
            if (item.getString() == "Otworz")
            {
                currentState = State::TimeTable;
            }
            else if (item.getString() == "Opcje")
            {
                cout << "Wcisnieto opcje" << endl;
            }
            else if (item.getString() == "Autorzy")
            {
                cout << "Wcisnieto autorzy" << endl;
            }
            else if (item.getString() == "Wyjdz")
            {
                exit(0);
            }
        }
    }
}



