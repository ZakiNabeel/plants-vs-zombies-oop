#include "Game.h"
#include "Zombie.h"
#include <SFML/Audio.hpp>

Game::Game() : levelNumber(1), score(0), totalLevels(3), coins(500) {
    level = new Levels * [totalLevels];
    level[0] = new BeginersGarden();
    level[1] = new ZombieOutskirts();
    level[2] = new SunflowerFields();
    plantClicked = 0;
    sunPtr = nullptr;
    this->newLevelCheck = 0;
    lives = 1;
}

Game::~Game() {
    for (int i = 0; i < totalLevels; i++) {
        delete level[i];
    }
    delete[] level;
}

int Game::getLevelNumber() {
    return this->levelNumber;
}

// // void Game::run() {
// //     sf::RenderWindow window(sf::VideoMode(1400, 600), "Plants Vs Zombies");
// //     sf::Event event;
// //     bool gameStarted = false;
// //     bool instructionSelected = false;
// //     bool nameScreenSelected = false;
// //     sf::Clock clock;
// //     sf::Clock sunClock;
// //     sf::Font fontScore;
// //     fontScore.loadFromFile("KnightWarrior-w16n8.otf");
// //     sf::Text textScore;
// //     textScore.setFont(fontScore);
// //     textScore.setCharacterSize(40);
// //     textScore.setFillColor(sf::Color::Red);
// //     textScore.setPosition(1200, 0);
// //     textScore.setString("Coins: " + to_string(coins));
// //     sf::SoundBuffer music;
// //     music.loadFromFile("Peritune_Crimson_Moon-chosic.com_.mp3");
// //     while (window.isOpen())
// //     {
// //         while (window.pollEvent(event))
// //         {
// //             if (event.type == sf::Event::Closed)
// //                 window.close();
// //             if (!gameStarted && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
// //                 if (!instructionSelected && !nameScreenSelected) {
// //                     if (menuScreen.getPlayButton().wasClicked(window, event)) {
// //                         nameScreenSelected = true;
// //                     }
// //                     else if (menuScreen.getInstructionButton().wasClicked(window, event)) {
// //                         instructionSelected = true;
// //                     }
// //                 }
// //                 else if (nameScreenSelected && gameStarted==0) {
// //                     if (nameScreen.getOkButton().wasClicked(window, event)) {
// //                         gameStarted = true;
// //                         nameScreenSelected = false;
// //                     }
// //                 }
// //                 else if (instructionSelected && instructionScreen.getBackButton().wasClicked(window, event)) {
// //                     instructionSelected = false;
// //                 }
// //             }

// //         }
// //         window.clear();
// //         if (gameStarted == 1) {
// //             if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked == 0)
// //             {
// //                 cout << "MOUSE CLICKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LESGOO" << endl;
// //                 plantClicked = level[levelNumber - 1]->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
// //             }
// //             if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
// //                 cout << "DAN DANA DAN DAN DANA DAN DAN" << endl;
// //                 level[levelNumber - 1]->updatePlantFactory(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1, 1, 1, coins);
// //                 plantClicked = 0;
// //                 textScore.setString("Coins: " + to_string(coins));
// //             }
// //             if (sunClock.getElapsedTime().asSeconds() >= 15) {
// //                 sunGenerated = 1;
// //             }
// //             if (sunGenerated == 1) {
// //                 sunPtr = new Sun(((rand() % 10) + 2) * 100, 0, 1, 1, 0, 1);
// //                 sunGenerated = 0;
// //                 coins += 100;
// //                 sunClock.restart();
// //             }
// //             window.clear();
// //             level[levelNumber - 1]->createBack(window);
// //             window.draw(grid);
// //             level[levelNumber - 1]->update(coins);
// //             textScore.setString("Coins: " + to_string(coins));
// //             level[levelNumber - 1]->display(window);
// //             window.draw(textScore);
// //             if (sunPtr != nullptr) {
// //                 sunPtr->movement();
// //                 sunPtr->display(window);
// //             }
// //             if (level[levelNumber - 1]->checkZombieWin(level[levelNumber - 1]->getZombieFactory().getZombiePtr(), level[levelNumber - 1]->getZombieFactory().getSize(), lives)) {
// //                 window.close();
// //             }
// //             window.setSize(sf::Vector2u(1400, 600));
// //             window.display();
// //             if (!level[levelNumber - 1]->checkNewWave(levelNumber)) {
// //                 levelNumber++;
// //                 cout << "Done" << levelNumber << endl;
// //             }

// //        }
// //      else if (nameScreenSelected && gameStarted==0) {
// //         nameScreen.handleEvent(event);
// //         nameScreen.draw(window);
// //     }
// //     else if (instructionSelected) {
// //         instructionScreen.draw(window);
// //     }
// //     else {
// //         menuScreen.draw(window);
// //     }
// //     window.display();
// //     }
// // }
    //while (window.isOpen()) {
    //    window.clear();
    //    while (window.pollEvent(event)) {
    //        if (event.type == sf::Event::Closed) {
    //            window.close();
    //        }
    //        if (!gameStarted && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
    //            if (!instructionSelected && !nameScreenSelected) {
    //                if (menuScreen.getPlayButton().wasClicked(window, event)) {
    //                    nameScreenSelected = true;
    //                }
    //                else if (menuScreen.getInstructionButton().wasClicked(window, event)) {
    //                    instructionSelected = true;
    //                }
    //            }
    //            else if (nameScreenSelected) {
    //                if (nameScreen.getOkButton().wasClicked(window, event)) {
    //                    gameStarted = true;
    //                    nameScreenSelected = false;
    //                }
    //            }
    //            else if (instructionSelected && instructionScreen.getBackButton().wasClicked(window, event)) {
    //                instructionSelected = false;
    //            }
    //        }
    //    }

    //    if (gameStarted) {
    //        // Game logic when game has started
    //        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked == 0) {
    //            plantClicked = level[levelNumber - 1]->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    //        }
    //        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
    //            level[levelNumber - 1]->updatePlantFactory(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1, 1, 1, coins);
    //            plantClicked = 0;
    //            textScore.setString("Coins: " + to_string(coins));
    //        }
    //        if (sunClock.getElapsedTime().asSeconds() >= 15) {
    //            sunGenerated = 1;
    //        }
    //        if (sunGenerated == 1) {
    //            sunPtr = new Sun(((rand() % 10) + 2) * 100, 0, 1, 1, 0, 1);
    //            sunGenerated = 0;
    //            coins += 100;
    //            sunClock.restart();
    //        }
    //        window.clear();
    //        level[levelNumber - 1]->createBack(window);
    //        window.draw(grid);
    //        level[levelNumber - 1]->update(coins);
    //        textScore.setString("Coins: " + to_string(coins));
    //        level[levelNumber - 1]->display(window);
    //        window.draw(textScore);
    //        if (sunPtr != nullptr) {
    //            sunPtr->movement();
    //            sunPtr->display(window);
    //        }
    //        if (level[levelNumber - 1]->checkZombieWin(level[levelNumber - 1]->getZombieFactory().getZombiePtr(), level[levelNumber - 1]->getZombieFactory().getSize(), lives)) {
    //            window.close();
    //        }
    //        window.setSize(sf::Vector2u(1400, 600));
    //        window.display();
    //        if (!level[levelNumber - 1]->checkNewWave(levelNumber)) {
    //            levelNumber++;
    //        }
    //    }
    //    else if (nameScreenSelected) {
    //        nameScreen.handleEvent(event);
    //        nameScreen.draw(window);
    //    }
    //    else if (instructionSelected) {
    //        instructionScreen.draw(window);
    //    }
    //    else {
    //        menuScreen.draw(window);
    //    }
    //    window.display();
    //}

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(1400, 600), "Plants Vs Zombies");
    sf::Event event;
    bool gameStarted = false;
    bool instructionSelected = false;
    bool nameScreenSelected = false;
    bool winScreenSelected = false;
    bool loseScreenSelected = false;
    sf::Clock clock;
    sf::Clock sunClock;
    sf::Font fontScore;
    fontScore.loadFromFile("KnightWarrior-w16n8.otf");
    sf::Text textScore;
    textScore.setFont(fontScore);
    textScore.setCharacterSize(40);
    textScore.setFillColor(sf::Color::Red);
    textScore.setPosition(1200, 0);
    textScore.setString("Coins: " + to_string(coins));
    sf::Music music;
    music.openFromFile("It's My Life - Bon Jovi (Lyrics).mp3");
	music.setVolume(50);
	music.play();
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Handling button clicks when no game has started yet
            if (!gameStarted && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                if (!instructionSelected && !nameScreenSelected) {
                    if (menuScreen.getPlayButton().wasClicked(window, event)) {
                        nameScreenSelected = true;  // Only set nameScreen to active here
                    }
                    else if (menuScreen.getInstructionButton().wasClicked(window, event)) {
                        instructionSelected = true;  // Display instructions
                    }
                }
                else if (nameScreenSelected) {
                    if (nameScreen.getOkButton().wasClicked(window, event)) {
                        gameStarted = true;  // Start the game
                        nameScreenSelected = false;  // Exit name screen
                    }

                }
                else if (instructionSelected && instructionScreen.getBackButton().wasClicked(window, event)) {
                    instructionSelected = false;  // Go back to menu
                }
            }
        }

        window.clear();
        //if (gameStarted) {
            // The game level should be active only if gameStarted is true
            //if (levelNumber <= 3) {
            //    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked == 0) {
            //        plantClicked = level[levelNumber - 1]->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            //    }
            //    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
            //        level[levelNumber - 1]->updatePlantFactory(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1, 1, 1, coins);
            //        plantClicked = 0;
            //        textScore.setString("Coins: " + to_string(coins));
            //    }
            //    if (sunClock.getElapsedTime().asSeconds() >= 15) {
            //        sunGenerated = 1;
            //    }
            //    if (sunGenerated == 1) {
            //        sunPtr = new Sun(((rand() % 10) + 2) * 100, 0, 1, 1, 0, 1);
            //        sunGenerated = 0;
            //        coins += 100;
            //        sunClock.restart();
            //    }
            //    window.clear();
            //    level[levelNumber - 1]->createBack(window);
            //    window.draw(grid);
            //    level[levelNumber - 1]->update(coins);
            //    textScore.setString("Coins: " + to_string(coins));
            //    level[levelNumber - 1]->display(window);
            //    window.draw(textScore);
            //    if (sunPtr != nullptr) {
            //        sunPtr->movement();
            //        sunPtr->display(window);
            //    }
            //    if (!level[levelNumber - 1]->checkNewWave(levelNumber)) {
            //        levelNumber++;
            //    }
            //    if (level[levelNumber - 1]->checkZombieWin(level[levelNumber - 1]->getZombieFactory().getZombiePtr(), level[levelNumber - 1]->getZombieFactory().getSize(), lives)) {
            //        window.close();
            //    }

            //}
            if (gameStarted) {
                // The game level should be active only if gameStarted is true
                if (levelNumber == 1) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked == 0) {
                        cout << "MOUSE CLICKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LESGOO" << endl;
                        plantClicked = level[levelNumber-1]->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
                        cout << "DAN DANA DAN DAN DANA DAN DAN" << endl;
                        level[levelNumber - 1]->getPlantFactory().addPlant(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1, 1, 1,coins);
                        plantClicked = 0;
                    }
                    level[levelNumber - 1]->createBack(window);
                    level[levelNumber - 1]->update(coins);
                    textScore.setString("Coins: " + to_string(coins));
                    level[levelNumber - 1]->display(window);
                          if (sunPtr != nullptr) {
                    sunPtr->movement();
                    sunPtr->display(window);

                }
                          window.draw(textScore);

                if (!level[levelNumber - 1]->checkNewWave(levelNumber)) {
                    levelNumber++;
                }
                    if (level[levelNumber - 1]->checkZombieWin(level[levelNumber - 1]->getZombieFactory().getZombiePtr(), level[levelNumber - 1]->getZombieFactory().getSize(), lives)) {
                        loseScreen.draw(window);
                    }
                }
                else if (levelNumber == 2) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked == 0) {
                        cout << "MOUSE CLICKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LESGOO" << endl;
                        plantClicked = level[levelNumber - 1]->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
                        cout << "DAN DANA DAN DAN DANA DAN DAN" << endl;
                        level[levelNumber - 1]->getPlantFactory().addPlant(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1, 1, 1, coins);
                        plantClicked = 0;
                    }
                    level[levelNumber - 1]->createBack(window);
                    level[levelNumber - 1]->update(coins);
                    textScore.setString("Coins: " + to_string(coins));
                    level[levelNumber - 1]->display(window);
                    if (sunPtr != nullptr) {
                        sunPtr->movement();
                        sunPtr->display(window);

                    }
                    window.draw(textScore);
                    if (!level[levelNumber - 1]->checkNewWave(levelNumber)) {
                        levelNumber++;
                    }
                    if (level[levelNumber - 1]->checkZombieWin(level[levelNumber - 1]->getZombieFactory().getZombiePtr(), level[levelNumber - 1]->getZombieFactory().getSize(), lives)) {
                        loseScreen.draw(window);
                        window.close();
                    }
                }
                else if (levelNumber == 3) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && plantClicked == 0) {
                        cout << "MOUSE CLICKED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LESGOO" << endl;
                        plantClicked = level[levelNumber - 1]->checkMouseClick(window, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && plantClicked == 1) {
                        cout << "DAN DANA DAN DAN DANA DAN DAN" << endl;
                        level[levelNumber - 1]->getPlantFactory().addPlant(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1, 1, 1, coins);
                        plantClicked = 0;
                    }
                    level[levelNumber - 1]->createBack(window);
                    level[levelNumber - 1]->update(coins);
                    textScore.setString("Coins: " + to_string(coins));
                    level[levelNumber - 1]->display(window);
                    if (sunPtr != nullptr) {
                        sunPtr->movement();
                        sunPtr->display(window);

                    }
                    window.draw(textScore);
                    if (!level[levelNumber - 1]->checkNewWave(levelNumber)) {
                        levelNumber++;
                    }
                    if (level[levelNumber - 1]->checkZombieWin(level[levelNumber - 1]->getZombieFactory().getZombiePtr(), level[levelNumber - 1]->getZombieFactory().getSize(), lives)) {
                        loseScreen.draw(window);
                    }
                }
                else {
                    winScreen.draw(window);
                }
            }


            else if (nameScreenSelected) {
                nameScreen.handleEvent(event); // Handle events specific to name screen
                nameScreen.draw(window);
            }
            else if (instructionSelected) {
                instructionScreen.draw(window);
            }
            else {
                menuScreen.draw(window);
            }
            window.setSize(sf::Vector2u(1400, 600));
            window.display();
        }
   }

