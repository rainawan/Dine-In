//
// Created by Raina Wan on 3/24/23.
//

#include "States.h"

States::States() {
    load();
}

void States::load() {
    for (int i = 0; i < LAST_STATE; ++i) {
        map[static_cast<states_enum>(i)] = false;
    }
}

bool States::getState(states_enum state) const {
    return map.at(state);
}

void States::enableState(states_enum state) {
    setState(state, true);
}

void States::disableState(states_enum state) {
    setState(state, false);
}

void States::setState(states_enum state, bool value) {
    map.at(state) = value;
}

void States::toggleState(states_enum state) {
    setState(state, !map.at(state));
}