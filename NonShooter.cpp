#include "NonShooter.h"
NonShooter::NonShooter(int xPos, int yPos, int h, int w, int hp) : Plants(xPos, yPos, h, w, hp) {
	cout << "NonShooter constructor" << endl;
}
NonShooter::~NonShooter() {}
void NonShooter::display(sf::RenderWindow & Window) {
	cout << " ";
	cout << "Display non shooter" << endl;
}
void NonShooter::collisionCheck(Zombie ** &zombieEntities, int size, Tile**& grid, int& numZom)
{
	cout << "Coliision checkk non shooter" << endl;

}
void NonShooter::magic(int& coins1)
{
	cout << "nonShooter magic" << endl;
}
