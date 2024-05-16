#include "WinScreen.h"
#include <iostream>
WinScreen::WinScreen() : Screen("GameVictory.jpg"), menuButton("Back to Menu", 150, 50, 700 - 75, 500)
{
    backgroundBox.setSize(sf::Vector2f(400, 200));
    backgroundBox.setPosition(250, 150);
    backgroundBox.setFillColor(sf::Color(128, 128, 128, 200));

    font.loadFromFile("SFUIText-Bold.ttf");
    instructionsText.setFont(font);
    instructionsText.setString("Congratulations! You Won!!!");
    instructionsText.setCharacterSize(32);
    instructionsText.setFillColor(sf::Color::White);
    instructionsText.setPosition(270, 170);
}
void WinScreen::draw(sf::RenderWindow& window)
{
    window.draw(screenSprite);
    menuButton.draw(window);
    window.draw(backgroundBox);
    window.draw(instructionsText);
}
bool WinScreen::update(sf::RenderWindow& window, sf::Event& event)
{
    if (menuButton.wasClicked(window, event))
    {
        cout << "Instruction button was clicked." << endl;
        return true; // Instruction button was clicked
    }
    return false;
}
Button& WinScreen::getMenuButton()
{
    return menuButton;
}