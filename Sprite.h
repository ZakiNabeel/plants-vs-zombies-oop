#pragma once
#ifndef Sprite_h
#define Sprite_h
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Sprite {
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clockEntity;
	bool coordinateLeftTouch = 1;
	bool coordinateRightTouch = 0;
	Sprite();
	~Sprite();
};
#endif // !Sprite_h

