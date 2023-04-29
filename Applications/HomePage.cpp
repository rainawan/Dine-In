//
// Created by Raina Wan on 4/18/23.
//

#include "HomePage.h"

HomePage::HomePage() {
    States::enableState(TEXT_INPUT);
    init();
}

void HomePage::init() {
    setupHeader();
    setupTextInput();
    setupSprite();
    setupRestaurants();
}

void HomePage::setupHeader() {
    header.setString("Dine-In");
    header.setFont(Fonts::getFont(EVIDANCE));
    header.setCharacterSize(200);
    header.setFillColor(sf::Color::Black);
    header.setPosition({780,200});
}

void HomePage::setupTextInput() {
    text_input.setPosition({700,500});
}

void HomePage::setupSprite() {
    background.setSprite(HOME);
    background.sf::RectangleShape::setScale({4.5, 4});

    search_sprite.setSprite(SEARCH);
    search_sprite.sf::RectangleShape::setScale({.23,.23});
    search_sprite.sf::RectangleShape::setPosition({text_input.getPosition().x + text_input.getGlobalBounds().width + 15, text_input.getPosition().y - 9});
}

void HomePage::setupRestaurants() {
    restaurants.setPosition({200,300});
}

void HomePage::repositionTextInput(sf::Vector2f pos) {
    text_input.setPosition(pos);
    search_sprite.sf::RectangleShape::setPosition({text_input.getPosition().x + text_input.getGlobalBounds().width + 15, text_input.getPosition().y - 9});
    yellow_box.setFillColor(sf::Color(247, 255, 184));
    yellow_box.setSize({search_sprite.getGlobalBounds().width / 2,search_sprite.getGlobalBounds().height / 2});
    Position::center(search_sprite, yellow_box);
}

void HomePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    if (!getState(REST_PAGE)) {
        target.draw(background);
        target.draw(header);
    }
    if (getState(REST_PAGE)) {
        target.draw(restaurants);
    }
    if (getState(TEXT_INPUT) && !restaurants.getState(HIDE_TEXT)) {
        if (getState(YELLOW_BOX)) {
            target.draw(yellow_box);
        }
        target.draw(text_input);
        target.draw(search_sprite);
    }
}

void HomePage::eventHandler(sf::RenderWindow &window, sf::Event event) {
    text_input.eventHandler(window, event);

    if (MouseEvents::isClicked(search_sprite, window)) {
        enableState(REST_PAGE);
        disableState(HOME_PAGE);
    }
    if (getState(REST_PAGE)) {
        restaurants.eventHandler(window, event);
        restaurants.enableState(REST_PAGE);
    }
}

void HomePage::update() {
    text_input.update();
    if (getState(REST_PAGE)) {
        repositionTextInput({180,100});
        enableState(YELLOW_BOX);
    }
}

Snapshot *HomePage::getSnapshot() {

}

void HomePage::applySnapshot(Snapshot *snapshot) {

}
