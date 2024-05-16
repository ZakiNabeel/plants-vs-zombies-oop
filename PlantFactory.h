#pragma once
#ifndef PLANT_FACTORY_H
#define PLANT_FACTORY_H
#include "Plants.h"
#include"Zombie.h"
#include "Peashooter.h" 
#include "Sunflower.h"
#include "Walknut.h"
#include "Repeater.h"
#include "Cherrybomb.h"
#include"SnowPea.h"
#include"Tile.h"
// Factory for generation of plants 
class PlantFactory {
	int size;
	int current;
	int levelChecker;
	Plants** plantPtr;
	Tile** grid2;
	int numShooterPlants;
public:
	bool sunFlowerSelected;
	bool peashooterSelected;
	bool walknutSelected;
	bool cherrybombSelected;
	bool repeaterSelected;
	bool snowPeaSelected;
  //  Plants* createPlant(const std::string& type, sf::Vector2f pos);
	PlantFactory(int);
	~PlantFactory();
	void addPlant(int, int, int, int, int, int& coins1);
	void display(sf::RenderWindow& Window);
	void addGrid(Tile**&);
	void updatePlant(int & coins1);
	void chekCollisionRumble(Zombie ** & zombieEntities, int size, Tile**& grid, int & numZom);
	Plants**& getPlantPtr();
	int getSize();
	void checkExistingPlants();
};

#endif // PLANT_FACTORY_H