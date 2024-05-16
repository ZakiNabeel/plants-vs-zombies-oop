#pragma once
#ifndef Tile_H
#define Tile_H
#include <iostream>
#include<SFML/Graphics.hpp>
using namespace std;
class Tile{
public:
	int xPos;
	int yPos;
	int height;
	int width;
	bool checkPlant;
	sf::RectangleShape rectangleTile;
public:
	Tile();
	Tile(int x, int y);
	~Tile();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getHeight();
	int getWidth();
	bool getSpace();
	void display(sf::RenderWindow& Window);
	void setGridPosition(int x, int y);
};
#endif