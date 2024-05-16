#include"Tile.h"
#include"Zombie.h"
using namespace sf;
Tile::Tile() {
	xPos = 0;
	yPos = 0;
	height = 100;
	width = 83;
	checkPlant = 0;
}

Tile::Tile(int x, int y){
	xPos = x;
	yPos = y;
	height = 100;
	width = 83;
	checkPlant = 0;
}
void Tile::setX(int x) {
	xPos = x;
}
void Tile::setY(int y) {
	yPos = y;
}
bool Tile::getSpace() {
	return checkPlant;
}

int Tile::getX() {
	return xPos;
}
int Tile::getY() {
	return yPos;
}
int Tile::getHeight() {
	return height;

}
int Tile::getWidth() {
	return width;

}
void Tile::setGridPosition(int x, int y) {
	rectangleTile.setSize(sf::Vector2f(width, height));
	rectangleTile.setPosition(x, y);
	rectangleTile.setFillColor(sf::Color::White);
	rectangleTile.setOutlineColor(sf::Color::Black);
	rectangleTile.setOutlineThickness(2);
}
Tile::~Tile() {
	
}
void Tile::display(sf::RenderWindow & Window) {
	Window.draw(rectangleTile);
}
