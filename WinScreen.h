#pragma once
#ifndef WINSCREEN_H
#define WINSCREEN_H
#include "Button.h"
#include "Screen.h"
#include <SFML/Graphics.hpp>
class WinScreen : public Screen
{
    Button menuButton;
    sf::RectangleShape backgroundBox;
    sf::Text instructionsText;
    sf::Font font;

public:
    WinScreen();
    ~WinScreen() {}
    void draw(sf::RenderWindow& window);
    bool update(sf::RenderWindow& window, sf::Event& event);
    Button& getMenuButton();
};
#endif