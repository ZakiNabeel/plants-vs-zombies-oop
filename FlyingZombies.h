#pragma once
#ifndef FlyingZombies_h
#define FlyingZombies_h
#include "Zombie.h"

class FlyingZombies : public Zombie {
public:
    FlyingZombies(int xPos, int yPos, int h, int w, int hit, int s);
    ~FlyingZombies();
    void movement();
    void takeDamage();
    void display(sf::RenderWindow& Window);
    void collisionCheck( Plants** & plantEntites, int size);
};

#endif // !FlyingZombies_h
