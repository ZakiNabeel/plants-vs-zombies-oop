#pragma once
#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include "Screen.h"
#include "Button.h"
class MenuScreen : public Screen
{
	Button playButton;
	Button scoreboardButton;
	Button instructionsButton;
public:
	bool buttonClicked = 0;
	MenuScreen();
	~MenuScreen() {};
	void draw(sf::RenderWindow& window);
	bool update(sf::RenderWindow& window, sf::Event& event);
	Button& getPlayButton();
	Button& getScoreboardButton();
	Button& getInstructionButton();
};
#endif