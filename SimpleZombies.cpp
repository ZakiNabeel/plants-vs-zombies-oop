#include"SimpleZombies.h"
SimpleZombies::SimpleZombies(int xPos, int yPos, int h, int w, int hit, int s) : Zombie(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("SimpleClearZombie.png");
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	rectSourceSprite.left = 0;
	rectSourceSprite.top = 0;
	rectSourceSprite.width = 363;
	rectSourceSprite.height = 600;
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setPosition(xPos, yPos);
	spriteEntity.sprite.setScale(0.3f, 0.17f);
	spriteEntity.clockEntity.restart();
	NorthWest = false;
	SouthWest = false;
	typeDancer = 0;
	right = 1;
}
SimpleZombies::~SimpleZombies(){}
void SimpleZombies::display(sf::RenderWindow & Window) {		
	//if (spriteEntity.clockEntity.getElapsedTime().asMicroseconds()> 0.1) {
	//	if (rectSourceSprite.left == 9000 && spriteEntity.coordinateRightTouch == false) {
	//		spriteEntity.coordinateRightTouch = true;
	//		spriteEntity.coordinateLeftTouch = false;
	//		rectSourceSprite.left -=200;
	//		spriteEntity.sprite.setTextureRect(rectSourceSprite);
	//	}
	//	else if (rectSourceSprite.left == 0 && spriteEntity.coordinateRightTouch == true) {
	//		spriteEntity.coordinateRightTouch = false;
	//		spriteEntity.coordinateLeftTouch = true;
	//		rectSourceSprite.left += 200;
	//		spriteEntity.sprite.setTextureRect(rectSourceSprite);
	//	}
	//	else if (spriteEntity.coordinateRightTouch == true && spriteEntity.coordinateLeftTouch == false) {
	//		rectSourceSprite.left -= 200;
	//		spriteEntity.sprite.setTextureRect(rectSourceSprite);
	//	}
	//	else {
	//		rectSourceSprite.left += 200;
	//		spriteEntity.sprite.setTextureRect(rectSourceSprite);
	//	}
	//}
	Window.draw(spriteEntity.sprite);
//	cout << "SimpleZombies Displayed" << endl;
}
void SimpleZombies::movement() {
	movementLeft();
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
//	cout << "SimpleZombies Moved" << endl;
}
void  SimpleZombies::takeDamage() {
	hitPoints -= 1;
}
void  SimpleZombies::collisionCheck( Plants** & plantEntites, int size){
	cout << "Collision Check Simple Zombie" << endl;
}