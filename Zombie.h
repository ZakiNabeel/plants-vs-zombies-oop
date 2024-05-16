#pragma once
#ifndef Zombie_h
#define Zombie_h
#include"iostream"
#include"Moving.h"
#include"Plants.h"
using namespace std;
class Plants;
class Zombie :public Moving {
public:
	bool typeDancer;
	bool NorthWest;
	bool SouthWest;
	bool right;
	Zombie(int xPos, int yPos, int h, int w, int hit, int s);
	~Zombie();
	void movement();
	void takeDamage();
	void display(sf::RenderWindow& Window);
	void collisionCheck(Plants** & plantEntites,int size);
};
#endif // !Zombie_h

