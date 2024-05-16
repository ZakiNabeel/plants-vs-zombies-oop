#pragma once
#ifndef ZombieOutskirts_h
#define ZombieOutskirts_h
#include "Level.h"
class ZombieOutskirts : public Levels {
public:
    void createBack(sf::RenderWindow& window);
    ZombieOutskirts();
    ~ZombieOutskirts();
    void display(sf::RenderWindow& Window);
    void update(int& coins1);
};

#endif // !ZombieOutskirts_h

