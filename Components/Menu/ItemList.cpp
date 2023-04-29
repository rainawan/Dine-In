//
// Created by Raina Wan on 3/24/23.
//

#include "ItemList.h"

void ItemList::addItem(const std::string &text, void (*f)()) {
    items.emplace_back(text, sf::Vector2f(400.f,80.f));
    position();
}

void ItemList::addItem(const Item &item, void (*f)()) {
    items.push_back(item);
    position();
}

void ItemList::setPosition(const sf::Vector2f &position) {
    items[0].setPosition(position);
    this->position();
}

void ItemList::setPosition(float x, float y) {
    setPosition({x,y});
}

sf::FloatRect ItemList::getHeaderBounds() {
    return items[0].getGlobalBounds();
}

sf::FloatRect ItemList::getGlobalBounds() {
    sf::FloatRect f = items[0].getGlobalBounds();
    f.height *= items.size();
    return f;
}

std::vector<Item> &ItemList::getItems() {
    return items;
}

void ItemList::position() {
    for (int i = 1; i < items.size(); ++i) {
        Position::bottom(items[i-1], items[i], 10);
    }
}

void ItemList::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!getState(HIDDEN)) {
        for(const Item& l : items)
            target.draw(l);
    }
}

void ItemList::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for(Item& l : items)  //loop through all items in listItem
        l.eventHandler(window, event);
}

void ItemList::update() {

}

Snapshot *ItemList::getSnapshot() {
    for (int i = 0; i < items.size(); ++i) {
        items[i].getSnapshot();
    }
}

void ItemList::applySnapshot(Snapshot *snapshot) {
    for (int i = 0; i < items.size(); ++i) {
        items[i].applySnapshot(snapshot);
    }
}
