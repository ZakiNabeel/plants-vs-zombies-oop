#include "Plants.h"
Plants::Plants(int xPos, int yPos, int h, int w, int hp) : Entity(xPos, yPos, h, w, hp) {
	cout << "Plants constructor" << endl;
	plantExists = true;
	typePeaShooter = 0;
	typeSunFlower = 0;
	typeCherryBomb = 0;
	typeWalknut = 0;
	typeRepeater = 0;
	typeSnowPea = 0;
}
Plants::~Plants() {}
void Plants::takeDamage() {
	cout << "Take damage plants" << endl;
}
void Plants::display(sf::RenderWindow& Window) {
	cout << "display plants" << endl;
}
