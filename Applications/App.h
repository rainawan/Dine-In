//
// Created by Raina Wan on 4/26/23.
//

#ifndef DINEIN_APP_H
#define DINEIN_APP_H

#include "../SFMLTools/GUIComponent.h"
#include "HomePage.h"

class App : public GUIComponent {
private:
    HomePage home;
    ReservationPage reserve;
    RestaurantsPage restaurant;
public:
    App();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_APP_H
