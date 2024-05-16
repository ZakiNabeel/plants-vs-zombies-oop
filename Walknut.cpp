#include "Walknut.h"
Walknut::Walknut(int xPos, int yPos, int h, int w, int hit) :NonShooter(xPos, yPos, h, w, 200){
	spriteEntity.texture.loadFromFile("WalknuttHighQ.png");
	rectSourceSprite.height=120;
	rectSourceSprite.width = 100;
	rectSourceSprite.left = 0;
	rectSourceSprite.top = 0;
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(1.0f, 1.0f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	present = 1;
	Plants::typeWalknut = 1;
	rotate = 1;
	speed = 5;
}
Walknut::~Walknut() {}
void Walknut::takeDamage()
{
	this->hitPoints--;
}
void Walknut::display(sf::RenderWindow& Window) {
	if (rotate) {
		if (rectSourceSprite.left >= 0 && rectSourceSprite.left < 735) {
			rectSourceSprite.left += 105;
		}
		else {
			rectSourceSprite.left = 0;
		}
		spriteEntity.sprite.setTextureRect(rectSourceSprite);
	}
	Window.draw(spriteEntity.sprite);
}

void Walknut::collisionCheck(Zombie**&zombieEntities, int size, Tile**& grid, int& numZom)
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
			rotate = 0;
			if (zombieEntities[i]->typeDancer) {
				if (zombieEntities[i]->NorthWest) {
					zombieEntities[i]->movementDiagonalSouthEast();
				}
				else {
					zombieEntities[i]->movementDiagonalNorthEast();
				}
			}
			else{
				zombieEntities[i]->movementRight();
			}
			position.setX((int)(position.getX() - this->speed));
			spriteEntity.sprite.setPosition(position.getX(), position.getY());
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
}
void Walknut::magic(int& coins1) {
	if (position.getX() <= 900) {
		position.setX((int)(position.getX() + this->speed));
		spriteEntity.sprite.setPosition(position.getX(), position.getY());
		rotate = 1;
	}
	else {
		rotate = 0;
	}
}