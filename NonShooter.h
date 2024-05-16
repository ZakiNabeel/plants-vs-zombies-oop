#pragma once
#ifndef NonShooter_H
#define NonShooter_H
#include "Plants.h"
class NonShooter : public Plants
{
public:
	// Non-shooter specific methods can be added here
	NonShooter(int xPos, int yPos, int h, int w, int hp);
	~NonShooter();
	void display(sf::RenderWindow &Window);
	void collisionCheck(Zombie** & zombieEntities, int,Tile**& grid, int& numZom);
	void takeDamage();
	void magic(int& coins1);
};
#endif