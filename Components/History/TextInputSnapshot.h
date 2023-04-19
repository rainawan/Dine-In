//
// Created by Raina Wan on 3/28/23.
//

#ifndef TEXTINPUTSOLUTION_TEXTINPUTSNAPSHOT_H
#define TEXTINPUTSOLUTION_TEXTINPUTSNAPSHOT_H

#include "Snapshot.h"
#include <string>
#include <SFML/Graphics.hpp>

class TextInputSnapshot : public Snapshot {
private:
    std::string data;
    sf::Color color;
public:
    const std::string &getData() const;
    void setData(const std::string &data);
};


#endif //TEXTINPUTSOLUTION_TEXTINPUTSNAPSHOT_H
