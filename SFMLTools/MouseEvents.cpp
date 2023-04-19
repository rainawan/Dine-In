//
// Created by Raina Wan on 3/24/23.
//

#ifndef MENU_MOUSEEVENTS_CPP
#define MENU_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<class T>
bool MouseEvents::isHovered(const T &Obj, const sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return Obj.getGlobalBounds().contains(mpos);
}

template<class T>
bool MouseEvents::isClicked(const T &Obj, const sf::RenderWindow &window) {
    return isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents::isNotClicked(const T &Obj, const sf::RenderWindow &window) {
    return !isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif