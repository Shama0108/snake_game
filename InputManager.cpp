#include "InputManager.h"

InputManager::InputManager(){

    for(int i = 0; i<sf::Keyboard::Keycount; ++i){
        keyStates[i] = false;
    }
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key)const{
    return keyStates[key];
}

void InputManager::update(){

    for(int i =0; i<sf::Keybaord::Keycount; ++i){
        keyStates[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
    }
}