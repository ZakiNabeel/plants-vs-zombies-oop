#include "NameScreen.h"
#include <iostream>
NameScreen::NameScreen() : Screen("INSTRUCTIONSCREEN.jpg"), okButton("OK", 150, 50, 700 - 75, 500)
{
    font.loadFromFile("SFUIText-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);
    text.setString("Enter your name: ");

    inputBox.setSize(sf::Vector2f(600, 50));
    inputBox.setPosition(95, 95);
    inputBox.setFillColor(sf::Color(50, 50, 50, 200));
}

void NameScreen::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        if (inputClock.getElapsedTime().asMilliseconds() > 150) { // Limit input to every 100 ms
            if (event.text.unicode < 128) {
                if (event.text.unicode == '\b' && !playerName.empty()) {
                    playerName.pop_back();
                }
                else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    playerName += static_cast<char>(event.text.unicode);
                }
                text.setString("Enter your name: " + playerName);
                inputClock.restart(); // Restart the clock after handling input
            }
        }
    }
}

void NameScreen::draw(sf::RenderWindow& window) {
    window.draw(text);
    window.draw(inputBox);
    okButton.draw(window);
}

bool NameScreen::update(sf::RenderWindow& window, sf::Event& event)
{
    if (okButton.wasClicked(window, event))
    {
        cout << "Instruction button was clicked." << endl;
        return true; // Instruction button was clicked
    }
    return false;
}

bool NameScreen::isNameEntered() const {
    return nameEntered;
}

string NameScreen::getPlayerName() const {
    return playerName;
}
Button& NameScreen::getOkButton()
{
    return okButton;
}