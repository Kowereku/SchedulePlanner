#include "Adding.h"
#include <iostream>

regex timeRegexAdd(R"((0?\d|1\d|2[0-3]):([0-5]?\d))"); // regex czasu

Adding::Adding(float width, float height, State& state) : currentState(state) // konstruktor okna dodawania do bazy danych
{
    if (!font.loadFromFile("charlotte.ttf")) // sprawdzanie, czy zaladowano czcionki i tlo
    {
        std::cerr << "Nie mozna zaladowac czcionki" << std::endl;
    }

    if (!font_input.loadFromFile("Typewriter.ttf"))
    {
        std::cerr << "Nie mozna zaladowac czcionki" << std::endl;
    }
    
    if (!backgroundTexture.loadFromFile("background_add_edit.jpg"))
    {
        std::cerr << "Nie mozna zaladowac obrazka tla" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    for (int i = 0; i < ITEMS_TO_ADD; ++i) // petla tworzaca napisy i input boxy dla kazdego pola w bazie danych
    {
        sf::Text text;
        text.setFont(font_input);
        switch (i)
        {
        case 0:
            text.setString("Nazwa"); break;
        case 1:
            text.setString("Opis"); break;
        case 2:
            text.setString("Dzien tygodnia"); break;
        case 3:
            text.setString("Godzina poczatku \n(format HH:MM)"); break;
        case 4:
            text.setString("Godzina konca \n(format HH:MM)"); break;
        }

        text.setCharacterSize(30);
        text.setFillColor(sf::Color(63, 63, 63));
        text.setPosition(sf::Vector2f(width / 5 - text.getGlobalBounds().width / 10, height / (ITEMS_TO_ADD) * (0.7*i) + 200));
        addItems.push_back(text);

        sf::RectangleShape inputBox;
        inputBox.setSize(sf::Vector2f(width / 4, 50));
        inputBox.setFillColor(sf::Color(235, 213, 196));
        inputBox.setPosition(sf::Vector2f(width /2 - inputBox.getSize().x / 2, height / (ITEMS_TO_ADD) * (0.7 * i) + 200));
        inputBoxes.push_back(inputBox);

        sf::Text inputText;
        
        inputText.setFont(font_input);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(inputBox.getPosition().x + 5, inputBox.getPosition().y + 5);
        inputTexts.push_back(inputText);
    }

    header.setFont(font); // wyswietlanie headera i guzikow
    header.setString("Dodawanie wydarzen");
    header.setCharacterSize(90);
    header.setFillColor(sf::Color(53, 53, 53));
    header.setPosition(sf::Vector2f(width / 2 - header.getGlobalBounds().width / 2, height/27));

    addButton.setFont(font);
    addButton.setCharacterSize(40);
    addButton.setString("Dodaj");
    addButton.setFillColor(sf::Color(63, 63, 63));
    addButton.setPosition(sf::Vector2f(width - 400, height / 3));

    backButton.setFont(font);
    backButton.setCharacterSize(40);
    backButton.setString("Powrot");
    backButton.setFillColor(sf::Color(63, 63, 63));
    backButton.setPosition(sf::Vector2f(width - 400, (height / 3) * 2));

    wrongData.setFont(font_input);
    wrongData.setFillColor(sf::Color::Red);
    wrongData.setCharacterSize(30);
    wrongData.setPosition(sf::Vector2f(width / 2.8 - wrongData.getGlobalBounds().width / 2, height - 100));
}

void Adding::draw(sf::RenderWindow& window) // rysowanie okienka
{
    window.draw(backgroundSprite);
    for (const auto& item : addItems) 
    {
        window.draw(item);
    }
    for (const auto& inputBox : inputBoxes) 
    {
        window.draw(inputBox);
    }
    for (const auto& inputText : inputTexts) 
    {
        window.draw(inputText);
    }
    window.draw(header);
    window.draw(addButton);
    window.draw(backButton);
    window.draw(wrongData);

}

void Adding::handleEvent(sf::Event& event) // obslugiwanie myszki i klawiatury, dodawanie do bazy danych
{
    if (event.type == sf::Event::TextEntered) 
    {
        if (event.text.unicode < 128) 
        {
            if (selectedInputBox >= 0 && selectedInputBox < inputTexts.size()) {
                std::string currentString = inputTexts[selectedInputBox].getString();
                if (event.text.unicode == '\b')
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

                if (regex_match(sh, timeRegexAdd) && regex_match(eh, timeRegexAdd) && checkIfIsDay(d) && inputTexts[0].getString() != "" && inputTexts[1].getString() != "")
                {
                    if (shResult[0] < ehResult[0])
                    {
                        insert(dir, inputTexts[0].getString(), inputTexts[1].getString(), d, sh, eh);
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
                        insert(dir, inputTexts[0].getString(), inputTexts[1].getString(), d, sh, eh);
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
                currentState = State::TimeTable;
                wrongData.setString("");
            }
        }
    }
}

bool Adding::checkIfIsDay(string d) // sprawdzenie czy poprawny dzien
{
    if (d == "Poniedzialek" || d == "Wtorek" || d == "Sroda" || d == "Czwartek" || d == "Piatek" || d == "Sobota" || d == "Niedziela")
    {
        return true;
    }
    else
        return false;
}
