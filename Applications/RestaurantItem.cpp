//
// Created by Raina Wan on 4/19/23.
//

#include "RestaurantItem.h"

RestaurantItem::RestaurantItem() : RestaurantItem("RestItem", {600,300}, FOOD){

}

RestaurantItem::RestaurantItem(std::string string, sf::Vector2f size, image_enum icon) {
    setupText(string, size);
    setupSprite(icon);
    reposition();
}

void RestaurantItem::setupText(std::string string, sf::Vector2f size) {
    item.reinitialize(string, size);
}

void RestaurantItem::setupSprite(image_enum icon) {
    rest_sprite.setSprite(icon);
    rest_sprite.sf::RectangleShape::setScale({.3, .3});
}

void RestaurantItem::reposition() {

}

void RestaurantItem::setScale(sf::Vector2f scale) {
    rest_sprite.sf::RectangleShape::setScale(scale);
}

void RestaurantItem::setPosition(const sf::Vector2f &position) {

}

void RestaurantItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(item);
    target.draw(rest_sprite);
}

void RestaurantItem::eventHandler(sf::RenderWindow &window, sf::Event event) {
    // on hover, highlight border
    if (MouseEvents::isHovered(item, window)) {
        item.setOutlineColor(sf::Color::Red);
    }
    if (!MouseEvents::isHovered(item, window)) {
        item.setOutlineColor(sf::Color::Black);
    }
}

void RestaurantItem::update() {

}

Snapshot *RestaurantItem::getSnapshot() {
    return nullptr;
}

void RestaurantItem::applySnapshot(Snapshot *snapshot) {

}
