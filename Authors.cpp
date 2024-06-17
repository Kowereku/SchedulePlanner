#include "Authors.h"

using namespace std;


Authors::Authors(float width, float height, State& state) : currentState(state) 
{
    if (!font.loadFromFile("charlotte.ttf")) 
    {
        // obs�uga wyj�tku
    }

    if (!fontTypewriter.loadFromFile("Typewriter.ttf"))
    {
        // obs�uga wyj�tku
    }

    if (!backgroundTexture.loadFromFile("tlokal.jpg"))
    {
        // obs�uga wyj�tku
        std::cerr << "Nie mo�na za�adowa� obrazka t�a" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    sf::Text text;
    text.setFont(font);


    header.setFont(font);
    header.setString("Autorzy");
    header.setCharacterSize(90);
    header.setFillColor(sf::Color(53, 53, 53));
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 4));

    authorNames.setFont(fontTypewriter);
    //authorNames.setString("Martyna Szandala \nPawel Zambrzycki\nInformatyka (profil praktyczny) \nII semestr");
    for (int i = 0; i < 4; ++i) 
    {
        sf::Text text;
        text.setFont(fontTypewriter);
        switch (i)
        {
        case 0:
            text.setString("Martyna Szandala"); break;
        case 1:
            text.setString("Pawel Zambrzycki"); break;
        case 2:
            text.setString("Informatyka (profil praktyczny)"); break;
        case 3:
            text.setString("II semestr"); break;
        }
        text.setCharacterSize(30);
        text.setFillColor(sf::Color(53, 53, 53));
        text.setPosition(sf::Vector2f(width / 2 - text.getGlobalBounds().width / 2, height / (8) * (0.7 * i + 1) + 300));
        listAuthors.push_back(text);
        }

    //authorNames.setString("");
    //authorNames.setString("");
    //authorNames.setString("");
    //authorNames.setString("");
    //authorNames.setCharacterSize(40);
    //authorNames.setFillColor(sf::Color(53, 53, 53));
    /*authorNames.setPosition(sf::Vector2f(width / 2 - authorNames.getGlobalBounds().width / 2, height / 2));*/



    backButton.setFont(font);
    backButton.setCharacterSize(50);
    backButton.setString("Powrot");
    backButton.setFillColor(sf::Color(63, 63, 63));
    backButton.setPosition(sf::Vector2f(width / 2 - backButton.getGlobalBounds().width /2, height / (4 + 1) * (0.7 * 3 + 1) + 200));

}


void Authors::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(header);
    window.draw(backButton);
    for (const auto& txt : listAuthors)
    {
        window.draw(txt);
    }
}

void Authors::handleMouseClick(sf::Vector2f mousePos)
{
    if (backButton.getGlobalBounds().contains(mousePos))
    {
        currentState = State::Menu;

    }
}



