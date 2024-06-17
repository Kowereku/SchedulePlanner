#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include "State.h"
#include "Event.h"
#include "DBCal.h"

using namespace std;

constexpr auto ITEMS_TO_CHANGE = 6;

class Changing
{
public:
    Changing(float width, float height, State& state);
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);
    bool checkIfIsDay(string d);
    void updateFields(Event ev);
    int searchID;

private:
    int selectedInputBox = NULL;
    sf::RectangleShape background;
    vector<sf::Text> addItems;
    vector<sf::RectangleShape> inputBoxes;
    sf::RectangleShape inputBox;
    vector<sf::Text> inputTexts;
    sf::Text inputText;
    sf::Font font;
    sf::Text addButton;
    sf::Text backButton;
    sf::Text wrongData;
    State& currentState;
    sf::Clock clock;
    sf::Time refreshTime;
};

