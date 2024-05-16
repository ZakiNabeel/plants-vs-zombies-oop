// DolphinRiderZombies.cpp
#include "DolphinRiderZombies.h"

DolphinRiderZombies::DolphinRiderZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("HD_Dolphin_Rider_Zombie-removebg-preview.png");
	sf::IntRect rectSourceSprite(0, 0, 211, 254);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.5f, 0.45f);
	NorthWest = false;
	SouthWest = false;
	typeDancer = 0;
	right = 1;
	swim = 0;
	swimSprite.texture.loadFromFile("coincrown-spr-dolphin-zombie-pvz-1-removebg-preview.png");
	sf::IntRect rectSourceSprite2(0, 0, 500, 500);
	swimSprite.sprite.setTexture(swimSprite.texture);
	swimSprite.sprite.setTextureRect(rectSourceSprite2);
	swimSprite.sprite.setScale(0.25f,0.25f);

}

DolphinRiderZombies::~DolphinRiderZombies() {}

void DolphinRiderZombies::movement() {
	movementLeft();
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
	if (position.getX() <= 900) {
		swim = 1;
	}
//	cout << "Moved Dolphin" << endl;
}

void DolphinRiderZombies::takeDamage() {
	hitPoints -= 3;
}

void DolphinRiderZombies::display(sf::RenderWindow& Window) {
		Window.draw(spriteEntity.sprite);
}


void DolphinRiderZombies::collisionCheck(Plants** & plantEntites, int size) {
	cout << "Collision Check Dolphin Zombie" << endl;
}
