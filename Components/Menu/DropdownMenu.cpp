//
// Created by Raina Wan on 3/24/23.
//

#include "DropdownMenu.h"


DropdownMenu::DropdownMenu() {

}

DropdownMenu::DropdownMenu(std::initializer_list<std::string> items) {
    //iterator used to iterate through any collection
    for (auto it = items.begin(); it != items.end(); ++it) {
        list.addItem(*it);
    }
    float width = list.getItems().begin()->getGlobalBounds().width;
    float height = list.getItems().begin()->getGlobalBounds().height;
    header.setString(*items.begin());
    header.setBoxSize({width, height});
    init();
}

void DropdownMenu::init() {
    list.enableState(HIDDEN);
}

void DropdownMenu::addItem(std::string item) {
    list.addItem(item);
}

void DropdownMenu::setPosition(const sf::Vector2f &position) {
    header.setPosition(position);
    Position::bottom(header, list, 10);
}

void DropdownMenu::setHeader(std::string string) {
    header.setString(string);
}

sf::Vector2f DropdownMenu::getPosition() {
    return header.getPosition();
}

sf::FloatRect DropdownMenu::getGlobalBounds() {
    sf::FloatRect f = list.getGlobalBounds();
    f.height += header.getGlobalBounds().height;
    return f;
}

void DropdownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(header);
    target.draw(list);
}

void DropdownMenu::eventHandler(sf::RenderWindow &window, sf::Event event) {
    list.eventHandler(window, event);
    header.eventHandler(window, event);

    if(MouseEvents::isClicked(header, window)) {
        list.disableState(HIDDEN);
    }
    if (MouseEvents::isNotClicked(header, window)) {
        disableState(HIGHLIGHT);
    }

    for(Item& item : list.getItems()) {

        item.eventHandler(window, event);
        if (MouseEvents::isClicked(item, window)) {
            History::push({this, getSnapshot()});
            list.enableState(HIDDEN);
            if (!getState(NO_CHANGE))
                header.setString(item.getString());
        }
        item.disableState(SHOWN);
    }


    if(MouseEvents::isNotClicked(header, window)) {
        std::string s;
        for(Item& l : list.getItems()) {
            if(MouseEvents::isClicked(l, window)) {
                if (l.getString() == "Resize")
                    window.setSize({1920, 1080});
            }
        }
        list.enableState(HIDDEN);
    }
}

void DropdownMenu::update() {

}

Snapshot *DropdownMenu::getSnapshot() {
    DropdownSnapshot* p = new DropdownSnapshot;
    p->setData(header.getString());
    return p;
}

void DropdownMenu::applySnapshot(Snapshot *snapshot) {
    header.applySnapshot(snapshot);
    std::cout << header.getString();
}
