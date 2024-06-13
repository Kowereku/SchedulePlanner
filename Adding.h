#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "State.h"

constexpr auto ITEMS_TO_ADD = 6;

class Adding
{
public:
    Adding(float width, float height, State& state);
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);

private:
    int selectedInputBox = NULL;
    sf::RectangleShape background;
    std::vector<sf::Text> addItems;
    std::vector<sf::RectangleShape> inputBoxes;
    std::vector<sf::Text> inputTexts;
    sf::Font font;
    sf::Text addButton;
    sf::Text backButton;
    State& currentState;
};

