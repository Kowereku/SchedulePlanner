#include "Editing.h"

Editing::Editing(float width, float height, State& state, Changing& changing) : currentState(state), changingInstance(changing)
{
    if (!font.loadFromFile("Calligraphy.ttf")) {
        // obs�uga wyj�ku
    }

    if (!backgroundTexture.loadFromFile("tlokal_2.jpg"))
    {
        // obs�uga wyj�tku
        std::cerr << "Nie mo�na za�adowa� obrazka t�a" << std::endl;
    }

    widthPub = width;
    heightPub = height;

    display = select(dir);
    clock.restart();
    updateEvents(width, height);

    backgroundSprite.setTexture(backgroundTexture);


    header.setFont(font);
    header.setString("Plan Tygodnia");
    header.setCharacterSize(70);
    header.setFillColor(sf::Color::Black);
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height / 40 - 30));

    float cellWidth = width / 8;
    float cellHeight = height / 15;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 10; ++j) {
            table[i][j].setSize(sf::Vector2f(cellWidth, cellHeight));
            table[i][j].setOutlineColor(sf::Color::Black);
            table[i][j].setOutlineThickness(1);
            table[i][j].setPosition(sf::Vector2f((i + 0.5) * cellWidth, j * cellHeight + 100));
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

    backButton.setFont(font);
    backButton.setCharacterSize(50);
    backButton.setString("Powrot");
    backButton.setFillColor(sf::Color::Black);
    backButton.setPosition(sf::Vector2f(width / 2 - backButton.getGlobalBounds().width / 2, height - 100));
}

void Editing::draw(sf::RenderWindow& window)
{
    if (clock.getElapsedTime() > refreshTime)
    {
        updateEvents(widthPub, heightPub);
        clock.restart();
    }
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
    window.draw(backButton);
    for (const auto& txt : displayTexts)
    {
        window.draw(txt);
    }
}

void Editing::handleEventEdit(sf::Vector2f event)
{
    if (backButton.getGlobalBounds().contains(event))
    {
        currentState = State::TimeTable;
    }
    for (int i = 0; i < displayTexts.size(); ++i)
    {
        if (displayTexts[i].getGlobalBounds().contains(event))
        {
            int eventId = displayIds[i];
            auto found = std::find_if(display.begin(), display.end(), [eventId](const Event& event) {
                return event.id == eventId;
                });
            if (found != display.end())
            {
                changingInstance.searchID = found->id;
                changingInstance.updateFields(*found);
                currentState = State::Changing;
            }
            break;
        }
    }
}

void Editing::updateEvents(float width, float height)
{
    display = select(dir);
    displayTexts.clear();
    int counterPon = 1;
    int counterWt = 1;
    int counterSr = 1;
    int counterCzw = 1;
    int counterPt = 1;
    int counterSob = 1;
    int counterNd = 1;
    for (const auto& event : display)
    {
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::Black);

        std::string eventDetails = event.name + "\n" +
            event.desc + "\n" +
            event.starth + " - " + event.endh;

        if (event.day == "Poniedzialek" && counterPon <= 9)
        {
            text.setPosition(sf::Vector2f((0.5) * width / 8 + 10, counterPon * height / 15 + 98));
            counterPon++;
        }
        else if (event.day == "Wtorek" && counterWt <= 9)
        {
            text.setPosition(sf::Vector2f((1.5) * width / 8 + 10, counterWt * height / 15 + 98));
            counterWt++;
        }
        else if (event.day == "Sroda" && counterSr <= 9)
        {
            text.setPosition(sf::Vector2f((2.5) * width / 8 + 10, counterSr * height / 15 + 98));
            counterSr++;
        }
        else if (event.day == "Czwartek" && counterCzw <= 9)
        {
            text.setPosition(sf::Vector2f((3.5) * width / 8 + 10, counterCzw * height / 15 + 98));
            counterCzw++;
        }
        else if (event.day == "Piatek" && counterPt <= 9)
        {
            text.setPosition(sf::Vector2f((4.5) * width / 8 + 10, counterPt * height / 15 + 98));
            counterPt++;
        }
        else if (event.day == "Sobota" && counterSob <= 9)
        {
            text.setPosition(sf::Vector2f((5.5) * width / 8 + 10, counterSob * height / 15 + 98));
            counterSob++;
        }
        else if (event.day == "Niedziela" && counterNd <= 9)
        {
            text.setPosition(sf::Vector2f((6.5) * width / 8 + 10, counterNd * height / 15 + 100));
            counterNd++;
        }
        text.setString(eventDetails);
        displayTexts.push_back(text);
        displayIds.push_back(event.id);
    }
}

