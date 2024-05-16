#include"WhitePea.h"
WhitePea::WhitePea(int xPos, int yPos, int h, int w, int hit, int s = 1) : Pea(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("snowPea__1_-removebg-preview.png");
	sf::IntRect rectSourceSprite(0, 0, 100, 100);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.4f, 0.4f);
	spriteEntity.sprite.setPosition(xPos, yPos);
}
WhitePea::~WhitePea(){

}
void WhitePea::display(sf::RenderWindow& Window){
	Window.draw(spriteEntity.sprite);
}
void WhitePea::movement() {
	movementRight();
	cout << "WhitePea";
}
void WhitePea::collisionCheck(Zombie**& zombieEntities, int size, bool& peaGenerated, int& numZom) {
	for (int i = 0; i < size; i++)
	{
		if (position.getX() > 1400) {
			isPresent = 0;
			peaGenerated = 0;
		}
		else if ((zombieEntities[i]->position.getX() <= position.getX() +40) && (zombieEntities[i]->position.getY() >= position.getY() - 30) && (zombieEntities[i]->position.getY() <= position.getY() + 30))
		{
			position.setX(-100);
			position.setY(-100);
			zombieEntities[i]->setSpeed(1);
			isPresent = 0;
			peaGenerated = 0;
		}
	}
}	

void WhitePea::takeDamage() {
	cout << "WhitePeacsssssssssssss";
}
sf::Sprite WhitePea::getSpriteEntity() {
	return spriteEntity.sprite;
}