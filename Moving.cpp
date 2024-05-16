#include"Moving.h"
Moving::Moving(int xPos, int yPos, int h, int w, int hit,int s):Entity(xPos,yPos,h,w,hit){
	this->speed = s;
}
Moving::~Moving(){

}
int Moving::getSpeed() {
	return this->speed;
}
void Moving::movementLeft() {
	position.setX((position.getX() - this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementRight() {
	position.setX((int)(position.getX() + this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementVertical() {
	position.setY((int)(position.getY() + this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementDiagonalNorthWest() {
	position.setY((int)(position.getY() - this->speed));
	position.setX((int)(position.getX() - this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementDiagonalSouthWest() {
	position.setY((int)(position.getY() + this->speed));
	position.setX((int)(position.getX() - this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementDiagonalNorthEast() {
	position.setY((int)(position.getY() - this->speed));
	position.setX((int)(position.getX() + this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}
void Moving::movementDiagonalSouthEast() {
	position.setY((int)(position.getY() - this->speed));
	position.setX((int)(position.getX() + this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}

void Moving::movementVerticalUp() {
	position.setY((int)(position.getY() - this->speed));
	spriteEntity.sprite.setPosition(position.getX(), position.getY());
}

void Moving::setSpeed(int s) {
	speed = s;
}

