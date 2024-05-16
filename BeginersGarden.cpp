#include"BeginersGarden.h"
BeginersGarden::BeginersGarden() : Levels(1){
}
BeginersGarden::~BeginersGarden() {
}
void BeginersGarden::display(sf::RenderWindow& Window) {
	Levels::display(Window);
}
void BeginersGarden::update(int& coins1) {
	Levels::update(coins1);
}

void BeginersGarden::createBack(sf::RenderWindow& window) {
	(Levels::textureBackGround).loadFromFile("level1.png");
	(Levels::spriteBackGround).setTexture((Levels::textureBackGround));
	window.draw(spriteBackGround);
}