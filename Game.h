#pragma once
#ifndef Game_h
#define Game_h
#include"Level.h"
#include"BeginersGarden.h"
#include"ZombieOutskirts.h"
#include"SunflowerFields.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include "MenuScreen.h"
#include "InstructionScreen.h"
#include "NameScreen.h"
#include"WinScreen.h"
#include"LoseScreen.h"
using namespace std;

class Game {
	int score;
	int totalLevels;
	int coins;
	Levels** level;
	int levelNumber;
	bool plantClicked;
	Sun* sunPtr;
	bool sunGenerated;
	sf::RectangleShape grid;
	bool newLevelCheck;
	int lives;
	MenuScreen menuScreen;
	InstructionScreen instructionScreen;
	NameScreen nameScreen;
	WinScreen winScreen;
	LoseScreen loseScreen;

public:
	int& getLives();
	Game();
	~Game();
	void run();
	void newLevel();
	int getLevelNumber();
};
#endif // !Game_h