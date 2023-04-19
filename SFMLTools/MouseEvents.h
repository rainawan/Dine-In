//
// Created by Raina Wan on 3/24/23.
//

#ifndef MENU_MOUSEEVENTS_H
#define MENU_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents {
private:
    static sf::Clock clock;
    static int clicks;
    static void countClicks(sf::Event event);
public:
    template<class T>
    static bool isHovered(const T& Obj, const sf::RenderWindow& window);
    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow& window);
    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow& window);
};

#include "MouseEvents.cpp"
#endif //MENU_MOUSEEVENTS_H
