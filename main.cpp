#include <SFML/Graphics.hpp>

int main(){
    //create the main window
    sf::RenderWindow window(sf::VideoMode(800,600), "Snake Game");

    window.setFramerateLimit(30);

    //Window lifecycle
    while(window.isOpen()){

        sf:: Event event;
        while(window.pollEvent(event)){
            //handle different events

            if(event.type == sf::Event::Closed){
                window.close();
            }
        }


        window.clear(); //clears the previous frame


        //Game logic goes here

        //Draw game elements on the window


        window.display();
    }

    return 0;
}