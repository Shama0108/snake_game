#include "Food.h"

Food::Food(){
    foodColor = sf::Color::Red;
    foodSize = 10.0f;
    position = sf::Vector2f(0.0f, 0.0f);

    respwan();
}

sf::Vector2f Food::getPosition() const{
    return position;
}

void Food::respawn(){

    //we going to pick a random number in the range of 0-800 minus 10 after dividing the random number by the range to 
    //ensure the random number is within that specific range
    //800 is the width of the window and 600 is the height of the window
    position.x = static_cast<float>(rand() % (800-static_cast<int>(foodSize)));
    position.y = static_cast<float>(rand() %(600 - static_cast<int>(foodSize)));

}

void Food::render(sf::RenderWindow &window){
    sf::RectangleShape foodShape(sf::Vector2f(foodSize, foodSize));
    foodShape.setFillColor(foodColor);
    foodShape.setPosition(position);
    window.draw(foodShape);
}