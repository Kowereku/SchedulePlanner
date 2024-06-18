#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "State.h"
#include "Event.h"
#include "DBCal.h"

using namespace std;

#define DAYS_IN_WEEK 7

class TimeTable
{
public:
	TimeTable(float width, float height, State& state);
	void draw(sf::RenderWindow& window);
	void handleMouseClick(sf::Vector2f mousePos);
	void updateEvents(float width, float height);
	float widthPub;
	float heightPub;

private:
	sf::Font font;
	sf::Font fontTypewriter;
	sf::Text header;
	sf::RectangleShape table[7][10];
	vector<sf::Text> days;
	vector<Event> display;
	vector<sf::Text> displayTexts;
	sf::Text tableText;
	sf::Text addButton;
	sf::Text removeButton;
	sf::Text editButton;
	sf::Text backButton;
	State& currentState;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Clock clock;
	sf::Time refreshTime;
};

