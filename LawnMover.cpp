#include"LawnMover.h"
LawnMover::LawnMover(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, 10) {
	isPresent = 1;
	startMoving = 0;
}
LawnMover::~LawnMover(){}
void LawnMover::display(sf::RenderWindow& window){
	spriteEntity.texture.loadFromFile("lawnmover.png");
	sf::IntRect rectSourceSprite(0, 0, 622, 400);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.2f, 0.2f);
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
	window.draw(spriteEntity.sprite);
}
void LawnMover::movement() {
	if (startMoving) {
		movementRight();
	}
}
void LawnMover::collisionCheck(Zombie ** & zombieEntities, int size, int& numZom) {
	for (int i = 0; i < size; i++) {
		if ((((zombieEntities[i]->position.getX() <= position.getX() + 80))) && (zombieEntities[i]->position.getY() <= position.getY()+20 && zombieEntities[i]->position.getY() >= position.getY() - 20)) {
			zombieEntities[i]->position.setX(-100);
			zombieEntities[i]->position.setY(-100);
			numZom--;
			startMoving = 1;
		}
		if (position.getX() >= 1500) {
			startMoving = 0;
		}
	}
}
bool LawnMover::healthCheck() {
	if (hitPoints == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
