//
// Created by Raina Wan on 3/27/23.
//

#ifndef TEXTINPUT_CURSOR_H
#define TEXTINPUT_CURSOR_H
#include "../../SFMLTools/GUIComponent.h"

class Cursor : public GUIComponent {
private:
    sf::Text cursor;
    sf::Clock clock;
public:
    Cursor();
    void setPosition(const sf::Vector2f& position);
    void setCharacterSize(int num);
    void setFillColor(sf::Color color);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //TEXTINPUT_CURSOR_H
