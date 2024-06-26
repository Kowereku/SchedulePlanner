#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Event.h"
#include "State.h"
#include "DBCal.h"
#include "Changing.h"

#define DAYS_IN_WEEK 7 // stala dni w tygodniu

class Editing
{
public:
	Editing(float width, float height, State& state, Changing& changing);
	void draw(sf::RenderWindow& window);
	void handleEventEdit(sf::Vector2f event);
	void updateEvents(float width, float height);
	float widthPub;
	float heightPub;

private:
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
	Changing& changingInstance;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Clock clock;
	sf::Time refreshTime;
};


