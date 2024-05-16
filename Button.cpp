#include "Button.h"

Button::Button(const std::string& label, float width, float height, float posX, float posY) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(posX, posY));

    font.loadFromFile("SFUIText-Bold.ttf");  
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);  
    text.setFillColor(sf::Color::Black);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(posX + width / 2.0f, posY + height / 2.0f);
}

void Button::setFont(const std::string& fontPath) {
    font.loadFromFile(fontPath);
    text.setFont(font);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool Button::wasClicked(sf::RenderWindow& window, sf::Event& event) const {
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    bool isOver = mouseX >= shape.getPosition().x &&
        mouseX <= (shape.getPosition().x + shape.getSize().x) &&
        mouseY >= shape.getPosition().y &&
        mouseY <= (shape.getPosition().y + shape.getSize().y);

    return isOver && event.type == sf::Event::MouseButtonReleased &&
        event.mouseButton.button == sf::Mouse::Left;
}
