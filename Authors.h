#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "State.h"


class Authors {
public:
    Authors(float width, float height, State& state);
    void draw(sf::RenderWindow& window);
    void handleMouseClick(sf::Vector2f mousePos);

private:
    sf::RectangleShape background;
    std::vector<sf::Text> menuItems;
    std::vector<sf::Text> displayTexts;
    std::vector<sf::Text> listAuthors;
    sf::Text header;
    sf::Text authorNames;
    sf::Text backButton;
    sf::Font font;
    sf::Font fontTypewriter;
    State& currentState;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

};

