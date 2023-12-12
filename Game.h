//The engine of the game. Orchestrates everything
#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Food.h"
#include "InputManager.h"
#include "GraphicsManager.h"
#include "CollisionManager.h"
#include "ScoreManager.h"
#include "GameState.h"
#include "GameOverScreen.h"


class Game{
private:

    Snake snake;
    Food food;
    InputManager inputManager;
    GraphicsManager graphicsManager;
    CollisionManager collisionManager;
    ScoreManager scoreManager;
    GameOverScreen gameoverScreen;

public:

    Game();
    void initialize();
    void run();


};

#endif