#pragma once
#ifndef NAMESCREEN_H
#define NAMESCREEN_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Screen.h"
using namespace std;
class NameScreen : public Screen
{
    Button okButton;
    sf::Text text;
    sf::Font font;
    string playerName;
    sf::RectangleShape inputBox;
    sf::Clock inputClock;
    bool nameEntered = false;

public:
    NameScreen();
    ~NameScreen() {}
    void draw(sf::RenderWindow& window);
    bool update(sf::RenderWindow& window, sf::Event& event);
    void handleEvent(const sf::Event& event);
    bool isNameEntered() const;
    string getPlayerName() const;
    Button& getOkButton();
};
#endif