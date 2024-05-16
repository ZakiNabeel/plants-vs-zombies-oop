#include"Pea.h"
Pea::Pea(int xPos, int yPos, int h, int w, int hit, int s = 1) : Moving(xPos, yPos, h, w, hit, 10) {
	this->isPresent = 1;
}
Pea::~Pea(){}
void Pea::display(sf::RenderWindow & Window){
	cout << "abs";
}
void Pea::movement() {
	movementRight();
	cout << "cnuw";
}
void Pea::takeDamage() {
	cout << "Peacsssssssssssss";
}
void Pea::setX(int x) {
	position.setX(x);
}
void Pea::setY(int y) {
	position.setY(y);
}
void Pea::setH(int h) {
	size.setHeight(h);
}
void Pea::setW(int w) {
	size.setWidth(w);
}
void Pea::setHit(int hit) {
	hitPoints = hit;
}
void Pea::setSpeed(int s) {
	speed = s;
}
