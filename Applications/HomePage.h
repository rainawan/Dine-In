//
// Created by Raina Wan on 4/18/23.
//

#ifndef DINEIN_HOMEPAGE_H
#define DINEIN_HOMEPAGE_H

#include "../SFMLTools/GUIComponent.h"
#include "../Components/TextInput/TextInput.h"
#include "../SFMLTools/Sprites.h"

class HomePage : public GUIComponent {
private:
    sf::Sprite background;
    sf::Text header;
    Sprites sprite;
    TextInput text_input;
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
