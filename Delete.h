#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Event.h"
#include "State.h"
#include "DBCal.h"

#define DAYS_IN_WEEK 7

class Delete
{
public:
	Delete(float width, float height, State& state);
	void draw(sf::RenderWindow& window);
	void handleEventDel(sf::Vector2f event);
	void updateEvents(float width, float height);
	float widthPub;
	float heightPub;

private:
	sf::RectangleShape background;
	sf::Font font;
	sf::Font fontTypewriter;
	sf::Text header;
	sf::RectangleShape table[7][10];
	std::vector<sf::Text> days;
	std::vector<Event> display;
	std::vector<sf::Text> displayTexts;
	std::vector<int> displayIds;
	sf::Text tableText;
	sf::Text addButton;
	sf::Text backButton;
	State& currentState;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Clock clock;
	sf::Time refreshTime;
};

