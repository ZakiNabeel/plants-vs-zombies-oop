#pragma once
#ifndef Size_h
#define Size_h
#include<iostream>
using namespace std;

struct Size {
	int height;
	int width;
	Size(int,int);
	~Size();
	void setHeight(int h);
	void setWidth(int w);
	int getHeight();
	int getWidth();
};

#endif // !Size_h

