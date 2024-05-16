#include "Screen.h"
Screen::Screen(const std::string& backgroundImagePath) {
    screenTexture.loadFromFile(backgroundImagePath);
    screenSprite.setTexture(screenTexture);
}