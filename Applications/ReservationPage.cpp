//
// Created by Raina Wan on 4/21/23.
//

#include "ReservationPage.h"

ReservationPage::ReservationPage() : ReservationPage(RestaurantItem("Bone Kettle", {1400, 250}, BONE_KETTLE, FIVESTAR, 4), FOOD) {

}

ReservationPage::ReservationPage(RestaurantItem item, image_enum image) {
    setupHeader(item.getString());
    setupImage(item.getString());
    setupBackground();
    setupMenu();
    setupInfo(item.getString());
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

void ReservationPage::setupImage(std::string s) {
    switch(s[0]) {
        case 'B':
            inside.setSprite(BK_INSIDE);
            inside.sf::RectangleShape::setScale({1.4,1.2});
            break;
        case 'M':
            inside.setSprite(M_INSIDE);
            inside.sf::RectangleShape::setScale({1.4,1.3});
            break;
        case 'G':
            inside.setSprite(G_INSIDE);
            inside.sf::RectangleShape::setScale({1.1,1});
            break;
        case 'U':
            inside.setSprite(U_INSIDE);
            inside.sf::RectangleShape::setScale({1.4,1.3});
            break;
        default:
            inside.setSprite(BONE_KETTLE);
            break;
    }
    inside.sf::RectangleShape::setPosition({header.getPosition().x, header.getPosition().y + 300});
}

void ReservationPage::setupBackground() {
    background.setSprite(RESERVE);
    background.sf::RectangleShape::setScale({.42,.38}); // reserve

    back.setSprite(BACK);
    back.sf::RectangleShape::setScale({.08,.08});
    back.sf::RectangleShape::setPosition({30,40});
}

void ReservationPage::setupSubmit() {
    submit = {"Reserve", {800, 80}};
    submit.setBackgroundColor(sf::Color::White);
    submit.setTextColor(sf::Color::Red);
    submit.setPosition({party_size.getPosition().x, location.getPosition().y + location.getGlobalBounds().height + 100});

    confirmation.setString("Reservation Confirmed. See you soon!");
    confirmation.setFont(Fonts::getFont(LOUISE));
    confirmation.setPosition({submit.getPosition().x, submit.getPosition().y + submit.getGlobalBounds().height + 10});
}

void ReservationPage::setupMenu() {
    date = {"Friday, April 28", "Saturday, April 29", "Sunday, April 30"};
    date.setHeader("Date");
    date.setPosition({1400, 450});

    time = {"7:00 PM", "7:30 PM", "8:00 PM", "8:30 PM", "9:00 PM"};
    time.setHeader("Time");
    time.setPosition({date.getPosition().x + date.getGlobalBounds().width + 10, date.getPosition().y});

    party_size = {"1", "2" ,"3", "4", "5", "6", "7", "8+"};
    party_size.setHeader("Party Size");
    party_size.setPosition({date.getPosition().x, date.getPosition().y + date.getHeaderBounds().height + 10});

    requests = {"Indoor Seating", "Outdoor Seating"};
    requests.setHeader("Requests");
    requests.setPosition({party_size.getPosition().x + party_size.getGlobalBounds().width + 10, party_size.getPosition().y});
}

void ReservationPage::setupInfo(std::string s) {
    switch(s[0]) {
        case 'B':
            website.setString("https://www.bonekettle.com");
            contact.setString("(626) 314-5185");
            location.setString("67 N Raymond Ave\n"
                               "Pasadena, CA 91103");
            break;
        case 'M':
            website.setString("https://www.milliescafela.com");
            contact.setString("(626) 486-2407");
            location.setString("1399 E Washington Blvd\n"
                               "Pasadena, CA 91104");
            break;
        case 'G':
            website.setString("https://www.granvillerestaurants.com/");
            contact.setString("(626) 360-7633");
            location.setString("270 S Lake Ave\n"
                               "Pasadena, CA 91101");
            break;
        case 'U':
            website.setString("https://urthcaffe.com");
            contact.setString("(626) 844-4644");
            location.setString("594 E Colorado Blvd\n"
                               "Pasadena, CA 91101");
            break;
        default:
            website.setString("Default");
            contact.setString("Default");
            location.setString("Default");
            break;
    }

    website.setFont(Fonts::getFont(LOUISE));
    contact.setFont(Fonts::getFont(LOUISE));
    location.setFont(Fonts::getFont(LOUISE));

    website.setCharacterSize(40);
    contact.setCharacterSize(40);
    location.setCharacterSize(40);

    website.setPosition({party_size.getPosition().x + 120, party_size.getPosition().y + party_size.getHeaderBounds().height + 55});
    contact.setPosition({website.getPosition().x, website.getPosition().y + website.getGlobalBounds().height + 55});
    location.setPosition({contact.getPosition().x, contact.getPosition().y + website.getGlobalBounds().height + 55});

    setupContactSprites();
}

void ReservationPage::setupContactSprites() {
    web.setSprite(WEBSITE);
    web.sf::RectangleShape::setPosition({party_size.getPosition().x, party_size.getPosition().y + party_size.getHeaderBounds().height + 50});
    web.sf::RectangleShape::setScale({.06,.06});

    con.setSprite(CONTACT);
    con.sf::RectangleShape::setPosition({web.sf::RectangleShape::getPosition().x, web.sf::RectangleShape::getPosition().y + web.getGlobalBounds().height + 40});
    con.sf::RectangleShape::setScale({.07,.07});

    loc.setSprite(LOCATION);
    loc.sf::RectangleShape::setPosition({con.sf::RectangleShape::getPosition().x - 15, con.sf::RectangleShape::getPosition().y + con.getGlobalBounds().height + 35});
    loc.sf::RectangleShape::setScale({.14,.14});
}

void ReservationPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(back);

    target.draw(header);
    target.draw(underline);
    target.draw(inside);

    target.draw(submit);

    target.draw(web);
    target.draw(con);
    target.draw(loc);

    target.draw(website);
    target.draw(location);
    target.draw(contact);

    target.draw(party_size);
    target.draw(requests);
    target.draw(date);
    target.draw(time);

    if (getState(CONFIRM)) {
        target.draw(confirmation);
    }
}

void ReservationPage::eventHandler(sf::RenderWindow &window, sf::Event event) {
    date.eventHandler(window, event);
    time.eventHandler(window, event);
    requests.eventHandler(window, event);
    party_size.eventHandler(window, event);
    submit.eventHandler(window, event);

    if (MouseEvents::isClicked(back, window)) {
        enableState(REST_PAGE);
    }

    if (MouseEvents::isClicked(submit, window)) {
        enableState(CONFIRM);
    }
}

void ReservationPage::update() {

}

Snapshot *ReservationPage::getSnapshot() {
    return nullptr;
}

void ReservationPage::applySnapshot(Snapshot *snapshot) {

}
