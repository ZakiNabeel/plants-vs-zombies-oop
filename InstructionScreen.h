#pragma once
#ifndef INSTRUCTIONSCREEN_H
#define INSTRUCTIONSCREEN_H
#include "SFML/Graphics.hpp"
#include "Screen.h"
#include "Button.h"
#include <iostream>
using namespace std;
class InstructionScreen : public Screen
{
    Button backButton;
    sf::RectangleShape backgroundBox;
    sf::Text instructionsText;
    sf::Font font;

public:
    InstructionScreen();
    ~InstructionScreen() {}
    void draw(sf::RenderWindow& window);
    bool update(sf::RenderWindow& window, sf::Event& event);
    Button& getBackButton();
};
#endif