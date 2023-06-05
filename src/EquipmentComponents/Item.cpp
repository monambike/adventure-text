// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include "Item.hpp"
#include "../Utilities/TerminalUtils.hpp"

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
