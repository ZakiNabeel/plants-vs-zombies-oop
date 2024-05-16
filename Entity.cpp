#include"Entity.h"
Entity::Entity(int xPos, int yPos, int h, int w, int hitNum):position(xPos, yPos),size(h,w),hitPoints(hitNum){
	cout << "Entity constructor" << endl;
}

Entity::~Entity() {

}

void Entity::display(sf::RenderWindow& Window) {

}
void Entity::takeDamage() {
	(this->hitPoints)--;
}
bool collisionViaCherryBomb(){ return 1; }

bool Entity::healthCheck() {
	if (this->hitPoints == 0) return 1;
	else return 0;
}
