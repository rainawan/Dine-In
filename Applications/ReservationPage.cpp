//
// Created by Raina Wan on 4/21/23.
//

#include "ReservationPage.h"

ReservationPage::ReservationPage() : ReservationPage(RestaurantItem("Bone Kettle", {1400, 250}, BONE_KETTLE, FIVESTAR, 4), FOOD) {

}

ReservationPage::ReservationPage(RestaurantItem item, image_enum image) {
    setupHeader(item.getString());
    setupImage(image);
    setupBackground();
    setupMenu();
}

void ReservationPage::setupHeader(std::string string) {
    header.setString(string);
    header.setFont(Fonts::getFont(LOUISE));
    header.setCharacterSize(100);
    header.setFillColor(sf::Color::White);
}

void ReservationPage::setupImage(image_enum image) {
    food.setSprite(image);
}

void ReservationPage::setupBackground() {
    background.setSprite(RESERVE);
    background.sf::RectangleShape::setScale({.42,.38});
}

void ReservationPage::setupMenu() {
    date = {"Friday, April 28", "Saturday, April 29", "Sunday, April 30"};
    date.setHeader("Date");
    date.setPosition({500, 500});

    time = {"7:00 PM", "7:30 PM", "8:00 PM", "8:30 PM", "9:00 PM"};
    time.setHeader("TIME");
    time.setPosition({1000,500});

    party_size = {"1", "2" ,"3", "4", "5", "6", "7", "8+"};
    party_size.setHeader("Party Size");
    party_size.setPosition({500, 800});
}

void ReservationPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(header);
    target.draw(date);
    target.draw(time);
    target.draw(party_size);
}

void ReservationPage::eventHandler(sf::RenderWindow &window, sf::Event event) {
    date.eventHandler(window, event);
    time.eventHandler(window, event);
    party_size.eventHandler(window, event);
}

void ReservationPage::update() {

}

Snapshot *ReservationPage::getSnapshot() {
    return nullptr;
}

void ReservationPage::applySnapshot(Snapshot *snapshot) {

}
