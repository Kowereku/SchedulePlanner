#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include "State.h"
#include "DBCal.h"

using namespace std;

constexpr auto ITEMS_TO_ADD = 5;

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
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    vector<sf::Text> addItems;
    vector<sf::RectangleShape> inputBoxes;
    vector<sf::Text> inputTexts;
    sf::Font font;
    sf::Font font_input;
    sf::Text addButton;
    sf::Text backButton;
    sf::Text header;
    sf::Text wrongData;
    State& currentState;
};

