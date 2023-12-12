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
    return alive;
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

void Snake::checkCollision(const Food &food){

    //does body collide with borders
    if (body[0].getPosition().x < 0 || body[0].getPosition().x >= windowWidth || body[0].getPosition().y < 0 || body[0].getPosition().y >= windowHeight) {
        alive = false;  // Snake collided with the walls
        return;
    }

    //does body collide with 
    for(int i = 1; i<body.size; ++i){

        //globalBounds checks if the globalbounds of the head intersects with the block of another body segment
    if(body[0].getGlobalBounds().intersects(body[i].getGlobalBounds())){
        alive = false;
        return;
    }
    }

    if(body[0].getGlobalBounds().intersects(sf::FloatRect(food.getPosition(), sf::Vector2f(food.foodSize, food.foodSize)))){
        grow();
        food.respawn();
    }

void Snake::render(sf::RenderWindow &window){
    for(const auto &segment : body){
        window.draw(segment);
    }
}
}