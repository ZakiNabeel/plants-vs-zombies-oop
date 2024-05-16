#pragma once
#ifndef NormalPea_h
#define NormalPea_h
#include"Pea.h"
class NormalPea : public Pea {
public:	
	NormalPea(int xPos, int yPos, int h, int w, int hit, int s);
	NormalPea();
	~NormalPea();
	void display(sf::RenderWindow& Window);
	void collisionCheck(Zombie**& zombieEntities, int, bool& peaGenerated, int& numZom);
	void movement();
	void takeDamage();
	sf::Sprite getSpriteEntity();

};
#endif // !NormalPea_h

