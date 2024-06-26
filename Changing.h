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

constexpr auto ITEMS_TO_CHANGE = 5; // stala do wyswietlania inputow

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
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    vector<sf::Text> addItems;
    vector<sf::RectangleShape> inputBoxes;
    sf::RectangleShape inputBox;
    vector<sf::Text> inputTexts;
    sf::Text inputText;
    sf::Font font;
    sf::Font font_input;
    sf::Text addButton;
    sf::Text header;
    sf::Text backButton;
    sf::Text wrongData;
    State& currentState;
    sf::Clock clock;
    sf::Time refreshTime;
};

