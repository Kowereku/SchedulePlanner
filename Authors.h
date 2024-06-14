#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Authors.h"
#include "State.h"

constexpr auto MENU_ITEMS = 1;



class Authors {
public:
    Authors(float width, float height, State& state);
    void draw(sf::RenderWindow& window);
    void handleMouseClick(sf::Vector2f mousePos);

private:
    sf::RectangleShape background;
    std::vector<sf::Text> menuItems;
    sf::Text header;
    sf::Font font;
    State& currentState;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

};

