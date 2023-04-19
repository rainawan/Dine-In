//
// Created by Raina Wan on 3/24/23.
//

#ifndef MENU_STATES_H
#define MENU_STATES_H
#include <map>

enum states_enum {
    CLICKED,
    NOT_CLICKED,
    ENABLED,
    BLINK,
    HIDDEN,
    SHOWN,
    NO_CHANGE,
    SHOW_CHILDREN,
    HIGHLIGHT,
    LAST_STATE
};

class States {
private:
    std::map<states_enum, bool> map; // <key, value>
    void load();
public:
    States();
    bool getState(states_enum state) const;
    void enableState(states_enum state); //will make state true inside map
    void disableState(states_enum state); //will set state to false
    void setState(states_enum state, bool value);
    void toggleState(states_enum state); //change b/w true and false
};


#endif //MENU_STATES_H
