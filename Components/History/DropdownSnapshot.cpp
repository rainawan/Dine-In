//
// Created by Raina Wan on 3/29/23.
//

#include "DropdownSnapshot.h"

const std::string &DropdownSnapshot::getData() const {
    return data;
}

void DropdownSnapshot::setData(const std::string &data) {
    DropdownSnapshot::data = data;
}
