#pragma once
#ifndef BeginersGarden_h
#define BeginersGarden_h
#include"Level.h"
class BeginersGarden: public Levels {
public:
	void createBack(sf::RenderWindow& window);
	BeginersGarden();
	~BeginersGarden();
	void display(sf::RenderWindow& Window);
	void update(int& coins1);
};
#endif // !BeginersGarden_h

