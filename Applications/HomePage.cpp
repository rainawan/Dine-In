//
// Created by Raina Wan on 4/18/23.
//

#include "HomePage.h"

HomePage::HomePage() {
    init();
}

void HomePage::init() {
    setupHeader();
    setupTextInput();
    setupSprite();
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

void HomePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(text_input);
    target.draw(header);
    target.draw(search_sprite);
}

void HomePage::eventHandler(sf::RenderWindow &window, sf::Event event) {
    text_input.eventHandler(window, event);
}

void HomePage::update() {
    text_input.update();
}

Snapshot *HomePage::getSnapshot() {

}

void HomePage::applySnapshot(Snapshot *snapshot) {

}
