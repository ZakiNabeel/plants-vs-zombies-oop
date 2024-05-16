#include"Position.h"

void Position::setX(int xPos) {
	this->x = xPos;
}
void Position::setY(int yPos) {
	this->y = yPos;
}
int Position::getX() {
	return this->x;
}
int Position::getY() {
	return this->y;
}
Position::Position(int xPos, int yPos) {
	this->x = xPos;
	this->y = yPos;
}
Position::~Position(){}
