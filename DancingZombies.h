#pragma once
#ifndef DancingZombies_h
#define DancingZombies_h
#include "Zombie.h"

class DancingZombies : public Zombie {
    bool NorthWest;
	bool SouthWest;
public:
    DancingZombies(int xPos, int yPos, int h, int w, int hit, int s);
    ~DancingZombies();
    void movement();
    void takeDamage();
    void display(sf::RenderWindow& Window);
    void collisionCheck( Plants**& plantEntites, int size);
    bool getNorthWest();
    bool getSouthWest();
};

#endif // !DancingZombies_h

