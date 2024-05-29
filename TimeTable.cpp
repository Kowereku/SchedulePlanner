#include "TimeTable.h"

TimeTable::TimeTable(float width, float height, State& state) : currentState(state)
{
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
    }

    test.setFont(font);
    test.setString("test");
    test.setFillColor(sf::Color::White);
    test.setPosition(sf::Vector2f(width / 2, height / 2));
}

void TimeTable::draw(sf::RenderWindow& window)
{
    window.draw(test);
}