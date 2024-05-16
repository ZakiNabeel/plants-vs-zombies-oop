#pragma once
#ifndef Entity_h
#define Entity_h
#include"Size.h"
#include"Position.h"
#include"Sprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Entity {
protected:
public:
	Position position;
	Size size;
	int hitPoints;
	Sprite spriteEntity;
	Entity(int xPos, int yPos, int h, int w, int);
	virtual ~Entity();
	void takeDamage();
	virtual void display(sf::RenderWindow& Window)=0;
	bool healthCheck();
};
#endif // !Entity_h
