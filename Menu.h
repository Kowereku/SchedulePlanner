#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "State.h"

#define MENU_ITEMS 3



class Menu {
public:
    Menu(float width, float height, State& state);
    void draw(sf::RenderWindow& window);
    void handleMouseClick(sf::Vector2f mousePos);

private:
    std::vector<sf::Text> menuItems;
    sf::Text header;
    sf::Font font;
    State& currentState;
};

