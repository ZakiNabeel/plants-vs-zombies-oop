#pragma once
#ifndef Pea_h
#define Pea_h
#include<iostream>
using namespace std;
#include"Moving.h"
#include"Zombie.h"
class Pea : public Moving {
public:	
	bool isPresent;
	Pea(int xPos, int yPos, int h, int w, int hit, int s);
	virtual ~Pea();
	void display(sf::RenderWindow& Window);
	void movement();
	virtual void collisionCheck(Zombie**& zombieEntities, int, bool &, int& numZom)=0;
	void takeDamage();
	void setX(int);
	void setY(int);
	void setH(int);
	void setW(int);
	void setHit(int);
	void setSpeed(int);
	//void isPresent();
	virtual sf::Sprite getSpriteEntity() = 0;

	//Take Damage is removed
};
#endif // !Pea_h

