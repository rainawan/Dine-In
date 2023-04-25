//
// Created by Raina Wan on 4/18/23.
//

#ifndef DINEIN_HOMEPAGE_H
#define DINEIN_HOMEPAGE_H

#include "../SFMLTools/GUIComponent.h"
#include "../Components/TextInput/TextInput.h"
#include "../SFMLTools/Sprites.h"
#include "RestaurantsPage.h"

class HomePage : public GUIComponent {
private:
    sf::Text header;
    Sprites background, search_sprite;
    TextInput text_input;
    RestaurantsPage restaurants;
    void setupHeader();
    void setupTextInput();
    void setupSprite();
    void setupRestaurants();
    void repositionTextInput(sf::Vector2f pos);
public:
    HomePage();
    void init();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_HOMEPAGE_H
