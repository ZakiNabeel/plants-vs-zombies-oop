#include "Cherrybomb.h"
Cherrybomb::Cherrybomb(int xPos, int yPos, int h, int w, int hp) : NonShooter(xPos, yPos, h, w, hp) {
	cout << "In Cherrybomb constructor" << endl;
	spriteEntity.texture.loadFromFile("PvZ_Pictures.doc2-ezgif.com-webp-to-png-converter-removebg-preview.png");
	sf::IntRect rectSourceSprite(0, 0, 570, 438);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.2f, 0.24f);
	spriteEntity.sprite.setPosition(xPos, yPos);
	present = 1;
	Plants::typeCherryBomb = 1;
	blast = 0;
}
Cherrybomb::~Cherrybomb() {}
void Cherrybomb::display(sf::RenderWindow& Window) {
	if(blast==0)Window.draw(spriteEntity.sprite);
}
void Cherrybomb::takeDamage()
{
	cout << "     ";
	this->hitPoints -= 1;
}
void Cherrybomb::collisionCheck(Zombie**& zombieEntities, int size, Tile**& grid, int& numZom) {
	for (int i = 0; i < size; i++)
	{
		if ((zombieEntities[i]->position.getX() >= position.getX() + 50 && zombieEntities[i]->position.getX() <= position.getX() + 100) && (zombieEntities[i]->position.getY() >= position.getY() - 30) && (zombieEntities[i]->position.getY() <= position.getY() + 30))
		{
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					if (grid[i][j].getX() == position.getX() && grid[i][j].getY() == position.getY()) {
						grid[i][j].checkPlant = 0;	
					}
				}
			}
			zombieEntities[i]->hitPoints = 0;
			zombieEntities[i]->position.setX(-100);
			zombieEntities[i]->position.setY(-100);
			blast = 1;
			position.setX(-100);
			position.setY(-100);
			--numZom;
		}
	}
}
void Cherrybomb::magic(int& coins1) { 
	cout << "CherryBomb Exploded" << endl;
}