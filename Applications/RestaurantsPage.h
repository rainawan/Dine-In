//
// Created by Raina Wan on 4/19/23.
//

#ifndef DINEIN_RESTAURANTSPAGE_H
#define DINEIN_RESTAURANTSPAGE_H

#include "../SFMLTools/GUIComponent.h"
#include "../SFMLTools/Sprites.h"
#include "RestaurantItem.h"
#include <vector>

class RestaurantsPage : public GUIComponent {
private:
    sf::Text header;
    std::vector<RestaurantItem> items;
public:
    RestaurantsPage();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_RESTAURANTSPAGE_H
