#pragma once
#ifndef Repeater_H
#define Repeater_H
#include "Shooter.h"
#include "NormalPea.h"
class Repeater : public Shooter
{
public:	
	bool present;
 
	Repeater(int xPos, int yPos, int h, int w, int hit);
	~Repeater();
	void takeDamage();
	void display(sf::RenderWindow & Window);
	void collisionCheck(Zombie**& zombieEntities, int, Tile ** & grid, int& numZom);
	void magic(int& coins1);
	void generatePea();
};
#endif