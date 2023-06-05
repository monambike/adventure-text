/**********************************************************************
    File: myfile.cpp
    Author: Your Name
    Description: Brief description of the file's purpose or functionality.

    [Additional details or notes if necessary]

    Copyright (c) [year], [author]
    Distributed under the [license] License (http://opensource.org/licenses/[license])

    [Any other relevant information or acknowledgements]
**********************************************************************/

// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "Item.hpp"
#include "TerminalUtils.hpp"

Item::Item(std::string name, std::string description, Rarity rarity)
    : name(name), description(description), rarity(rarity) {}


std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return description;
}

Rarity Item::getRarity() const {
    return rarity;
}

void Item::displayName() {
    switch (rarity) {
        case COMMON: TerminalUtils::changeTerminalTextColor(WHITE); break;
        case UNCOMMON: TerminalUtils::changeTerminalTextColor(BLUE); break;
        case RARE: TerminalUtils::changeTerminalTextColor(CYAN); break;
        case EPIC: TerminalUtils::changeTerminalTextColor(MAGENTA); break;
        case LEGENDARY: TerminalUtils::changeTerminalTextColor(YELLOW); break;
    }
    std::cout << name;
    TerminalUtils::changeTerminalTextColor(WHITE);
}

void Item::showDetailedInfo() {
    std::cout << "Name: ";
    displayName();
    std::cout << std::endl;
    std::cout << "Rarity: " << rarity << std::endl;
}
