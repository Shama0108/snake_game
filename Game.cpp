#include "Game.h"


Game::Game(){
    snake = Snake(sf::Vector2f(400,300), 3, sf::Color::Green);
    food = Food();
    inputManager = InputManager();
}

void Game::run(){
    sf::RenderWindow window(sf::VideoMode(800,600), "Snake Game");

    window.setFramerateLimit(30);

    //Window lifecycle
    while(window.isOpen()){

        sf:: Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }


        window.clear(); //clears the previous frame

        

        if(inputManager.isKeyPressed(sf::Keyboard::Up)){
            snake.setDirection(sf::Vector2f(0.0f, -1.0f));             
        }else if(inputManager.isKeyPressed(sf::Keyboard::Down)){
            snake.setDirection(sf::Vector2f(0.0f, 1.0f));
        }else if(inputManager.isKeyPressed(sf::Keyboard::Right)){
            snake.setDirection(sf::Vector2f(1.0f, 0.0f));
        }else if(inputManager.isKeyPressed(sf::Keyboard::Left)){
            snake.setDirection(sf::Vector2f(-1.0f, 0.0f));
        }

        snake.move();
        snake.checkCollision(food);

        window.clear();
        snake.render(window);
        food.render(window);
      

        window.display();
    }
}