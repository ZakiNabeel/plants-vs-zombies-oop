#include "Shooter.h"
Shooter::Shooter(int xPos, int yPos, int h, int w, int hp) : Plants(xPos, yPos, h, w, hp) {
	peaPtr = nullptr;
}
Shooter::~Shooter() {
	delete[] peaPtr;
}
void Shooter::collisionCheck(Zombie ** &zombieEntities, int size, Tile**& grid, int& numZom)
{
	cout<<"Coliision Check Shooter"<<endl;
}
void Shooter::display(sf::RenderWindow & Window) {}

void Shooter::takeDamage()
{
		this->hitPoints--;
}

void Shooter::magic(int& coins1) {
	cout << "Magic shooter" << endl;
}
