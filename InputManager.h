//handles user input such as the key pressed for motion

#pragma
#include <SFML/Window.hpp>

class InputManager{

    private:
        bool keyStates[sf::Keyboard::KeyCount]; //a constant that represents the total number of keys available in the sf::keyboard.
        //Used to determine the size of the keyStates array.

    public:
        InputManager();
        bool isKeyPressed(sf::Keyboard::Key key) const; //sf::Keyboard provides a set of static constants for various keys
        // to check if a certain key is pressed: sf::Keyboard::isKeyPressed(sf::Keyboard::A)
        //will be used to direct the snake
};