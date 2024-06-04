#include "TimeTable.h"
#include "DBCal.h"

TimeTable::TimeTable(float width, float height, State& state) : currentState(state)
{
    if (!font.loadFromFile("Calligraphy.ttf")) {
        // obsługa wyjąku
    }

    select(dir);


    if (!backgroundTexture.loadFromFile("tlokal_2.jpg"))
    {
        // obsługa wyjątku
        std::cerr << "Nie można załadować obrazka tła" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    //background.setSize(sf::Vector2f(width, height));
    //background.setFillColor(sf::Color(63, 63, 63)); // Szary kolor tła

    header.setFont(font);
    header.setString("Plan Tygodnia");
    header.setCharacterSize(70);
    header.setFillColor(sf::Color::Black);
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 40 - 30 ));

    float cellWidth = width / 8;
    float cellHeight = height / 15;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 10; ++j) {
            table[i][j].setSize(sf::Vector2f(cellWidth, cellHeight));
            table[i][j].setOutlineColor(sf::Color::Black);
            table[i][j].setOutlineThickness(1);
            table[i][j].setPosition(sf::Vector2f((i+0.5) * cellWidth, j * cellHeight + 100));
            if (j == 0)
            {
                table[i][j].setFillColor(sf::Color(255, 253, 141));
            }
        }
    }
    
    for (int i = 0; i < DAYS_IN_WEEK; ++i) {
        sf::Text text;
        text.setFont(font);
        switch (i)
        {
        case 0:
            text.setString("Poniedzialek"); break;
        case 1:
            text.setString("Wtorek"); break;
        case 2:
            text.setString("Sroda"); break;
        case 3:
            text.setString("Czwartek"); break;
        case 4:
            text.setString("Piatek"); break;
        case 5:
            text.setString("Sobota"); break;
        case 6:
            text.setString("Niedziela"); break;
        }

        text.setFillColor(sf::Color::Black);
        text.setPosition(sf::Vector2f(sf::Vector2f((i + 1) * cellWidth - text.getGlobalBounds().width / 2, 120)));
        days.push_back(text);
    }

    addButton.setFont(font);
    addButton.setCharacterSize(50);
    addButton.setString("Dodaj wydarzenie");
    addButton.setFillColor(sf::Color::Black);
    addButton.setPosition(sf::Vector2f(width / 4 - addButton.getGlobalBounds().width / 2, height - 180));

    removeButton.setFont(font);
    removeButton.setCharacterSize(50);
    removeButton.setString("Usun wydarzenie");
    removeButton.setFillColor(sf::Color::Black);
    removeButton.setPosition(sf::Vector2f(2 * width / 4 - removeButton.getGlobalBounds().width / 2, height - 180));

    editButton.setFont(font);
    editButton.setCharacterSize(50);
    editButton.setString("Edytuj wydarzenie");
    editButton.setFillColor(sf::Color::Black);
    editButton.setPosition(sf::Vector2f(3 * width / 4 - editButton.getGlobalBounds().width / 2, height - 180));

    backButton.setFont(font);
    backButton.setCharacterSize(50);
    backButton.setString("Powrot");
    backButton.setFillColor(sf::Color::Black);
    backButton.setPosition(sf::Vector2f(width / 2 - backButton.getGlobalBounds().width / 2, height - 100));
}

void TimeTable::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(header);
    for (int i = 0; i < 7; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            window.draw(table[i][j]);
        }
    }
    for (const auto& day : days) 
    {
        window.draw(day);
    }
    window.draw(addButton);
    window.draw(removeButton);
    window.draw(editButton);
    window.draw(backButton);
}

void TimeTable::handleMouseClick(sf::Vector2f mousePos) 
{
    if (addButton.getGlobalBounds().contains(mousePos)) 
    {
        insert(dir);
        select(dir);
    }
    else if (removeButton.getGlobalBounds().contains(mousePos)) 
    {
        delate(dir);
        select(dir);
    }
    else if (editButton.getGlobalBounds().contains(mousePos)) 
    {
        update(dir);
        select(dir);
    } 
    else if (backButton.getGlobalBounds().contains(mousePos)) 
    {
        currentState = State::Menu;
    }
}