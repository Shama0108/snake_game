#include "Snake.h"

Snake::Snake(sf::Vector2f startPosition, int initialSize, sf::Color color){
    this->direction = sf::Vector2f(1.0f,0.0f); //initial direction
    this->size = initialSize;
    this->color = color;
    this->Alive = true;
    this->speed = 1.0f;


    //  initialize the body of the snake
    for(int i = 0; i<initialSize; ++i){

        //create a body segment
        sf::RectangleShape segment(sf::Vector2f(size,size));


        //ensure each segment is positioned horizontally on the left of the previous one
        segment.setPosition(startPosition.x - i* size, startPosition.y);
        //set color of segment
        segment.setFillColor(color);
        //add segment to body vector
        body.push_back(segment);


    }
}

bool Snake::isAlive() const{
    return Alive;
}

Snake::Snake() : direction(0.0f, 0.0f), speed(1.0f), size(1), color(sf::Color::White), Alive(true) {
    // Additional initialization logic for the default constructor
    // For example, initialize the body vector with a default segment
    sf::RectangleShape segment(sf::Vector2f(10.0f, 10.0f));
    segment.setFillColor(color);
    body.push_back(segment);
}



void Snake::move(){
    for(int i = body.size() -1; i>0; --i){
        body[i].setPosition(body[i-1].getPosition());
    }

    body[0].move(direction*speed);
}

void Snake::grow(){

    sf::RectangleShape segment(sf::Vector2f(size,size));
    segment.setPosition(body.back().getPosition());
    segment.setFillColor(color);
    body.push_back(segment);

}

void Snake::setDirection(const sf::Vector2f &newDirection){
    direction = newDirection;
}

void Snake::checkCollision( Food &food){

    //does body collide with borders
    if (body[0].getPosition().x < 0 || body[0].getPosition().x >= 800 || body[0].getPosition().y < 0 || body[0].getPosition().y >= 600) {
        Alive = false;  // Snake collided with the walls
        return;
    }

    //does body collide with itself
    for(int i = 1; i<body.size(); ++i){

        //globalBounds checks if the globalbounds of the head intersects with the block of another body segment
    if(body[0].getGlobalBounds().intersects(body[i].getGlobalBounds())){
        Alive = false;
        return;
    }
    }

    if(body[0].getGlobalBounds().intersects(sf::FloatRect(food.getPosition(), sf::Vector2f(food.getFoodSize(), food.getFoodSize())))){
        grow();
        food.respawn();
    }

void Snake::render(sf::RenderWindow &window){
    for(const auto &segment : body){
        window.draw(segment);
    }
}
}