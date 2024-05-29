#pragma once
#include "SFML/Graphics.hpp"

#define ITEMS_IN_MENU 3

class Menu
{
public:
	Menu(float width, float height);

	void draw(sf::RenderWindow& window);

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[ITEMS_IN_MENU];
};

