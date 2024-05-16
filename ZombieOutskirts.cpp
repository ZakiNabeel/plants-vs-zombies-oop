#include "ZombieOutskirts.h"

ZombieOutskirts::ZombieOutskirts() : Levels(2) {
}

ZombieOutskirts::~ZombieOutskirts() {
}

void ZombieOutskirts::display(sf::RenderWindow& Window) {
    Levels::display(Window);
}

void ZombieOutskirts::update(int& coins1) {
    Levels::update(coins1);
}

void ZombieOutskirts::createBack(sf::RenderWindow& window) {
    (Levels::textureBackGround).loadFromFile("Level2Background.png");
    (Levels::spriteBackGround).setTexture((Levels::textureBackGround));
    window.draw(spriteBackGround);
}
