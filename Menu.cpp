#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// error handler;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Otworz");
	menu[0].setPosition(sf::Vector2f((width / 2) - 40, height / (ITEMS_IN_MENU + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Opcje");
	menu[1].setPosition(sf::Vector2f((width / 2) - 40, height / (ITEMS_IN_MENU + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Wyjdz");
	menu[2].setPosition(sf::Vector2f((width / 2) - 40, height / (ITEMS_IN_MENU + 1) * 3));

}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < ITEMS_IN_MENU; i++)
	{
		window.draw(menu[i]);
	}
}