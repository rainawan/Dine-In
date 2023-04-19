//
// Created by Raina Wan on 3/29/23.
//

#ifndef MENU_HISTORY_H
#define MENU_HISTORY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include "../../SFMLTools/GUIComponent.h"
#include "Snapshot.h"

struct HistoryNode {
    GUIComponent* component;
    Snapshot* snapshot;
};

class History {
private:
    static std::stack<HistoryNode> stack;
public:
    static HistoryNode& top();
    static void pop();
    static void push(const HistoryNode& node);
    static void empty();
    static int size();
    static void eventHandler(sf::RenderWindow& window, sf::Event event);
};


#endif //MENU_HISTORY_H
