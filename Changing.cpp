#include "Changing.h"
#include <iostream>

regex timeRegexChange(R"((0?\d|1\d|2[0-3]):([0-5]?\d))");

Changing::Changing(float width, float height, State& state) : currentState(state)
{
    if (!font.loadFromFile("arial.ttf")) {
        // obs�uga wyj�tku
    }

    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(63, 63, 63)); // Szary kolor t�a

    for (int i = 0; i < ITEMS_TO_CHANGE; ++i) {
        sf::Text text;
        text.setFont(font);
        switch (i)
        {
        case 0:
            text.setString("Nazwa"); break;
        case 1:
            text.setString("Opis"); break;
        case 2:
            text.setString("Dzien tygodnia"); break;
        case 3:
            text.setString("Godzina poczatku (format HH:MM)"); break;
        case 4:
            text.setString("Godzina konca (format HH:MM)"); break;
        }

        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(width / 10 - text.getGlobalBounds().width / 10, height / (ITEMS_TO_CHANGE)*i));
        addItems.push_back(text);

        inputBox.setSize(sf::Vector2f(width / 2, 50));
        inputBox.setFillColor(sf::Color::White);
        inputBox.setPosition(sf::Vector2f(width / 2 - inputBox.getSize().x / 2, height / (ITEMS_TO_CHANGE * 2) * (i * 2 + 1)));
        inputBoxes.push_back(inputBox);

        inputText.setFont(font);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(inputBox.getPosition().x + 5, inputBox.getPosition().y + 5);
        inputTexts.push_back(inputText);
    }

    addButton.setFont(font);
    addButton.setString("Zmien");
    addButton.setFillColor(sf::Color::White);
    addButton.setPosition(sf::Vector2f(width - 100, height / 3));

    backButton.setFont(font);
    backButton.setString("Powrot");
    backButton.setFillColor(sf::Color::White);
    backButton.setPosition(sf::Vector2f(width - 100, (height / 3) * 2));

    wrongData.setFont(font);
    wrongData.setFillColor(sf::Color::Red);
    wrongData.setPosition(sf::Vector2f(width - 600, height / 2));
}

void Changing::draw(sf::RenderWindow& window) {

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
    window.draw(wrongData);
}

void Changing::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128)
        {
            if (selectedInputBox >= 0 && selectedInputBox < inputTexts.size()) {
                std::string currentString = inputTexts[selectedInputBox].getString();
                if (event.text.unicode == '\b') // Obsluga klawisza backspace
                {
                    if (!currentString.empty())
                    {
                        currentString.pop_back();
                    }
                }
                else if (inputTexts[selectedInputBox].getString().getSize() < 20)
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
                string d = inputTexts[2].getString();
                d[0] = toupper(d[0]);
                for (int k = 1; k < d.size(); k++)
                {
                    d[k] = tolower(d[k]);
                }
                string sh = inputTexts[3].getString();
                string eh = inputTexts[4].getString();

                stringstream shTest(sh);
                string shTemp;
                vector<int> shResult;
                while (getline(shTest, shTemp, ':'))
                {
                    shResult.push_back(stoi(shTemp));
                }

                stringstream ehTest(eh);
                string ehTemp;
                vector<int> ehResult;
                while (getline(ehTest, ehTemp, ':'))
                {
                    ehResult.push_back(stoi(ehTemp));
                }

                if (regex_match(sh, timeRegexChange) && regex_match(eh, timeRegexChange) && checkIfIsDay(d) && inputTexts[0].getString() != "" && inputTexts[1].getString() != "")
                {
                    if (shResult[0] < ehResult[0])
                    {
                        update(dir, searchID , inputTexts[0].getString(), inputTexts[1].getString(), d, sh, eh);
                        inputTexts[0].setString("");
                        inputTexts[1].setString("");
                        inputTexts[2].setString("");
                        inputTexts[3].setString("");
                        inputTexts[4].setString("");
                        currentState = State::TimeTable;
                        wrongData.setString("");
                    }
                    else if (shResult[0] == ehResult[0] && shResult[1] < ehResult[1])
                    {
                        update(dir, searchID, inputTexts[0].getString(), inputTexts[1].getString(), d, sh, eh);
                        inputTexts[0].setString("");
                        inputTexts[1].setString("");
                        inputTexts[2].setString("");
                        inputTexts[3].setString("");
                        inputTexts[4].setString("");
                        currentState = State::TimeTable;
                        wrongData.setString("");
                    }
                    else
                    {
                        wrongData.setString("Wprowadzono niepoprawne dane!");
                    }
                }
                else
                {
                    wrongData.setString("Wprowadzono niepoprawne dane!");
                }
            }
            else if (backButton.getGlobalBounds().contains(mousePos))
            {
                currentState = State::Editing;
            }
        }
    }
}

bool Changing::checkIfIsDay(string d)
{
    if (d == "Poniedzialek" || d == "Wtorek" || d == "Sroda" || d == "Czwartek" || d == "Piatek" || d == "Sobota" || d == "Niedziela")
    {
        return true;
    }
    else
        return false;
}

void Changing::updateFields(Event ev)
{
    inputTexts[0].setString(ev.name);
    inputTexts[1].setString(ev.desc);
    inputTexts[2].setString(ev.day);
    inputTexts[3].setString(ev.starth);
    inputTexts[4].setString(ev.endh);
}
