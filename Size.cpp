#include"Size.h"

void Size::setHeight(int h) {
	this->height = h;
}
void Size::setWidth(int w) {
	this->width = w;
}
int Size::getHeight() {
	return this->height;
}
int Size::getWidth() {
	return this->width;
}
Size::Size(int h, int w) {
	this->height = h;
	this->width = w;
}
Size::~Size(){}