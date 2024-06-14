#include "Authors.h"

using namespace std;


Authors::Authors(float width, float height, State& state) : currentState(state) 
{
    if (!font.loadFromFile("charlotte.ttf")) 
    {
        // obs�uga wyj�tku
    }

    if (!backgroundTexture.loadFromFile("tlokal.jpg"))
    {
        // obs�uga wyj�tku
        std::cerr << "Nie mo�na za�adowa� obrazka t�a" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

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



