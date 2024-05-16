#pragma once
#ifndef WhitePea_h
#define WhitePea_h
#include"Pea.h"
class WhitePea :public Pea {
public:
	WhitePea();
	WhitePea(int xPos, int yPos, int h, int w, int hit, int s);
	~WhitePea();
	void display(sf::RenderWindow& Window);
	void collisionCheck(Zombie**& zombieEntities, int, bool& peaGenerated, int& numZom);
	void movement();
	void takeDamage();
	sf::Sprite getSpriteEntity();

};
#endif // !WhitePea_h

