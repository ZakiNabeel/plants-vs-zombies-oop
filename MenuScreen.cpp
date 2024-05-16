#include "MenuScreen.h"
#include <iostream>
using namespace std;
MenuScreen::MenuScreen() : Screen("background menu.jpg"),
playButton("Play", 150, 50, 700 - 75, 150), // Centered X, higher Y
scoreboardButton("Scoreboard", 150, 50, 700 - 75, 220), // Same X, slightly lower Y
instructionsButton("Instructions", 150, 50, 700 - 75, 290) {}
void MenuScreen::draw(sf::RenderWindow& window)
{
    window.draw(screenSprite);
    playButton.draw(window);
    scoreboardButton.draw(window);
    instructionsButton.draw(window);
}
bool MenuScreen::update(sf::RenderWindow& window, sf::Event& event)
{
    if (playButton.wasClicked(window, event))
    {
        cout << "Play button was clicked." << endl;
        return true; // Play button was clicked
    }
    else if (instructionsButton.wasClicked(window, event))
    {
        cout << "Instructions button was clicked." << endl;
        return true; // Instruction button was clicked
    }
    if (scoreboardButton.wasClicked(window, event))
    {
        cout << "Scoreboard button was clicked." << endl;
        return true; // Scoreboard button was clicked
    }
    return false; // No action taken
}
Button& MenuScreen::getPlayButton()
{
    return playButton;
}
Button& MenuScreen::getInstructionButton()
{
    return instructionsButton;
}
Button& MenuScreen::getScoreboardButton()
{
    return scoreboardButton;
}