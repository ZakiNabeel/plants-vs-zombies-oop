#pragma once
#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

public:
    Button(const std::string& label, float width, float height, float posX, float posY);

    void setFont(const std::string& fontPath);
    void draw(sf::RenderWindow& window);
    bool wasClicked(sf::RenderWindow& window, sf::Event& event) const;
};
