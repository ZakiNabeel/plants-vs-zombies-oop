#pragma once
#ifndef Position_h
#define Position_h
#include<iostream>
using namespace std;

struct Position {
	int x;
	int y;
	Position(int,int);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	~Position();
};
#endif // !Position_h
