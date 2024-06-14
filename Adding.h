#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include "State.h"

using namespace std;

constexpr auto ITEMS_TO_ADD = 6;

class Adding
{
public:
    Adding(float width, float height, State& state);
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);
    bool checkIfIsDay(string d);

private:
    int selectedInputBox = NULL;
    sf::RectangleShape background;
    vector<sf::Text> addItems;
    vector<sf::RectangleShape> inputBoxes;
    vector<sf::Text> inputTexts;
    sf::Font font;
    sf::Text addButton;
    sf::Text backButton;
    State& currentState;
};

