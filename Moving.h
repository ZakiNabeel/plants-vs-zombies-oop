#pragma once
#ifndef Movement_h
#define Movement_h
#include"Entity.h"
class Moving : public Entity{
protected:
	int speed;
public:
	Moving(int xPos, int yPos, int h, int w, int, int);
	~Moving();
	virtual void movement()=0;
	//void movementHorizontal();
	void movementVertical();
	void movementDiagonalNorthWest();
	void movementDiagonalSouthWest();
	void movementDiagonalNorthEast();
	void movementDiagonalSouthEast();
	void movementLeft();
	void movementRight();
	int getSpeed();
	void setSpeed(int);
	void movementVerticalUp();
	//virtual void setSpeed(int);
	//Speed funtions added.
	//	void movementLeft() and void movementRight() added for Zombies and plants. otehrvisw we would have to make the horizontal function virtual as well
};
#endif // !Movement_h

