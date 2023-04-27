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
    setupSubmit();

}

void ReservationPage::setupHeader(std::string string) {
    header.setString(string);
    header.setFont(Fonts::getFont(LOUISE));
    header.setCharacterSize(130);
    header.setFillColor(sf::Color::White);
    header.setPosition({200,150});

    underline.setSize({2000,7});
    underline.setPosition({header.getPosition().x, header.getPosition().y + header.getGlobalBounds().height + 70});
}

void ReservationPage::setupImage(image_enum image) {
    inside.setSprite(image);
    inside.sf::RectangleShape::setScale({1.2,1.2});
    inside.sf::RectangleShape::setPosition({header.getPosition().x, header.getPosition().y + 300});
}

void ReservationPage::setupBackground() {
    background.setSprite(RESERVE);
    background.sf::RectangleShape::setScale({.42,.38});

    back.setSprite(BACK);
    back.sf::RectangleShape::setScale({.08,.08});
    back.sf::RectangleShape::setPosition({30,40});
}

void ReservationPage::setupSubmit() {
    submit = {"Reserve", {800, 50}};
    submit.setBackgroundColor(sf::Color::White);
    submit.setTextColor(sf::Color::Red);
    submit.setPosition({party_size.getPosition().x, party_size.getPosition().y + 130});
}

void ReservationPage::setupMenu() {
    date = {"Friday, April 28", "Saturday, April 29", "Sunday, April 30"};
    date.setHeader("Date");
    date.setPosition({1400, 500});

    time = {"7:00 PM", "7:30 PM", "8:00 PM", "8:30 PM", "9:00 PM"};
    time.setHeader("Time");
    time.setPosition({date.getPosition().x + date.getGlobalBounds().width, date.getPosition().y});

    party_size = {"1", "2" ,"3", "4", "5", "6", "7", "8+"};
    party_size.setHeader("Party Size");
    party_size.setPosition({date.getPosition().x, 800});
}

void ReservationPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(back);

    target.draw(header);
    target.draw(underline);
    target.draw(inside);

    target.draw(date);
    target.draw(time);
    target.draw(party_size);
    target.draw(submit);
}

void ReservationPage::eventHandler(sf::RenderWindow &window, sf::Event event) {
    date.eventHandler(window, event);
    time.eventHandler(window, event);
    party_size.eventHandler(window, event);
    if (MouseEvents::isClicked(back, window)) {
        enableState(REST_PAGE);
    }

}

void ReservationPage::update() {

}

Snapshot *ReservationPage::getSnapshot() {
    return nullptr;
}

void ReservationPage::applySnapshot(Snapshot *snapshot) {

}
