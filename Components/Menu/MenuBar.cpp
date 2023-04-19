//
// Created by Raina Wan on 3/30/23.
//

#include "MenuBar.h"

MenuBar::MenuBar() {

}

MenuBar::MenuBar(int num_menus) {
    for (int i = 0; i < 1; ++i) {
        DropdownMenu menu;
        menus.push_back(menu);
    }
    setup();
}

void MenuBar::addItem(std::string header, std::initializer_list<std::string> items) {
    DropdownMenu menu = items;
    menu.setHeader(header);
    menus.push_back(menu);
    setup();
}

void MenuBar::setup() {
    menus[0].setPosition({0, 0});
    for (int i = 1; i < menus.size(); ++i) {
        menus[i].setPosition({menus[i-1].getPosition().x + menus[i-1].getGlobalBounds().width + 10, menus[i-1].getPosition().y});
    }
}

void MenuBar::setPosition(const sf::Vector2f &position) {
//    menus[0].setPosition(position); // WRONG
    for (int i = 0; i < menus.size(); ++i) {
        menus[i].setPosition(position);
    }
}

void MenuBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < menus.size(); ++i) {
        target.draw(menus[i]);
    }
}

void MenuBar::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < menus.size(); ++i) {
        menus[i].enableState(NO_CHANGE);
        menus[i].eventHandler(window, event);
        History::eventHandler(window, event);
    }
}

void MenuBar::update() {

}

Snapshot *MenuBar::getSnapshot() {
    return nullptr;
}

void MenuBar::applySnapshot(Snapshot *snapshot) {

}
