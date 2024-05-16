#pragma once
#ifndef Level_h
#define Level_h
#include"ZombieFactory.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include"Tile.h"
#include<iostream>
#include"PlantFactory.h"
#include"LawnMover.h"
using namespace std;
class PlantFactory;
class ZombieFactory;
class Levels {
protected:	
	//int numZombies;
	ZombieFactory zombieFactory;
	PlantFactory plantFactory;
	LawnMover** lawnMoverPtr;
	int levelNumber;
	Tile** grid;
	sf::Texture textureBackGround;
	sf::Sprite spriteBackGround;
	sf::Texture textureAvailablePlants;
	sf::Sprite spriteAvailablePlants;
	sf::Texture textureAvailablePlantsL2;
	sf::Sprite spriteAvailablePlantsL2;
	sf::Texture textureAvailablePlantsL3;
	sf::Sprite spriteAvailablePlantsL3;
	//Sun** sunPtr;
	Pea* peaPtr;
	int sizePea;
	int waveNumber;
public:
	int numZombies;
	Levels(int);
	virtual void createBack(sf::RenderWindow& window) = 0;
	~Levels();
	ZombieFactory& getZombieFactory();
	PlantFactory& getPlantFactory();
	bool checkNewWave(int level);
	void display(sf::RenderWindow & Window);
	void update(int& coins1);
	void availablePlants();
	void drawAvailablePlants(int, sf::RenderWindow& Window);
	bool checkMouseClick(sf::RenderWindow& Window, int, int);
	void collisionRumble(Tile ** &);
	void updatePlantFactory(int, int, int, int, int, int& coins1);
	bool checkZombieWin(Zombie**& zombieEntities, int size, int & live);
	//Tile** getGrid();
};

#endif // !Level.h

