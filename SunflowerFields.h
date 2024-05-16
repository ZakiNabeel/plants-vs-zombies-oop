#pragma once
#ifndef SunflowerFields_h
#define SunflowerFields_h
#include"Level.h"
class SunflowerFields : public Levels {
public:
	void createBack(sf::RenderWindow& window);
	SunflowerFields();
	~SunflowerFields();
	void display(sf::RenderWindow& Window);
	void update(int& coins1);
};
#endif // !SunflowerFields_h

