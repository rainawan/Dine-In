//
// Created by Raina Wan on 3/27/23.
//

#ifndef DINEIN_TYPING_H
#define DINEIN_TYPING_H

#include <SFML/Graphics.hpp>
#include "../../SFMLTools/Fonts.h"
#include "../../SFMLTools/States.h"
#include "../History/TextInputSnapshot.h"
#include "../History/SnapshotInterface.h"
#include "../History/History.h"

class Typing : public GUIComponent {
private:
    sf::Text text;
    std::string s;
public:
    Typing();
    void setPosition(const sf::Vector2f& position);
    void setCharacterSize(int num);
    void setFillColor(sf::Color color);
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();
    float getCharacterSize();
    std::string getText();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot *getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_TYPING_H
