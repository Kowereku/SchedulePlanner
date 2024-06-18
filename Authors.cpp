#include "Authors.h"

using namespace std;


Authors::Authors(float width, float height, State& state) : currentState(state) 
{
    if (!font.loadFromFile("charlotte.ttf")) // sprawdzenei czcionki i tla
    {
        std::cerr << "Nie mozna zaladowac czcionki" << std::endl;
    }

    if (!fontTypewriter.loadFromFile("Typewriter.ttf"))
    {
        std::cerr << "Nie mozna zaladowac czcionki" << std::endl;
    }

    if (!backgroundTexture.loadFromFile("tlokal.jpg"))
    {
        std::cerr << "Nie mozna zaladowac obrazka tla" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    sf::Text text;
    text.setFont(font);


    header.setFont(font); // wyswietlanie autorow
    header.setString("Autorzy");
    header.setCharacterSize(90);
    header.setFillColor(sf::Color(53, 53, 53));
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 4));

    authorNames.setFont(fontTypewriter);

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

    backButton.setFont(font); // guzik powrot
    backButton.setCharacterSize(50);
    backButton.setString("Powrot");
    backButton.setFillColor(sf::Color(63, 63, 63));
    backButton.setPosition(sf::Vector2f(width / 2 - backButton.getGlobalBounds().width /2, height / (4 + 1) * (0.7 * 3 + 1) + 200));

}


void Authors::draw(sf::RenderWindow& window) // rysowanie guzika
{
    window.draw(backgroundSprite);
    window.draw(header);
    window.draw(backButton);
    for (const auto& txt : listAuthors)
    {
        window.draw(txt);
    }
}

void Authors::handleMouseClick(sf::Vector2f mousePos) // obsluga myszki
{
    if (backButton.getGlobalBounds().contains(mousePos))
    {
        currentState = State::Menu;

    }
}



