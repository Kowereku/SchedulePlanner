#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "State.h"

#define DAYS_IN_WEEK 7

class Delete
{
public:
	Delete(float width, float height, State& state);
	void draw(sf::RenderWindow& window);
	void handleEventDel(sf::Vector2f event);

private:
	sf::RectangleShape background;
	sf::Font font;
	sf::Text header;
	sf::RectangleShape table[7][10];
	std::vector<sf::Text> days;
	sf::Text tableText;
	sf::Text addButton;
	sf::Text backButton;
	State& currentState;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
};

