//
// Created by Raina Wan on 4/19/23.
//

#ifndef DINEIN_RESTAURANTSPAGE_H
#define DINEIN_RESTAURANTSPAGE_H

#include "../SFMLTools/GUIComponent.h"
#include "../SFMLTools/Sprites.h"
#include "RestaurantItem.h"
#include "ReservationPage.h"
#include "../Components/TextInput/TextInput.h"
#include "../Components/FileTree/FileTree.h"
#include <vector>

class RestaurantsPage : public GUIComponent {
private:
    sf::Text header;
    std::vector<RestaurantItem> items;
    Sprites background;
    TextInput text_input;
    FileTree sort;
    ReservationPage reserve;
    void reposition();
    void init();
    void setupFileTree();
    void setupBackground();
public:
    RestaurantsPage();
    void setPosition(const sf::Vector2f& pos);
    void push(std::string string, sf::Vector2f size, image_enum food, image_enum stars, int dollars);
    void low_to_high();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_RESTAURANTSPAGE_H
