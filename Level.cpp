#include"Level.h"
Levels::Levels(int n):zombieFactory(n), plantFactory(n), levelNumber(n){
	numZombies = zombieFactory.getNumZombies();
	if (levelNumber <= 3) {
		grid = new Tile * [5];
		for (int i = 0; i < 5; i++) {
			grid[i] = new Tile[9];
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				grid[i][j].setX(250 + j * 83);
				grid[i][j].setY(70 + i * 100);
				grid[i][j].setGridPosition(grid[i][j].getX(), grid[i][j].getY());
			}
		}
	}
	lawnMoverPtr = new LawnMover * [5];
	for (int i = 0; i < 5; i++) {
		lawnMoverPtr[i] = new LawnMover(120, 70 + i * 100, 1, 1, 7,7);
	}

	plantFactory.addGrid(grid);
	availablePlants();
	peaPtr = nullptr;
	sizePea = 0;
	waveNumber = 0;
}
Levels::~Levels() {
	for (int i = 0; i < 5; i++) {
		delete grid[i];
	}
	delete[] grid;
	for (int i = 0; i < 5; i++) {
		delete lawnMoverPtr[i];
	}
	delete[] lawnMoverPtr;
	if (peaPtr != nullptr) {
		delete[] peaPtr;
	}
}

bool  Levels::checkZombieWin(Zombie**& zombieEntities, int size, int& live) {
	for (int i = 0; i < size; i++) {
		if (zombieEntities[i]->position.getX() == 100) {
			zombieEntities[i]->movementRight();
			live--;
			return 1;
		}
	}
	return 0;
}

void Levels::display(sf::RenderWindow &Window) {
	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		grid[i][j].display(Window);
	//	}
	//}
	plantFactory.display(Window);
	zombieFactory.display(Window);
	for (int i = 0; i < 5; i++) {
		lawnMoverPtr[i]->display(Window);
	}
	drawAvailablePlants(levelNumber, Window);
}

bool Levels::checkNewWave(int level) {
	if (numZombies== 0 && waveNumber>0) {
		numZombies = zombieFactory.getNumZombies();
		zombieFactory.setCurrent(0);
		for (int i = 0; i < numZombies; i++) {
			(zombieFactory.getZombiePtr())[i] = nullptr;
		}
		zombieFactory.addZombies(1200, ((rand() % 5) + 1) * 100, 1, 1, 3, 2);
		waveNumber--;
		return 1;
	}
	if (numZombies == 0 && waveNumber == 0) {
		cout << "Level Completed" << endl;
		return 0;
	}
	return 1;
}

void Levels::update(int& coins1) {

	zombieFactory.updateZombies();	
	plantFactory.updatePlant(coins1);
	collisionRumble(grid);
	plantFactory.checkExistingPlants();
	for (int i = 0; i < 5; i++) {
		if(lawnMoverPtr[i]->startMoving==1)
		lawnMoverPtr[i]->movement();
	}
}
void Levels::availablePlants() {
	if (levelNumber == 1) {
		textureAvailablePlants.loadFromFile("LEVEL1 AVAILABLE.png");
		sf::IntRect rectSourceSprite(0, 0, 100, 600);
		rectSourceSprite.left = 0;
		rectSourceSprite.top = 0;
		rectSourceSprite.width = 100;
		rectSourceSprite.height = 600;
		spriteAvailablePlants.setTexture(textureAvailablePlants);
		spriteAvailablePlants.setTextureRect(rectSourceSprite);
		spriteAvailablePlants.setPosition(0,0);
	}
	else if (levelNumber == 2) {
		textureAvailablePlantsL2.loadFromFile("LEVEL2 AVAILABLE.png");
		sf::IntRect rectSourceSprite(0, 0, 100, 600);
		rectSourceSprite.left = 0;
		rectSourceSprite.top = 0;
		rectSourceSprite.width = 100;
		rectSourceSprite.height = 600;
		spriteAvailablePlantsL2.setTexture(textureAvailablePlantsL2);
		spriteAvailablePlantsL2.setTextureRect(rectSourceSprite);
		spriteAvailablePlantsL2.setPosition(0, 0);
	}
	else if (levelNumber == 3) {
		textureAvailablePlantsL3.loadFromFile("LEVEL3 AVAILABLE.png");
		sf::IntRect rectSourceSprite(0, 0, 100, 600);
		rectSourceSprite.left = 0;
		rectSourceSprite.top = 0;
		rectSourceSprite.width = 100;
		rectSourceSprite.height = 600;
		spriteAvailablePlantsL3.setTexture(textureAvailablePlantsL3);
		spriteAvailablePlantsL3.setTextureRect(rectSourceSprite);
		spriteAvailablePlantsL3.setPosition(0, 0);
	}
}
void Levels::drawAvailablePlants(int level, sf::RenderWindow & Window) {
		if(level==1)Window.draw(spriteAvailablePlants);
		else if (level == 2)Window.draw(spriteAvailablePlantsL2);
		else if (level == 3)Window.draw(spriteAvailablePlantsL3);
}

bool Levels::checkMouseClick(sf::RenderWindow& Window, int x, int y) {
	cout << x << endl;
	cout << y << endl;
	if (levelNumber == 1) {
		if (x >= 0 && x <= 100 && y >= 0 && y <= 100 ) {
			plantFactory.peashooterSelected = 1;
			return 1;
		}
		else if (x >= 0 && x <= 100 && y > 100 && y <= 200) {
			plantFactory.sunFlowerSelected = 1;
			return 1;
		}
		return 0;
	}
	else if (levelNumber == 2) {
		if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
			plantFactory.peashooterSelected = 1;
			return 1;
		}
		else if (x >= 0 && x <= 100 && y > 100 && y <= 200) {
			plantFactory.sunFlowerSelected = 1;
			return 1;
		}
		else if (x >= 0 && x <= 100 && y > 200 && y <= 300) {
			plantFactory.walknutSelected = 1;
			return 1;
		}
		return 0;
	}
	else if (levelNumber == 3) {
		if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
			plantFactory.peashooterSelected = 1;
			return 1;
		}
		else if (x >= 0 && x <= 100 && y > 100 && y <= 200) {	
			plantFactory.sunFlowerSelected = 1;
			return 1;
		}
		else if (x >= 0 && x <= 100 && y > 200 && y <= 300) {
			plantFactory.walknutSelected = 1;
			return 1;
		}
		else if (x >= 0 && x <= 100 && y > 300 && y <= 400) {
			plantFactory.cherrybombSelected = 1;
			return 1;
		}	
		else if (x >= 0 && x <= 100 && y > 400 && y <= 500) {
			plantFactory.repeaterSelected = 1;
			return 1;
		}
		else if (x >= 0 && x <= 100 && y > 500 && y <= 600) {
			plantFactory.snowPeaSelected = 1;
			return 1;
		}		
		return 0;
	}

}
PlantFactory& Levels::getPlantFactory() {
	return plantFactory;
}

ZombieFactory& Levels::getZombieFactory(){
	return zombieFactory;
}
void Levels::collisionRumble(Tile ** & grid) {
	plantFactory.chekCollisionRumble(zombieFactory.getZombiePtr(), zombieFactory.getSize(), grid, numZombies);
	zombieFactory.chekCollisionRumble(plantFactory.getPlantPtr(),plantFactory.getSize());
	for (int i = 0; i < 5; i++) {
		lawnMoverPtr[i]->collisionCheck(zombieFactory.getZombiePtr(), zombieFactory.getSize(), numZombies);
	}
}


void Levels::updatePlantFactory(int xPos, int yPos, int h, int w, int hit, int& coins1) {
	plantFactory.addPlant(xPos,yPos,h,w,hit,coins1);
}
