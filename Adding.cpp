#include "Adding.h"
#include "DBCal.h"
#include <iostream>

Adding::Adding(float width, float height, State& state) : currentState(state)
{
    if (!font.loadFromFile("arial.ttf")) {
        // obs³uga wyj¹tku
    }

    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(63, 63, 63)); // Szary kolor t³a

    for (int i = 0; i < ITEMS_TO_ADD; ++i) {
        sf::Text text;
        text.setFont(font);
        switch (i)
        {
        case 0:
            text.setString("Nazwa"); break;
        case 1:
            text.setString("Opis"); break;
        case 2:
            text.setString("Typ"); break;
        case 3:
            text.setString("Dzien tygodnia"); break;
        case 4:
            text.setString("Godzina pocz."); break;
        case 5:
            text.setString("Godzina kon."); break;
        }

        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(width / 10 - text.getGlobalBounds().width / 10, height / (ITEMS_TO_ADD) * i));
        addItems.push_back(text);

        sf::RectangleShape inputBox;
        inputBox.setSize(sf::Vector2f(width / 2, 50));
        inputBox.setFillColor(sf::Color::White);
        inputBox.setPosition(sf::Vector2f(width / 2 - inputBox.getSize().x / 2, height / (ITEMS_TO_ADD * 2) * (i * 2 + 1)));
        inputBoxes.push_back(inputBox);

        sf::Text inputText;
        inputText.setFont(font);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(inputBox.getPosition().x + 5, inputBox.getPosition().y + 5);
        inputTexts.push_back(inputText);
    }

    addButton.setFont(font);
    addButton.setString("Dodaj");
    addButton.setFillColor(sf::Color::White);
    addButton.setPosition(sf::Vector2f(width - 100, height / 3));

    backButton.setFont(font);
    backButton.setString("Powrot");
    backButton.setFillColor(sf::Color::White);
    backButton.setPosition(sf::Vector2f(width - 100, (height / 3) * 2));
}

void Adding::draw(sf::RenderWindow& window) {
    window.draw(background);
    for (const auto& item : addItems) {
        window.draw(item);
    }
    for (const auto& inputBox : inputBoxes) {
        window.draw(inputBox);
    }
    for (const auto& inputText : inputTexts) {
        window.draw(inputText);
    }
    window.draw(addButton);
    window.draw(backButton);
}

void Adding::handleEvent(sf::Event& event) 
{
    if (event.type == sf::Event::TextEntered) 
    {
        if (event.text.unicode < 128) 
        {
            if (selectedInputBox >= 0 && selectedInputBox < inputTexts.size()) {
                std::string currentString = inputTexts[selectedInputBox].getString();
                if (event.text.unicode == '\b') // Obs³uga klawisza backspace
                { 
                    if (!currentString.empty()) 
                    {
                        currentString.pop_back();
                    }
                }
                else if (inputTexts[selectedInputBox].getString().getSize() < 30)
                {
                    currentString += static_cast<char>(event.text.unicode);
                }
                inputTexts[selectedInputBox].setString(currentString);
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        if (event.mouseButton.button == sf::Mouse::Left) {
            for (int i = 0; i < inputBoxes.size(); ++i) {
                if (inputBoxes[i].getGlobalBounds().contains(mousePos)) {
                    selectedInputBox = i;
                    break;
                }
            }
            if (addButton.getGlobalBounds().contains(mousePos))
            {
            insert(dir);
            select(dir);
            currentState = State::TimeTable;
            }
            else if (backButton.getGlobalBounds().contains(mousePos))
            {
                currentState = State::TimeTable;
            }
        }
    }
}