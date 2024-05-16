#include"Zombie.h";

Zombie::Zombie(int xPos, int yPos, int h, int w, int hit, int s = 1) :Moving(xPos, yPos, h, w, hit, s){}
Zombie::~Zombie(){
}
void Zombie::movement() {
	cout << " ";
}
void Zombie::display(sf::RenderWindow &Window) {
	cout << " ";
}

void Zombie::takeDamage() {
	cout << " ";
}

void Zombie::collisionCheck( Plants**& plantEntites, int size) {
	cout << "Zombie Collision Check\n";
}
