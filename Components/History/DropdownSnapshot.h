//
// Created by Raina Wan on 3/29/23.
//

#ifndef MENU_DROPDOWNSNAPSHOT_H
#define MENU_DROPDOWNSNAPSHOT_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Snapshot.h"

class DropdownSnapshot : public Snapshot {
private:
    std::string data;
    sf::Color color;
public:
    const std::string &getData() const;
    void setData(const std::string &data);
};


#endif //MENU_DROPDOWNSNAPSHOT_H
