#include "Peashooter.h"
#include "SFML/Graphics.hpp"
Peashooter::Peashooter(int xPos, int yPos, int h, int w, int hit) : Shooter(xPos, yPos, h, w, 100) {
	spriteEntity.texture.loadFromFile("peaShooter.png");
	sf::IntRect rectSourceSprite(0, 0, 97, 111);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.8f, 0.8f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	peaGenerated = 0;
	Shooter::numOfPea = 1;
	present = 1;
	Plants::typePeaShooter = 1;
	spriteEntity.clockEntity.restart();
}
Peashooter::~Peashooter() {}
void Peashooter::takeDamage()
{
	cout << "     ";
	this->hitPoints--;
}
bool Peashooter::isPresent() {
	return this->present;
}


void Peashooter::display(sf::RenderWindow & Window) {
	if(isPresent())
	Window.draw(spriteEntity.sprite);
	for (int i = 0; i < numOfPea; i++) {
		if (peaPtr != nullptr && peaGenerated==1)
		peaPtr[i]->display(Window);
	}
}
void Peashooter::collisionCheck( Zombie** &zombieEntities, int size, Tile**& grid, int& numZom)
{
	for (int i = 0; i < size; i++)
	{
		if ((zombieEntities[i]->position.getX() >= position.getX()+50 && zombieEntities[i]->position.getX() <= position.getX() + 80) && (zombieEntities[i]->position.getY() >= position.getY() - 30) && (zombieEntities[i]->position.getY() <= position.getY() + 30))
		{
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					if (grid[i][j].getX() == position.getX() && grid[i][j].getY() == position.getY()) {
						grid[i][j].checkPlant=0;
					}
				}
			}
			if (zombieEntities[i]->typeDancer) {
				if (zombieEntities[i]->NorthWest) {
					zombieEntities[i]->movementDiagonalSouthEast();
				}
				else {
					zombieEntities[i]->movementDiagonalNorthEast();
				}
			}
			else {
				zombieEntities[i]->movementRight();
			}			
			hitPoints--;
			if (hitPoints==0) {
				plantExists = 0;
				present = 0;	
				position.setX(-100);
				position.setY(-100);
				takeDamage();
				if (healthCheck())
				{
					plantExists = 0;
					present = 0;
				}
				spriteEntity.clockEntity.restart();
			}
		}
	}
	if (peaGenerated == 1) {
		for (int i = 0; i < numOfPea; i++) {
			peaPtr[i]->collisionCheck(zombieEntities, size, peaGenerated,numZom);
		}
	}
}
void Peashooter::magic(int& coins1)
{
    // Check if 10 seconds have elapsed since the last pea was generated
    if (peaGenerated == 0 && spriteEntity.clockEntity.getElapsedTime().asSeconds() >= 10) {
        // Generate a new pea
        generatePea();

        // Reset the clock
        spriteEntity.clockEntity.restart();
    }
    if (peaGenerated == 1) {
		for (int i = 0; i < numOfPea; i++) {
			peaPtr[i]->movement();
		}
    }
}

void Peashooter::generatePea()
{
	cout << "Pea generated Pea Shooter" << endl;
	peaPtr = new Pea * [1];
	peaPtr[0] = new NormalPea(position.getX() + 83, position.getY(), 1, 1, 0, 3);
	peaGenerated = 1;
	for (int i = 0; i < numOfPea; i++) {
		peaPtr[i]->isPresent = 1;
	}
}