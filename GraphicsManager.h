//responsible for drawing the images on the window
#pragma
#include <SFML/Graphics.hpp>

class GraphicsManager{
    private:
        sf::RenderWindow &renderWindow;

    public:
        GraphicsManager(sf::RenderWindow &window);
        void drawSnake(const Snake& snake);
        void drawFood(const Food& food);
        void clearScreen();
        void display();
};