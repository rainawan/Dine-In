//
// Created by Raina Wan on 3/24/23.
//

#ifndef MENU_POSITION_H
#define MENU_POSITION_H
#include <SFML/Graphics.hpp>
#include <cmath>

class Position {
public:
    template<class T, class S>
    static void left(const T &obj1, S &obj2, float spacing = 0); //positions S to left of T
    template<class T, class S>
    static void right(const T &obj1, S &obj2, float spacing = 0);
    template<class T, class S>
    static void center(const T &obj1, S &obj2, float spacing = 0);
    template<class T, class S>
    static void bottom(const T &obj1, S &obj2, float spacing = 0);
    template<class T, class S>
    static void top(const T &obj1, S &obj2, float spacing = 0);
    template<typename T>
    static void centerText(const T &obj, sf::Text &text);
    void test();
};

#include "Position.cpp"
#endif //MENU_POSITION_H
