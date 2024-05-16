// DancingZombies.cpp
#include "DancingZombies.h"

DancingZombies::DancingZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("dancer-removebg-preview.png");
	sf::IntRect rectSourceSprite(0, 0, 478, 522);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setPosition(xPos, yPos);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.2f, 0.2f);
	NorthWest = true;
	SouthWest = false;
	typeDancer = 1;
	right = 0;
}

DancingZombies::~DancingZombies() {}

void DancingZombies::movement() {
	if (position.getY() > 70 && NorthWest == true)Moving::movementDiagonalNorthWest();
	else if (position.getY() <= 70 && NorthWest == true) {
		NorthWest = false;
		SouthWest = true;
		Moving::movementDiagonalSouthWest();
	}
	else if (position.getY() < 450 && SouthWest == true) Moving::movementDiagonalSouthWest();
	else if (position.getY() >= 450 && SouthWest == true) {
		NorthWest = true;
		SouthWest = false;
		Moving::movementDiagonalNorthWest();
	}
}

void DancingZombies::takeDamage() {
    hitPoints -= 2;
}

void DancingZombies::display(sf::RenderWindow & Window) {
    Window.draw(spriteEntity.sprite);
//	cout << "DancingZombies Displayed" << endl;
}

void DancingZombies::collisionCheck(Plants** & plantEntites, int size) {
	cout << "Collision Check Dancing Zombie" << endl;
}

bool DancingZombies::getNorthWest() {
	return NorthWest;
}
bool  DancingZombies::getSouthWest() {
	return SouthWest;
}
