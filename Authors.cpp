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

    sf::Text text;
    text.setFont(font);


    header.setFont(font);
    header.setString("Autorzy");
    header.setCharacterSize(90);
    header.setFillColor(sf::Color(53, 53, 53));
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 4));

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
    for (const auto& txt : displayTexts)
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



