#pragma once
#ifndef DolphinRiderZombies_h
#define DolphinRiderZombies_h
#include "Zombie.h"
#include"Sprite.h"

class DolphinRiderZombies : public Zombie {
    bool swim;
    Sprite swimSprite;
public:
    DolphinRiderZombies(int xPos, int yPos, int h, int w, int hit, int s);
    ~DolphinRiderZombies();
    void movement();
    void takeDamage();
    void display(sf::RenderWindow& Window);
    void collisionCheck( Plants** &plantEntites, int size);
};

#endif // !DolphinRiderZombies_h

