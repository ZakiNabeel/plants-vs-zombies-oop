#include"ZombieFactory.h"
#include<ctime>
#include<cstdlib>
ZombieFactory::ZombieFactory(int s) :size(s*5), current(0), levelChecker(s) {
	zombiePtr = new Zombie*[size];
	addZombies(1200, ((rand() % 5) + 1) * 100,1,1,3,5);
}
ZombieFactory::~ZombieFactory() {
	for (int i = 0; i < size; i++) {
		delete zombiePtr[i];
	}
	delete[] zombiePtr;
	zombiePtr = nullptr;
}
int ZombieFactory::getNumZombies() {
	return this->size;
}
void ZombieFactory::setCurrent(int cur) {
	this->current = cur;
}

void ZombieFactory::addZombies(int xPos, int yPos, int h=1, int w=1, int hit=3, int s=1) {
	srand(time(NULL));
	if (levelChecker == 1) {
		int check = 0;
		while (current < size) {
			check = rand() % 2;
			cout << check << "-------------------" << check << endl;
			if (check == 0)zombiePtr[current] = new SimpleZombies(1200 + 100 * (rand() % 5), ((rand() % 5) * 100) + 70, h, w, 3, 8);
			else if (check == 1)zombiePtr[current] = new FootballZombies(1200 + 100 * (rand() % 5), ((rand() % 5) * 100) + 70, h, w, 5, 13);
			++current;
		}
	}
	else if (levelChecker == 2) {
		int check = 0;
		while (current < size) {
			check = rand() % 4;
			cout << check << "-------------------" << check << endl;
			if (check == 0)zombiePtr[current] = new SimpleZombies(1200 + 100 * (rand() % 5), ((rand() % 5) * 100) + 70, h, w, 3, 8);
			else if (check == 1)zombiePtr[current] = new FootballZombies(1200 + 100 * (rand() % 3), ((rand() % 5) * 100) + 70, h, w, 5, 13);
			else if (check == 2)zombiePtr[current] = new DancingZombies(1200 + 100 * (rand() % 1), ((rand() % 5) * 100) + 70, h, w, 2, 12);
			else if (check == 3)zombiePtr[current] = new FlyingZombies(1200 + 100 * (rand() % 3), ((rand() % 5) * 100) + 70, h, w, 2,15);
			++current;
		}
	}
	else if (levelChecker == 3) {
		int check = 0;
		int containerY = 0;
		while (current < size) {
			check = rand() % 4;
			containerY = ((rand() % 5) * 100) + 70;
			if (check == 0 && containerY!=270)zombiePtr[current] = new SimpleZombies(1200 + 100 * (rand() % 5),containerY, h, w, 3, 8);
			else if (check == 1 && containerY != 270)zombiePtr[current] = new FootballZombies(1200 + 100 * (rand() % 3), containerY, h, w, 5, 13);
			else if (check == 2 && containerY != 270)zombiePtr[current] = new DancingZombies(1200 + 100 * (rand() % 3), containerY, h, w, 2, 2);
			else if (check == 3 )zombiePtr[current] = new DolphinRiderZombies(1200 + 100 * (rand() % 3), 270, h, w, 5, 10);
			else if(check==4 && containerY != 270)zombiePtr[current] = new FlyingZombies(1200 + 100 * (rand() % 3), containerY, h, w, 4, 15);
			else zombiePtr[current] = new DolphinRiderZombies(1200 + 100 * (rand() % 3), 270, h, w, 5, 10);
			++current;
			cout << "Added " << current << endl;
		}
	}
}
void ZombieFactory::display(sf::RenderWindow& Window) {
	for (int i = 0; i < size; i++) {
		if (zombiePtr[i] != nullptr) {
			//cout << "Displayed" << endl;
			(*(zombiePtr[i])).display(Window);
		}
	}
}
void ZombieFactory::updateZombies() {
	for (int i = 0; i < size; i++) {
		if (zombiePtr[i] != nullptr) {
			(*(zombiePtr[i])).movement();
			cout << (*(zombiePtr[i])).position.getX();
			cout << (*(zombiePtr[i])).position.getY();
		}
	}
}
void ZombieFactory::chekCollisionRumble(Plants**& plantEntities, int size)
{
	for (int i = 0; i < this->current; i++) {
		//if (zombiePtr[i] != nullptr) {
		//	(*(zombiePtr[i])).collisionCheck(plantEntities,size);
		//}
	}
}

int ZombieFactory::getSize() {
	return this->size;
}

Zombie**& ZombieFactory::getZombiePtr() {
	return zombiePtr;
}

