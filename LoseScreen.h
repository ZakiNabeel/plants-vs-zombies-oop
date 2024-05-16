#pragma once
#ifndef LOSESCREEN_H
#define LOSESCREEN_H
#include "Button.h"
#include "Screen.h"
#include <SFML/Graphics.hpp>
class LoseScreen : public Screen
{
    Button menuButton;
    sf::RectangleShape backgroundBox;
    sf::Text instructionsText;
    sf::Font font;

public:
    LoseScreen();
    ~LoseScreen() {}
    void draw(sf::RenderWindow& window);
    bool update(sf::RenderWindow& window, sf::Event& event);
    Button& getMenuButton();
};
#endif

