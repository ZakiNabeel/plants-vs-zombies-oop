#include "Repeater.h"
Repeater::Repeater(int xPos, int yPos, int h, int w, int hit) : Shooter(xPos, yPos, h, w, hit) {
	spriteEntity.texture.loadFromFile("REPEATERRR-removebg-preview.png");
	sf::IntRect rectSourceSprite(0, 0, 339, 510);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.3f, 0.2f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	present = 1;
	Plants::typeRepeater = 1;
	numOfPea = 2;
	peaPtr = new Pea * [numOfPea];
}

void Repeater::display(sf::RenderWindow& Window) {
	if (present)
		Window.draw(spriteEntity.sprite);
	for (int i = 0; i < numOfPea; i++) {
		if (peaPtr != nullptr && peaGenerated == 1)
			peaPtr[i]->display(Window);
	}
}

Repeater::~Repeater() {}

void Repeater::takeDamage()
{
	this->hitPoints--;
}
void Repeater::collisionCheck(Zombie**& zombieEntities, int size, Tile**& grid, int& numZom)
{
	for (int i = 0; i < size; i++)
	{
		if ((zombieEntities[i]->position.getX() >= position.getX() + 50 && zombieEntities[i]->position.getX() <= position.getX() + 80) && (zombieEntities[i]->position.getY() >= position.getY() - 30) && (zombieEntities[i]->position.getY() <= position.getY() + 30))
		{
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					if (grid[i][j].getX() == position.getX() && grid[i][j].getY() == position.getY()) {
						grid[i][j].checkPlant = 0;
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
			if (hitPoints == 0) {
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
			peaPtr[i]->collisionCheck(zombieEntities, size, peaGenerated, numZom);
		}
	}
}
void Repeater::magic(int& coins1) {
	if (spriteEntity.clockEntity.getElapsedTime().asSeconds() >= 10) {
		if (peaGenerated == 0) {
			generatePea();
			spriteEntity.clockEntity.restart();
		}
		else {
			for (int i = 0; i < numOfPea; i++) {
				peaPtr[i]->movement();
			}
		}
	}
}
void Repeater::generatePea() {
	peaPtr[0] = new NormalPea(position.getX() + 83*2, position.getY(), 1, 1, 0, 3);
	peaPtr[1] = new NormalPea(position.getX()+83, position.getY(), 1, 1, 0, 3);
	peaGenerated = 1;
	spriteEntity.clockEntity.restart();
}