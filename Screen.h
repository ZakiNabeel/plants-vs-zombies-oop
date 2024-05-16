#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "SFML/Graphics.hpp"
#include "Button.h"
using namespace std;
class Screen
{
protected:
	sf::Texture screenTexture;
	sf::Sprite screenSprite;
public:
	Screen();
	Screen(const string& backgroundImagePath);
	~Screen() {}
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual bool update(sf::RenderWindow& window, sf::Event& event) = 0;
};
#endif
