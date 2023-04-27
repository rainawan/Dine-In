//
// Created by Raina Wan on 4/26/23.
//

#include "App.h"

App::App() {
    init();
}

void App::init() {
    setupTextInput();
    setupSprite();
}

void App::setupTextInput() {
    text_input.setPosition({700,500});
}

void App::setupSprite() {
    search_sprite.setSprite(SEARCH);
    search_sprite.sf::RectangleShape::setScale({.23,.23});
    search_sprite.sf::RectangleShape::setPosition({text_input.getPosition().x + text_input.getGlobalBounds().width + 15, text_input.getPosition().y - 9});
}

void App::repositionTextInput(sf::Vector2f pos) {
    text_input.setPosition(pos);
    search_sprite.sf::RectangleShape::setPosition({text_input.getPosition().x + text_input.getGlobalBounds().width + 15, text_input.getPosition().y - 9});
    restaurant.setPosition({200,300});
}

void App::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    if (getState(HOME_PAGE)) {
//        target.draw(home);
//        target.draw(text_input);
//        target.draw(search_sprite);
//    }
//
//    if (getState(REST_PAGE)) {
//        target.draw(reserve);
//        target.draw(text_input);
//        target.draw(search_sprite);
//    }
//
//    if (getState(RESERVE_PAGE)) {
//        target.draw(reserve);
//    }
//    target.draw(reserve);
}

void App::eventHandler(sf::RenderWindow &window, sf::Event event) {
//    home.eventHandler(window, event);

//    text_input.eventHandler(window, event);
//
//    if (MouseEvents::isClicked(search_sprite, window)) {
//        enableState(REST_PAGE);
//        disableState(HOME_PAGE);
//    }
//    if (getState(REST_PAGE)) {
//        reserve.eventHandler(window, event);
//    }
//    if (getState(RESERVE_PAGE)) {
//        reserve.eventHandler(window, event);
//    }
//reserve.eventHandler(window, event);
}

void App::update() {
//    home.update();
//    text_input.update();
//
//    if (getState((REST_PAGE)))
//        repositionTextInput({180,100});
//
//    if (getState(RESERVE_PAGE)) {
//        reserve = reserve.getReserveItem();
//    }
}

Snapshot *App::getSnapshot() {
    return nullptr;
}

void App::applySnapshot(Snapshot *snapshot) {

}
