#pragma once
#ifndef Sunflower_H
#define Sunflower_H
#include "Sun.h"
#include "NonShooter.h"
class Sunflower : public NonShooter {
	Sun* sunPtr;
	bool sunGenerated;
public:
	bool present;

	Sunflower(int xPos, int yPos, int h, int w, int hit);
	~Sunflower();
	void display(sf::RenderWindow& Window);
	void takeDamage();
	void collisionCheck(Zombie** & zombieEntities, int, Tile**& grid, int& numZom);
	void generateSun(int& coins1);
	void magic(int& coins1);
};
#endif