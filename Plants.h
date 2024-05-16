#pragma once
#ifndef Plants_H
#define Plants_H
#include"Entity.h"
#include"Tile.h"
#include <SFML/Graphics.hpp>
#include"Zombie.h"
class Zombie;	
class Plants :public Entity{
public:
	bool plantExists;
	bool typePeaShooter;
	bool typeRepeater;
	bool typeSnowPea;
	bool typeSunFlower;
	bool typeCherryBomb;
	bool typeWalknut;
	Plants(int xPos, int yPos, int h, int w, int);
	~Plants();
	void takeDamage();
	void display(sf::RenderWindow& Window);
	virtual void collisionCheck(Zombie** &zombieEntities,int,Tile**& grid, int& numZom)=0;
	virtual void magic(int& coins1) = 0;
};
#endif