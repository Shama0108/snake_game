//food items the snake can eat
#pragma
#include <SFML/Graphics.hpp>

class Food{

    private:
        sf::Color foodColor;
        float foodSize;
        sf::Vector2f position;

    public:
        Food();
        void respawn();
        void render(sf::RenderWindow &window);
        float getFoodSize();
        
        sf::Vector2f getPosition() const;

};

