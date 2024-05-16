#include"NormalPea.h"
NormalPea::NormalPea(int xPos=0, int yPos=0, int h=0, int w=0, int hit=0, int s = 0) : Pea(xPos, yPos, h, w, hit, s) {
	spriteEntity.texture.loadFromFile("Pea.png");
	sf::IntRect rectSourceSprite(0, 0, 135, 135);
	spriteEntity.sprite.setTexture(spriteEntity.texture);
	spriteEntity.sprite.setTextureRect(rectSourceSprite);
	spriteEntity.sprite.setScale(0.3f, 0.3f);
	spriteEntity.sprite.setPosition(xPos+83, yPos);
	cout<<"\n\n\n\n\n\nConstructor called"<<endl;
}
NormalPea::~NormalPea(){}
void NormalPea::display(sf::RenderWindow & Window){
	Window.draw(spriteEntity.sprite);
}
void NormalPea::collisionCheck(Zombie ** & zombieEntities, int size, bool &peaGenerated, int& numZom){
	cout << "\n\n\n\n\n\nCollision called" << endl;
	for (int i = 0; i < size; i++)
	{
		if (position.getX() > 1400) {
			isPresent = 0;
			peaGenerated = 0;
		}
		else if ((zombieEntities[i]->position.getX()<=position.getX() + 40) && (zombieEntities[i]->position.getY() >= position.getY() - 30) && (zombieEntities[i]->position.getY() <= position.getY() + 30))
		{
			position.setX(-100);
			position.setY(-100);
			isPresent = 0;
			zombieEntities[i]->hitPoints--;
			if (zombieEntities[i]->hitPoints == 0)
			{
				zombieEntities[i]->position.setX(-100);
				zombieEntities[i]->position.setY(-100);
				--numZom;
			}
			isPresent = 0;
			peaGenerated = 0;
		}
	}
}
void NormalPea::movement() {
	movementRight();
}
void NormalPea::takeDamage() {
}
NormalPea::NormalPea() : Pea(0,0,0,0,0,0){
}
sf::Sprite NormalPea::getSpriteEntity() {
	return spriteEntity.sprite;
}

