#pragma once
#ifndef SimpleZombies_h
#define SimpleZombies_h
#include"Zombie.h"
class SimpleZombies :public Zombie {
	sf::IntRect rectSourceSprite;
public:
	SimpleZombies(int xPos, int yPos, int h, int w, int hit, int s);
	~SimpleZombies();
	void movement();
	void takeDamage();
	void display(sf::RenderWindow& Window);
	void collisionCheck( Plants** & plantEntites, int size);
};
#endif // !SimpleZombies_h

