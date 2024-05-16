#include "SunflowerFields.h" // Update the header file name

SunflowerFields::SunflowerFields() : Levels(3) {
}

SunflowerFields::~SunflowerFields() {
}

void SunflowerFields::display(sf::RenderWindow& Window) {
    Levels::display(Window);
}

void SunflowerFields::update(int& coins1) {
    Levels::update(coins1);
}

void SunflowerFields::createBack(sf::RenderWindow& window) {
    Levels::textureBackGround.loadFromFile("Level3 (1).png"); 
    Levels::spriteBackGround.setTexture(Levels::textureBackGround);
    window.draw(Levels::spriteBackGround);
}
