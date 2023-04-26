//
// Created by Raina Wan on 4/26/23.
//

#include "App.h"

App::App() {

}

void App::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!getState(REST_PAGE)) {
//        home.draw(target, states);
        target.draw(home);
    }
    if (States::getState(REST_PAGE)) {
        target.draw(restaurant);
    }
}

void App::eventHandler(sf::RenderWindow &window, sf::Event event) {
    home.eventHandler(window, event);
    if (getState(REST_PAGE)) {
        restaurant.eventHandler(window, event);
    }
}

void App::update() {
    home.update();
}

Snapshot *App::getSnapshot() {
    return nullptr;
}

void App::applySnapshot(Snapshot *snapshot) {

}
