// Behaviors of the snake

#pragma


#include <SFML/Graphics.hpp>
#include <vector>

class Snake{
    private:

    //the body segments. SFML is used
    std::vector<sf::RectangleShape> body;


    // a 2D vector in SFML will be used for direction
    sf:: Vector2f direction;

    float speed;
    int size; //size of each body segment
    sf::Color color;
    bool Alive;

    public:
    Snake(sf::Vector2f startPosition, int initialSize, sf::Color color);
    bool isAlive() const;
    void move();
    void grow();
    void checkCollision(const Food &food);
    void render(sf::RenderWindow &window);
};



