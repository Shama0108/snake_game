//The engine of the game. Orchestrates everything
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.h>
#include "Snake.h"
#include "Food.h"
#include "InputManager.h"



class Game{
private:

    Snake snake;
    Food food;
    InputManager inputManager;
    

public:

    Game();
    void initialize();
    void run();


};

#endif