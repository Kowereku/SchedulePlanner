#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#define MENU_ITEMS 3

class Menu {
public:
    Menu(float width, float height);
    void draw(sf::RenderWindow& window);
    void handleMouseClick(sf::Vector2f mousePos);

private:
    std::vector<sf::Text> menuItems;
    sf::Text header;
    sf::Font font;
};

