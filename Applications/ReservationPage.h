//
// Created by Raina Wan on 4/21/23.
//

#ifndef DINEIN_RESERVATIONPAGE_H
#define DINEIN_RESERVATIONPAGE_H

#include "RestaurantItem.h"
#include "../SFMLTools/GUIComponent.h"
#include "../Components/Menu/DropdownMenu.h"

class ReservationPage : public GUIComponent {
private:
    RestaurantItem item;
    Item submit;
    Sprites inside;
    sf::RectangleShape underline;
    sf::Text header;
    Sprites food, background;
    DropdownMenu date, time, party_size;
    void setupHeader(std::string string);
    void setupImage(image_enum image);
    void setupBackground();
    void setupSubmit();
    void setupMenu();
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
