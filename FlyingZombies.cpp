// FlyingZombies.cpp
#include "FlyingZombies.h"

FlyingZombies::FlyingZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("flyingZombie-removebg-preview.png");
	sf::IntRect rectSourceSprite(0, 0, 275, 496);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.35f, 0.22f);
	NorthWest = false;
	SouthWest = false;
	typeDancer = 0;
	right = 1;
}

FlyingZombies::~FlyingZombies() {}

void FlyingZombies::movement() {
	movementLeft();
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}

void FlyingZombies::takeDamage() {
	hitPoints -= 4;
}

void FlyingZombies::display(sf::RenderWindow& Window) {
	Window.draw(spriteEntity.sprite);
//	cout << "FlyingZombies Displayed" << endl;
}
void FlyingZombies::collisionCheck(Plants** & plantEntites, int size) {
	cout << "Collision Check Flying Zombie" << endl;
}
