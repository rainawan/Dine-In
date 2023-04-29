//
// Created by Raina Wan on 4/21/23.
//

#ifndef DINEIN_RESERVATIONPAGE_H
#define DINEIN_RESERVATIONPAGE_H

#include <iostream>
#include "RestaurantItem.h"
#include "../SFMLTools/GUIComponent.h"
#include "../Components/Menu/DropdownMenu.h"

class ReservationPage : public GUIComponent {
private:
    RestaurantItem item;
    Item submit;
    Sprites inside, back, web, loc, con;
    sf::RectangleShape underline;
    sf::Text header, website, location, contact, confirmation;
    Sprites food, background;
    DropdownMenu date, time, party_size, requests;
    void setupHeader(std::string string);
    void setupImage(std::string s);
    void setupBackground();
    void setupSubmit();
    void setupMenu();
    void setupInfo(std::string s);
    void setupContactSprites();
public:
    ReservationPage();
    ReservationPage(RestaurantItem item, image_enum image);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_RESERVATIONPAGE_H
