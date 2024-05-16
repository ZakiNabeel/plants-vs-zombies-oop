// FootballZombies.cpp
#include "FootballZombies.h"

FootballZombies::FootballZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, 5, s) {
	spriteEntity.texture.loadFromFile("Football.png");
	sf::IntRect rectSourceSprite(0, 0, 479, 521);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.20f, 0.20f);
	NorthWest = false;
	SouthWest = false;
	typeDancer = 0;
	right = 1;
}

FootballZombies::~FootballZombies() {}

void FootballZombies::movement() {
	movementLeft();
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}

void FootballZombies::takeDamage() {
	hitPoints -= 5;
}

void FootballZombies::display(sf::RenderWindow& Window) {
	Window.draw(spriteEntity.sprite);
}

void FootballZombies::collisionCheck(Plants** & plantEntites, int size) {
	cout << "Collision Check Football Zombie" << endl;
}
