//
// Created by Raina Wan on 3/29/23.
//

#include "History.h"

std::stack<HistoryNode> History::stack;

HistoryNode &History::top() {
    return stack.top();
}

void History::pop() {
    if (!stack.empty()) {
        top().component->applySnapshot(top().snapshot);
        delete top().snapshot;
        stack.pop();
    }
}

void History::push(const HistoryNode &node) {
    stack.push(node);
}

void History::empty() {
    stack.empty();
}

int History::size() {
    return stack.size();
}

void History::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem)) {
        pop();
    }
}