#include "Sunflower.h"
Sunflower::Sunflower(int xPos, int yPos, int h, int w, int hit) :NonShooter(xPos, yPos, h, w, 50){
	sunPtr = nullptr;
	spriteEntity.texture.loadFromFile("sunFlower (2).png");
	sf::IntRect rectSourceSprite(341, 117, 113, 117);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.7f, 0.7f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	cout << "Sunflower Constructor CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" << endl;
	sunGenerated = 0;
	present = 1;
	Plants::typeSunFlower = 1;
}
Sunflower::~Sunflower() {
	delete[] sunPtr;
	sunPtr = nullptr;
}
void Sunflower::display(sf::RenderWindow & Window) {
	Window.draw(spriteEntity.sprite);
	//cout << "SunFlower displayed, now get some sunlight" << endl;
	if (sunGenerated == 1 && sunPtr!=nullptr) {
		sunPtr[0].display(Window);
	}
}
void Sunflower::takeDamage()
{
		this->hitPoints--;
}
void Sunflower::collisionCheck(Zombie** &zombieEntities, int size, Tile**& grid, int& numZom)
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
			}			hitPoints--;
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
void Sunflower::generateSun(int& coins1)
{
	coins1 += 100;
	sunPtr = new Sun(position.getX()+83, position.getY(), 1, 1, 0,1);
	sunGenerated = 1;
	spriteEntity.clockEntity.restart();
}

void Sunflower::magic(int& coins1) {
	if (sunGenerated == 0 && spriteEntity.clockEntity.getElapsedTime().asSeconds() > 4) {
		generateSun(coins1);
		spriteEntity.clockEntity.restart();
	}
	else {
		if (spriteEntity.clockEntity.getElapsedTime().asSeconds() < 2 && sunGenerated == 1)
			sunPtr->movement();
		else if (spriteEntity.clockEntity.getElapsedTime().asSeconds() > 5 && sunGenerated == 1) { // 5 seconds as an example
			delete sunPtr;
			sunPtr = nullptr;
			sunGenerated = 0;
			spriteEntity.clockEntity.restart();
		}
	}
}
