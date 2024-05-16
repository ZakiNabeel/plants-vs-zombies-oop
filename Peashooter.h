#pragma once
#ifndef Peashooter_H
#define Peashooter_H
#include "Shooter.h"
#include "SFML/Graphics.hpp"
#include "NormalPea.h"
class Peashooter : public Shooter
{
public:
	bool present;
	Peashooter(int xPos, int yPos, int h, int w, int hit);
	~Peashooter();
	void takeDamage();
	void display(sf::RenderWindow & Window);
	void collisionCheck(Zombie**& zombieEntities,int, Tile**& grid, int& numZom);
	void magic(int& coins1);
	void generatePea();
	bool isPresent();
};
#endif