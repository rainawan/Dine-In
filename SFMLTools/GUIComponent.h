//
// Created by Raina Wan on 4/18/23.
//

#ifndef DINEIN_GUICOMPONENT_H
#define DINEIN_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fonts.h"
#include "MouseEvents.h"
#include "Position.h"
#include "States.h"
#include "../Components/History/SnapshotInterface.h"


class GUIComponent : public sf::Drawable, public sf::Transformable, public States, public SnapshotInterface {
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
    virtual Snapshot* getSnapshot() = 0;
    virtual void applySnapshot(Snapshot* snapshot) = 0;
};


#endif //DINEIN_GUICOMPONENT_H
