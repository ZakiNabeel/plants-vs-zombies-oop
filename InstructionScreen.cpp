#include "InstructionScreen.h"
InstructionScreen::InstructionScreen() : Screen("INSTRUCTIONSCREEN.jpg"), backButton("Back", 150, 50, 700 - 75, 500)
{
    backgroundBox.setSize(sf::Vector2f(800, 300));
    backgroundBox.setPosition(250, 150);
    backgroundBox.setFillColor(sf::Color(128, 128, 128, 200));

    font.loadFromFile("SFUIText-Bold.ttf");
    instructionsText.setFont(font);
    instructionsText.setString("How to play:\n\n- Place plants to aid in killing the zombies. \n- Do not let the zombies reach the end.\n- Collect the sun currency to place plants. \n- Most importantly, enjoy!");
    instructionsText.setCharacterSize(32);
    instructionsText.setFillColor(sf::Color::White);
    instructionsText.setPosition(270, 170);
}
void InstructionScreen::draw(sf::RenderWindow& window)
{
    window.draw(screenSprite);
    backButton.draw(window);
    window.draw(backgroundBox);
    window.draw(instructionsText);
}
bool InstructionScreen::update(sf::RenderWindow& window, sf::Event& event)
{
    if (backButton.wasClicked(window, event))
    {
        cout << "Instruction button was clicked." << endl;
        return true; // Instruction button was clicked
    }
    return false;
}
Button& InstructionScreen::getBackButton()
{
    return backButton;
}