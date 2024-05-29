#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "State.h"

class TimeTable
{
public:
	TimeTable(float width, float height, State& state);
	void draw(sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text test;
	State& currentState;
};

