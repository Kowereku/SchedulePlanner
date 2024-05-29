#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "State.h"

#define DAYS_IN_WEEK 7

class TimeTable
{
public:
	TimeTable(float width, float height, State& state);
	void draw(sf::RenderWindow& window);
	void handleMouseClick(sf::Vector2f mousePos);

private:
	sf::RectangleShape background;
	sf::Font font;
	sf::Text header;
	sf::RectangleShape table[7][10];
	std::vector<sf::Text> days;
	sf::Text tableText;
	sf::Text addButton;
	sf::Text removeButton;
	sf::Text editButton;
	sf::Text backButton;
	State& currentState;
};

